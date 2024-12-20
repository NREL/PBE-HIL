#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
File name: SCADA_load_calculations
Author: Hannes Labuschagne
Created: Oct 2024
Version: 0.1
Description: 
Contact: hannes.labuschagne@nrel.gov
"""

import numpy as np
import scipy as sp 

########################################
### LOAD CALCULATIONS AND ASSIGNMENT ###
########################################

class OOB_Power:
    """Equivalent load or power requirement values for the surface and seafloor sensors."""

    def __init__(self, user_sensor_specs):
        """Initialize variable containing load data for surface and seafloor sensors
        
        : R_surface_xV   : (Ohm)   : Lumped surface loads
        : P_surface_xV   : (W)     : Lumped surface loads
        : R_seafloor_xV   : (Ohm)   : Lumped seafloor loads
        : P_seafloor_xV   : (W)     : Lumped seafloor loads
        """

        self.user_sensor_specs = user_sensor_specs

        # Determine equivalent load and resistance values
        load_surface, load_seafloor = self.sum_loads(user_sensor_specs)
        resistance_surface = self.equivalent_loads(load_surface)
        resistance_seafloor = self.equivalent_loads(load_seafloor)

        # Assign/Initialize equivalent resistance values for the HIL model
        self.R_surface_5V = resistance_surface[0]
        self.R_surface_12V = resistance_surface[1]
        self.R_surface_24V = resistance_surface[2]
        self.R_seafloor_5V = resistance_seafloor[0]
        self.R_seafloor_12V = resistance_seafloor[1]
        self.R_seafloor_24V = resistance_seafloor[2]

        # Assign/Initialize equivalent power values ()
        self.P_surface_5V = load_surface[0]
        self.P_surface_12V = load_surface[1]
        self.P_surface_24V = load_surface[2]
        self.P_seafloor_5V = load_seafloor[0]
        self.P_seafloor_12V = load_seafloor[1]
        self.P_seafloor_24V = load_seafloor[2]


    def sum_loads(self, user_sensor_specs):
        """Calculate the lumped load for surface and seafloor sensors 
        according to different input voltage specifications.

        : user_spec : Input is of class 'sensor', according to the load specified by the user. Contains
                      voltage and power data.
        : return    : 'load_x', (W), which is an array containing the equivalent load for the sensors according
                      to the different positions and input voltages (5V, 12V, 24V).
        """

        load_surface = [0]*3 
        load_seafloor = [0]*3        

        for key, value in user_sensor_specs.items():
            if value.Position == 'Surface':
                if value.Voltage == '5V':
                    load_surface[0] += value.Power 
                elif value.Voltage == '12V':
                    load_surface[1] += value.Power
                else:
                    load_surface[2] += value.Power
            else:
                if value.Voltage == '5V':
                    load_seafloor[0] += value.Power
                elif value.Voltage == '12V':
                    load_seafloor[1] += value.Power
                else:
                    load_seafloor[2] += value.Power

        return load_surface, load_seafloor


    def equivalent_loads(self, user_sensor_Pref):
        """Calculate the lumped resistor-value for each load.
        
        : user_spec : Input is an array with the lumped load data.
        : return    : 'R', (Ohm), which is an array containing the equivalent resistance values.
        """

        R = [0]*3       # Create array

        try:
            R[0] = (5.0**2)/user_sensor_Pref[0]
        except ZeroDivisionError:
            print("ZeroDivisionError: Load")
            R[0] = 0
        try:
            R[1] = (12.0**2)/user_sensor_Pref[1]
        except ZeroDivisionError:
            print("ZeroDivisionError: Load")
            R[1] = 0
        try:
            R[2] = (24.0**2)/user_sensor_Pref[2]
        except ZeroDivisionError:
            print("ZeroDivisionError: Load")
            R[2] = 0

        
        return R


########################################
### LOAD CALCULATIONS AND ASSIGNMENT ###
########################################

def Boost_Converter_equivalent_load(V_boost, user_spec_voltage, user_spec_load):
    """To calculate the Boost Converter's LC-filter, an estimate is needed for the equivalent load.
    This function is used to calculate that equivalent load value.
    
    : user_spec : User input is an array containing the equivalent load resistance values for the 
                 seafloor sensors and equipment.
    : return    : 'eq_resistance', (Ohm)
    """
   
    eq_resistance_5V = ((V_boost**2)/(user_spec_voltage[0]**2))*user_spec_load.R_seafloor_5V
    eq_resistance_12V = ((V_boost**2)/(user_spec_voltage[1]**2))*user_spec_load.R_seafloor_12V
    eq_resistance_24V = ((V_boost**2)/(user_spec_voltage[2]**2))*user_spec_load.R_seafloor_24V

    eq_resistance = 1/eq_resistance_5V + 1/eq_resistance_12V + 1/eq_resistance_24V
    
    return eq_resistance

def Boost_Converter_equivalent_load_config1(V_boost, user_spec_voltage, user_spec_load):
    """To calculate the Boost Converter's LC-filter, an estimate is needed for the equivalent load.
    This function is used to calculate that equivalent load value.
    
    : user_spec : User input is an array containing the equivalent load resistance values for the 
                 seafloor sensors and equipment.
    : return    : 'eq_resistance', (Ohm)
    """
   
    eq_resistance_5V = ((user_spec_voltage[2]**2)/(user_spec_voltage[0]**2))*user_spec_load.R_seafloor_5V
    eq_resistance_12V = ((user_spec_voltage[2]**2)/(user_spec_voltage[1]**2))*user_spec_load.R_seafloor_12V

    eq_resistance_24V = 1/eq_resistance_5V + 1/eq_resistance_12V + 1/user_spec_load.R_seafloor_24V

    eq_resistance = ((V_boost**2)/(user_spec_voltage[2]**2))*eq_resistance_24V
    
    return eq_resistance


###############################################
### MANUAL LOAD CALCULATIONS AND ASSIGNMENT ###
###############################################

def sum_loads(user_sensor_specs):
    """Calculate the lumped load for surface and seafloor sensors 
    according to different input voltage specifications.
    
    : user_spec : Input is of class 'sensor', according to the load specified by the user. Contains
                  voltage and power data.
    : return    : 'load_x', (W), which is an array containing the equivalent load for the sensors according
                  to the different positions and input voltages (5V, 12V, 24V).
    """

    load = [0]*4       

    for key, value in user_sensor_specs.items():
        if value.Position == 'Surface':
            if value.Voltage == '12V':
                load[0] += value.Power 
            else:
                load[1] += value.Power
        else:
            if value.Voltage == '12V':
                load[2] += value.Power
            else:
                load[3] += value.Power

    return load

def equivalent_loads(user_sensor_Pref):
    """Calculate the lumped resistor-value for each load.
    
    : user_spec : Input is an array with the lumped load data.
    : return    : 'R', (Ohm), which is an array containing the equivalent resistance values.
    """

    R = [0]*4       # Create array

    for i in range (len(R)):
        if i % 2 == 0:
            try:
                R[i] = (12.0**2)/user_sensor_Pref[i]
            except ZeroDivisionError:
                print("ZeroDivisionError: Load")
        else:
            try:
                R[i] = (24.0**2)/user_sensor_Pref[i]
            except ZeroDivisionError:
                print("ZeroDivisionError: Load")
    
    return R
