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

class BuckBoost_Converter_Specifications:
    """Input values for the Buck-Boost Converter 
    and LC-filter values"""

    def __init__(self, V_in, V_cv, V_cc, I_cc, I_trickle, f_s, Delta_V ):
        """Initialize Buck-Boost Converter values
        
        : V_in        : (V)    : The voltage of the source that is charging the AUV
        : V_cv        : (V)    : The maximum battery voltage, specified for constant voltage control
        : V_cc        : (V)    : The battery voltage when changing to constant current control
        : I_cc        : (A)    : The battery charging current during constant current control
        : I_trickle   : (A)    : The battery charging current during trickle-charge control
        : f_s         : (Hz)   : The switching frequency of the Buck-Boost Converter
        : Delta_V     : (V)    : User specified delta for the output voltage
        """

        self.V_in = V_in
        self.V_cv = V_cv
        self.V_cc = V_cc
        self.I_cc = I_cc
        self.I_trickle = I_trickle
        self.T_s = 1/f_s
        self.Delta_V = Delta_V


class LC_filter:
    """Calculated LC filter values or user specified LC filter values."""
    
    
    def __init__(self, L, C):
        """Initialize Buck/Boost Converter LC-filter values
        
        : L     : (H)   : The caclulated inductance value or the value specified by the user.
        : C     : (F)   : The calculated capacitor value or the value specified by the user.
        """

        self.L = L
        self.C = C


###################################################
### BUCK-BOOST CONVERTER LC-FILTER CALCULATIONS ### 
###################################################
        
def LC_filter_L_BuckBoost (user_specs):
    """Determine the minimum L for continuous conduction using a Buck-Boost Converter.
    
    : user_spec : Input is of class "BuckBoost_Converter_Specifications" and contains user specifications.
    : return    : L, (H) 
    """

    # Determine duty cycle
    # For L, we consider I_out and D at trickle-charge
    D = 1/(1+(user_specs.V_in/user_specs.V_cc))
    
    # Calculate the inductance, L, for the Buck-Boost Converter's LC filter    
    L = (user_specs.V_cc*user_specs.T_s*((1-D)**2))/(2*user_specs.I_trickle)
        
    return L

def LC_filter_C_BuckBoost (user_specs):
    """Determine minimum C for continuous conduction
    
    : user_spec : Input is of class "BuckBoost_Converter_Specifications" and contains user specifications.
    : return    : C, (F)
    """

    # Determine duty cycle
    # For L, we consider I_out and D at the beginning of constant voltage control
    D = 1/(1+(user_specs.V_in/user_specs.V_cv)) 
        
    # Initialize counter
    C = (user_specs.I_cc*D*user_specs.T_s)/user_specs.Delta_V       

    return C