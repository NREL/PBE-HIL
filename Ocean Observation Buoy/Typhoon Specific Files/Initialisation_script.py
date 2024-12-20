#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
File name: Initialisation_script
Author: Hannes Labuschagne
Created: Oct 2024
Version: 0.1
Description: 
Contact: hannes.labuschagne@nrel.gov

Instructions for Typhoon HIL user:
Copy script from line 16 into Typhoon Schematic Editor Python API
"""

# Numpy module is imported as 'np'
# Scipy module is imported as 'sp'
# The Schematic API is imported as 'mdl'
# To get the model file path, use 'mdl.get_model_file_path()'
# To print information to the console, use info()

# Import statements
import sensor_data
import LC_filter
import SCADA_load_calculations as load

# ENERGY STORAGE / BATTERY VALUES / SOURCE

# Custom Voltage Source
V_source = 48.0                 # Source or battery voltage
Ah_bat_source = 20.0            # Ah value for battery source

# Battery min and max voltages; values necessary for Boost Converter
V_bat_min = 36.0                # Lowest battery voltage during operation
V_bat_max = 54.0                # Highers battery voltage during operation

f_s = 20000.0                   # Converter frequency; seperated converter frequencies can be assigned if necessary

# Define RL values for the subsea cable: Trans_Cable(R (Ohm), L (mH))
cable_resistance = 0.020
cable_inductance = 0.001
RL_surf2sea_cable = sensor_data.Trans_Cable(cable_resistance, cable_inductance)

V_SurfaceLoad = (5.0, 12.0, 24.0)            # Voltage level for the OOB's sensor load part of the seasurface circuitry
V_SeafloorLoad = (5.0, 12.0, 24.0)           # Voltage level for the OOB's sensor load part of the seafloor circuitry
V_out_Boost = 120.0                          # Voltage level that needs to be stepped up by Boost converter to reduce transmission losses

# SPECIFY SENSORS & SENSOR DATA
sensor_load = {}
sensor_load['CPU'] = sensor_data.Custom_User_Sensor(1, 1, 'Surface', '5V', 0)
sensor_load['GPS'] = sensor_data.Custom_User_Sensor(0.7, 1, 'Surface', '5V', 0)
sensor_load['dataLogger_communications_surface'] = sensor_data.Custom_User_Sensor(6.0, 3, 'Surface', '5V', 0)
sensor_load['pyranometer'] = sensor_data.Custom_User_Sensor(0.1, 1, 'Surface', '5V', 0)
sensor_load['ADCP'] = sensor_data.Custom_User_Sensor(20, 3, 'Surface', '12V', 0)
sensor_load['catalytic'] = sensor_data.Custom_User_Sensor(6.0, 1, 'Surface', '12V', 0)
sensor_load['ctd_surface'] = sensor_data.Custom_User_Sensor(36, 1, 'Surface', '12V', 0)
sensor_load['echosounder'] = sensor_data.Custom_User_Sensor(6.0, 1, 'Surface', '12V', 0)
sensor_load['electrode_ph'] = sensor_data.Custom_User_Sensor(1.0, 1, 'Surface', '12V', 0)
sensor_load['flourometer'] = sensor_data.Custom_User_Sensor(3.0, 1, 'Surface', '12V', 0)
sensor_load['isfet'] = sensor_data.Custom_User_Sensor(0.4, 2, 'Surface', '12V', 0)
sensor_load['meteorological_probe'] = sensor_data.Custom_User_Sensor(0.18, 2, 'Surface', '12V', 0)
sensor_load['motion_sensor'] = sensor_data.Custom_User_Sensor(4.5, 1, 'Surface', '12V', 0)
sensor_load['wave_sensor'] = sensor_data.Custom_User_Sensor(69.0, 1, 'Surface', '12V', 0)
sensor_load['optical_sensor'] = sensor_data.Custom_User_Sensor(4.44, 3, 'Surface', '12V', 0)
sensor_load['pco2'] = sensor_data.Custom_User_Sensor(4.0, 2, 'Surface', '12V', 0)
sensor_load['anemometer'] = sensor_data.Custom_User_Sensor(72.48, 3, 'Surface', '24V', 0)

sensor_load['dataLogger_communications_floor'] = sensor_data.Custom_User_Sensor(6.0, 3, 'Floor', '5V', 0)
sensor_load['camera'] = sensor_data.Custom_User_Sensor(10.8, 1, 'Floor', '12V', 0)
sensor_load['ctd_floor'] = sensor_data.Custom_User_Sensor(36, 1, 'Floor', '12V', 0)
sensor_load['LED'] = sensor_data.Custom_User_Sensor(150, 1, 'Floor', '24V', 0)


# DETERMINE EQUIVALENT LOADS FOR SEA SURFACE AND SEAFLOOR SENSORS
Pref_user = load.sum_loads(sensor_load)
R_sensors = load.equivalent_loads(Pref_user)

equivalent_load_data = load.OOB_Power(sensor_load)

# SEA-SURFACE BUCK CONVERTER DESIGN
# Specify Buck converter and determine LC-filter values

Buck_SeaSurface = {}
# Set values for Buck Converter Surface Loads
Buck_SeaSurface['Surface_5V'] = LC_filter.Buck_Converter_Specifications(V_source, V_SurfaceLoad[0], 5, 1/f_s, 0.05)
Buck_SeaSurface['Surface_12V'] = LC_filter.Buck_Converter_Specifications(V_source, V_SurfaceLoad[1], 5, 1/f_s, 0.05)
Buck_SeaSurface['Surface_24V'] = LC_filter.Buck_Converter_Specifications(V_source, V_SurfaceLoad[2], 5, 1/f_s, 0.05)

# Determine LC filter components
L_Buck_SeaSurface = LC_filter.LC_filter_L_Buck(Buck_SeaSurface)
C_Buck_SeaSurface = LC_filter.LC_filter_C_Buck(Buck_SeaSurface, L_Buck_SeaSurface)

# Determine PI control values
P_surface_5V = L_Buck_SeaSurface[0]/equivalent_load_data.R_surface_5V
P_surface_12V = L_Buck_SeaSurface[1]/equivalent_load_data.R_surface_12V
P_surface_24V = L_Buck_SeaSurface[2]/equivalent_load_data.R_surface_24V
I_surface_5V = 50.0
I_surface_12V = 50.0
I_surface_24V = 50.0


# SEA-SURFACE BOOST CONVERTER DESIGN
# Specify Boost converter and determine LC-filter values

Boost_SeaSurface = {}
Delta_V = 0.2
Eq_Boost_Resistance = RL_surf2sea_cable.R + load.Boost_Converter_equivalent_load_config1(V_out_Boost, V_SeafloorLoad, equivalent_load_data) 


Conduction = "Discontinuous"
# Set values for Buck Converter Surface Loads
Boost_SeaSurface['Surface'] = LC_filter.Boost_Converter_Specifications(V_out_Boost, V_bat_min, V_bat_max, Delta_V, 1/f_s, Eq_Boost_Resistance, Conduction)

# Determine LC filter components
L_Boost_SeaSurface = LC_filter.LC_filter_L_Boost(Boost_SeaSurface)
C_Boost_SeaSurface = LC_filter.LC_filter_C_Boost(Boost_SeaSurface)

P_Boost = 160.0*L_Boost_SeaSurface[0]/Eq_Boost_Resistance
I_Boost = 50.0/10.0


# SEAFLOOR BUCK CONVERTER DESIGN
# Specify Buck converter and determine LC-filter values

Buck_SeaFloor = {}
# Set values for Buck Converter Surface Loads
Buck_SeaFloor['SeaFloor_5V'] = LC_filter.Buck_Converter_Specifications(V_out_Boost, V_SeafloorLoad[0], 5, 1/f_s, 0.05)
Buck_SeaFloor['SeaFloor_12V'] = LC_filter.Buck_Converter_Specifications(V_out_Boost, V_SeafloorLoad[1], 5, 1/f_s, 0.05)
Buck_SeaFloor['SeaFloor_24V'] = LC_filter.Buck_Converter_Specifications(V_out_Boost, V_SeafloorLoad[2], 5, 1/f_s, 0.05)

# Determine LC filter components
L_Buck_SeaFloor = LC_filter.LC_filter_L_Buck(Buck_SeaFloor)
C_Buck_SeaFloor = LC_filter.LC_filter_C_Buck(Buck_SeaFloor, L_Buck_SeaFloor)

# Determine PI control values
P_seafloor_5V = L_Buck_SeaFloor[0]/equivalent_load_data.R_seafloor_5V
P_seafloor_12V = L_Buck_SeaFloor[1]/equivalent_load_data.R_seafloor_12V
P_seafloor_24V = L_Buck_SeaFloor[2]/equivalent_load_data.R_seafloor_24V
I_seafloor_5V = 50.0
I_seafloor_12V = 50.0
I_seafloor_24V = 50.0
