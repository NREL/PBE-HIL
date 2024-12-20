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
import LC_filter

# ENERGY STORAGE / BATTERY VALUES / SOURCE

# Custom AUV Battery
AUV_Voltage = 48.0      # V, nominal battery voltage
AUV_SOC = 65.0          # %, initial state of charge
AUV_Ah = 2.0            # Ah

# Charging control strategy
V_cc = 40.0             # Constant Current
I_cc = 12.0
V_cv = 56.0             # Constant Voltage
I_trickle = 2.0         # Trickle-charge

Delta_V = 0.5           # Delta for output voltage

# AUV Charger Source
V_source = 48.0         # V, voltage of the dc bus

f_s = 20000.0           # Converter frequency


# BUCK-BOOST CONVERTER

converter = LC_filter.BuckBoost_Converter_Specifications(V_source, V_cv, V_cc, I_cc, I_trickle,
                                                         f_s, Delta_V)

L_BuckBoost = LC_filter.LC_filter_L_BuckBoost(converter)
C_BuckBoost = LC_filter.LC_filter_C_BuckBoost(converter)

# Determine and assign PI control values

P = 0.0015 
I = 5.0 