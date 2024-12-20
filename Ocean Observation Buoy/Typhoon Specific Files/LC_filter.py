#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
File name: LC_filter
Author: Hannes Labuschagne
Created: Oct 2024
Version: 0.1
Description: 
Contact: hannes.labuschagne@nrel.gov
"""

import numpy as np
import scipy as sp 

#######################################################
### CONVERTER AND PASSIVE COMPONENET INITIALIZATION ###
#######################################################

class Buck_Converter_Specifications:
    """Input values for the OOB's load and power specs used to determine 
    buck converter and LC-filter values"""

    def __init__(self, V_source, V_load, I_out, Ts, Delta_Vc):
        """Initialize Buck Converter- and Battery/Load values

        : V_source  : (V)   : The voltage of the DC-source, supplying power, that must be stepped down.
        : V_load    : (V)   : The load (target) voltage on the load side of the Bick Converter
        : I_trickle : (A)   : The trickle charge current of the battery.
        : Ts        : (Hz)  : The switching frequency of the Buck Converter
        : Delta_Vc  : (%)   : The maximum allowed percentage voltage ripple on the output of the Buck Converter.
        """

        self.V_source = V_source
        self.V_load = V_load
        self.I_out = I_out
        self.Ts = Ts
        self.Delta_Vc = Delta_Vc

class Boost_Converter_Specifications:
    """User input values for the Boost Converter, used te step up the voltage
    for minimal transmission losses to the seafloor sensor loads, and is then
    used to determine the LC filter values accordingly."""

    def __init__(self, V_out, V_source_min, V_source_max, Delta_V, Ts, resistance, conduction):
        """Initialize Boost Converter values
        
        : V_out         : (V)   : The output voltage required from the Boost Converter.
        : V_source_min  : (V)   : The voltage of the DC-source, supplying power, that must be stepped up.
        : V_source_max  : (V)   : The voltage of the DC-source, supplying power, that must be stepped up.  
        : Delta_V       : (V)   : The expected variation in output voltage that may be commanded.
                                (Note that for this application this Delta is small, since we only specify a single output voltage level)
        : Ts            : (Hz)  : The switching frequency of the Boost Converter
        : resistance    : (Ohm) : The equivalent resistance of the load.
        : conduction    : (-)   : It may be desired to specify whether "Continuous" or "Discontinuous".
        """

        self.V_out = V_out
        self.V_source_min = V_source_min
        self.V_source_max = V_source_max
        self.Delta_V = Delta_V
        self.Ts = Ts
        self.resistance = resistance
        self.conduction = conduction


class LC_filter:
    """Calculated LC filter values or user specified LC filter values."""
    
    
    def __init__(self, L, C):
        """Initialize Buck/Boost Converter LC-filter values
        
        : L     : (H)   : The caclulated inductance value or the value specified by the user.
        : C     : (F)   : The calculated capacitor value or the value specified by the user.
        """

        self.L = L
        self.C = C

#############################################
### BUCK CONVERTER LC-FILTER CALCULATIONS ### 
#############################################

def LC_filter_L_Buck (user_specs):
    """Determine the minimum L for continuous conduction using a Buck Converter.
    
    : user_spec : Input is of class "Buck_Converter_Specifications" and contains user specifications.
    : return    : L, (H) 
    """

    # Initialize array
    L = [0]*3   
    # Initialize counter
    i = 0   

    # Calculate the inductance, L, for the Buck Converter's LC filter    
    for key, value in user_specs.items():
        L[i] = (value.V_load*(1-(value.V_load/value.V_source)*value.Ts)/(2*value.I_out))
        i += 1
        
    return L
    
def LC_filter_C_Buck (user_specs, L):
    """Determine minimum C for continuous conduction
    
    : user_spec : Input is of class "Buck_Converter_Specifications" and contains user specifications.
    : return    : C, (F)
    """

    # Initialize array
    C = [0]*3   
    # Initialize counter
    i = 0       

    # Calculate the capacitor, C, for the Buck Converter's LC filter 
    for key, value in user_specs.items():
        C[i] = (value.V_load*(1-value.V_load/value.V_source)*value.Ts**2)/(8*L[i]*value.Delta_Vc)
        i += 1

    return C

##############################################
### BOOST CONVERTER LC-FILTER CALCULATIONS ###
############################################## 

def Boundary_Continuous_Discontinuous (user_specs):
    """Function used to determine whether the lower or upper voltage 
    specificattion for the boost converter should be used when determining L
    (Default return value is for discontinuous conduction mode.)
    
    : user_specs : Input is of class "Boost_Converter_Specifications" and contains user specifications.
    : return     : Returns "V", the voltage value that is used for the LC filter's calculations.
    """

    # Calculate the lower- and higher voltage duty cylcle
    D1 = 1 - user_specs.V_source_min/user_specs.V_out       
    D2 = 1 - user_specs.V_source_max/user_specs.V_out       
    # Initialize return variable
    V = 0        

    print("(D1*(1-D1)**2) = ", (D1*(1-D1)**2))
    print("(D2*(1-D2)**2) = ", (D2*(1-D2)**2))

    # "if"-function that determines and assigns the return variable's value
    if isinstance(user_specs.conduction, str):
        if (user_specs.conduction == "Continuous"):
            if ((D1*(1-D1)**2) > (D2*(1-D2)**2)):
                V = user_specs.V_source_min
            else:
                V = user_specs.V_source_max
        else:
            if ((D1*(1-D1)**2) > (D2*(1-D2)**2)):
                V = user_specs.V_source_max
            else:
                V = user_specs.V_source_min
    # Default Discontinuous Conduction mode
    else:
        if ((D1*(1-D1)**2) > (D2*(1-D2)**2)):
            V = user_specs.V_source_max
        else:
            V = user_specs.V_source_min

    return V

def LC_filter_L_Boost (user_specs):
    """Function determines L for the Boost Converter's LC filter, where the user can  
    specify either continuous/discontinuous conduction mode. The default for this 
    functions is discontinuous conduction mode.
    
    : user_specs : Input is of class "Boost_Converter_Specifications" and contains user specifications.
    : return     : L, (H)
    """

    # Initialize array
    L = [0]*3   
    # Initialize counter
    i = 0   

    # Calculate the inductance, L, for the Buck Converter's LC filter    
    for key, value in user_specs.items():
        # Assign voltage specification and duty cycle for the Boost Converter
        V = Boundary_Continuous_Discontinuous (value)
        D = 1 - V/value.V_out

        L[i] = (((value.resistance*value.Ts)/2)*D*(1-D)**2)
        i += 1

    # Return inductance, L
    return L


def LC_filter_C_Boost (user_specs):
    """Function determines C for the Boost Converter's LC filter, where the user
    specifies the allowed ripple for the output voltage.

    : user_specs : Input is of class "Boost_Converter_Specifications" and contains user specifications.
    : return     : C, (F)
    """

    # Initialize array
    C = [0]*3   
    # Initialize counter
    i = 0       

    # Calculate the capacitor, C, for the Buck Converter's LC filter 
    for key, value in user_specs.items():
        # Assign voltage specification and duty cycle for the Boost Converter
        V = Boundary_Continuous_Discontinuous (value)
        D = 1 - V/value.V_out

        C[i] = ((D*value.Ts*value.V_out)/(value.resistance*value.Delta_V))
        i += 1

    # Return capacitance, C
    return C
