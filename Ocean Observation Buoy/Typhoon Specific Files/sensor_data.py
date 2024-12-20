#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
File name: sensor_data
Author: Hannes Labuschagne
Created: Oct 2024
Version: 0.1
Description: 
Contact: hannes.labuschagne@nrel.gov
"""

import numpy as np
import scipy as sp 

# TRANSMISSION CABLE VALUES
class Trans_Cable:
    """RL model of transmission cable"""
    
    def __init__(self, R, L):
        """Initialize resistance inductor values
        
        : R     : (Ohm) : Transmission cable's resistance
        : L     : (H)   : Transmission cable's inductance
        """
        self.R = R
        self.L = L
        
# CUSTOM SENSOR VALUES
class Custom_User_Sensor:
    """Custom sensor/component with user specified data."""

    def __init__(self, Power, Number, Position, Voltage, Type):
        """Initialize sensor/component data.
        
        : Power     : (W)   : Power usage of sensor or component
        : Number    : (-)   : Number of sensors used in the model
        : Position  : (-)   : Position of the sensor in the OOB, i.e., 'Surface' or 'Floor'
        : Voltage   : (V)   : Input voltage to power sensor or component
        : Type      : (-)   : Type of sensor; '0' is always custom specified, '1,2,...' preprogrammed
        """

        self.Power = Power*Number
        self.Number = Number
        self.Position = Position
        self.Voltage = Voltage
        self.Type = Type
        

# ADCP SENSOR VALUES
class Acoustic_Doppler_Current_Profiler:
    """ADCP load model"""
    
    def __init__(self, Power, Number, Position, Voltage, Type):
        """Initialize ADCP data."""
        self.Power = Power
        self.Number = Number
        self.Position = Position
        self.Voltage = Voltage
        self.Type = Type
    
    def set_values(self):
        if self.Type == 1:
            # Nortek - Aquadopp 300m
            self.Power = 20*self.Number
        elif self.Type == 2:
            # Nortek - VECTOR 4000m
            self.Power = 1.5*self.Number
        else:
            # Custom
            self.Power = self.Power*self.Number

# ANEMOMETER SENSOR VALUES
class Anemometer:
    """Anemometer load model"""
    
    def __init__(self, Power, Number, Position, Voltage, Type):
        """Initialize Anemometer data."""
        self.Power = Power
        self.Number = Number
        self.Position = Position
        self.Voltage = Voltage
        self.Type = Type
    
    def set_values(self):
        if self.Type == 1:
            # Gill Windobserver II
            self.Power = 0.48*self.Number
        else:
            # Custom
            self.Power = self.Power*self.Number

# CAMERA VALUES
class Camera:
    """Camera load model"""
    
    def __init__(self, Power, Number, Position, Voltage, Type):
        """Initialize camera values"""
        self.Power = Power
        self.Number = Number
        self.Position = Position
        self.Voltage = Voltage
        self.Type = Type
    
    def set_values(self):
        if self.Type == 1:
            # OE14-408
            self.Power = 10.8*self.Number
        else:
            # Custom
            self.Power = self.Power*self.Number

# CATALYTIC SENSOR VALUES
class Catalytic:
    """Catalytic sensor load model"""
    
    def __init__(self, Power, Number, Position, Voltage, Type):
        """Initialize catalytic sensor load values"""
        self.Power = Power
        self.Number = Number
        self.Position = Position
        self.Voltage = Voltage
        self.Type = Type
    
    def set_values(self):
        if self.Type == 1:
            # H2 Specific Sensor/Transmitter
            self.Power = 6*self.Number
        else:
            # Custom
            self.Power = self.Power*self.Number

# CTD VALUES
class CTD:
    """CTD sensor load model"""
    
    def __init__(self, Power, Number, Position, Voltage, Type):
        """Initialize catalytic sensor load values"""
        self.Power = Power
        self.Number = Number
        self.Position = Position
        self.Voltage = Voltage
        self.Type = Type
    
    def set_values(self):
        if self.Type == 1:
            # SBE 26plus
            self.Power = 0.2*self.Number
        elif self.Type == 2:
            # SBE 37IM
            self.Power = 0.29*self.Number
        elif self.Type == 3:
            # SBE-37
            self.Power = 12*self.Number
        elif self.Type == 4:
            # SBE 16plusV2
            self.Power = 36*self.Number
        elif self.Type == 5:
            # 16plus-IM V2
            self.Power = 36*self.Number
        else:
            # Custom
            self.Power = self.Power*self.Number

# ECHOSOUNDER
class Echosounder:
    """Echosounder load model"""
    
    def __init__(self, Power, Number, Position, Voltage, Type):
        """Echosounder load values"""
        self.Power = Power
        self.Number = Number
        self.Position = Position
        self.Voltage = Voltage
        self.Type = Type
    
    def set_values(self):
        if self.Type == 1:
            # X2-CB
            self.Power = 6*self.Number
        elif self.Type == 2:
            # X2-CB
            self.Power = 6*self.Number
        else:
            # Custom
            self.Power = self.Power*self.Number

# ELECTRODE PH SENSOR
class Electrode_PH:
    """Electrode_PH load model"""
    
    def __init__(self, Power, Number, Position, Voltage, Type):
        """Electrode_PH load values"""
        self.Power = Power
        self.Number = Number
        self.Position = Position
        self.Voltage = Voltage
        self.Type = Type
    
    def set_values(self):
        if self.Type == 1:
            # SAMI-pH
            self.Power = 6*self.Number
        else:
            # Custom
            self.Power = self.Power*self.Number


# FLUOROMETER
class Flourometer:
    """Flourometer load model"""
    
    def __init__(self, Power, Number, Position, Voltage, Type):
        """Flourometer load values"""
        self.Power = Power
        self.Number = Number
        self.Position = Position
        self.Voltage = Voltage
        self.Type = Type
    
    def set_values(self):
        if self.Type == 1:
            # ECO Triplet-w
            self.Power = 0.9*self.Number
        elif self.Type == 2:
            # ECO FLBB-SB
            self.Power = 0.9*self.Number
        else:
            # Custom
            self.Power = self.Power*self.Number

# ION-SENSITIVE FIELD EFFECT TRANSISTOR
class ISFET:
    """I-Sfet load model"""
    
    def __init__(self, Power, Number, Position, Voltage, Type):
        """I-Sfet load values"""
        self.Power = Power
        self.Number = Number
        self.Position = Position
        self.Voltage = Voltage
        self.Type = Type
    
    def set_values(self):
        if self.Type == 1:
            # Rotronic MP-101A
            self.Power = 0.4*self.Number
        else:
            # Custom
            self.Power = self.Power*self.Number

# METEOROLOGICAL PROBE
class Meteorological_Probe:
    """Meteorological probe load model"""
    
    def __init__(self, Power, Number, Position, Voltage, Type):
        """Meteorological probe load values"""
        self.Power = Power
        self.Number = Number
        self.Position = Position
        self.Voltage = Voltage
        self.Type = Type
    
    def set_values(self):
        if self.Type == 1:
            # Rotronic MP-101A
            self.Power = 0.18*self.Number
        elif self.Type == 2:
            # Heise DXD RM Young 50202
            self.Power = 0.18*self.Number
        elif self.Type == 3:
            # RM Young 50202
            self.Power = 0.024*self.Number
        else:
            # Custom
            self.Power = self.Power*self.Number

# MOTION SENSOR
class Motion_Sensor:
    """Motion sensor load model"""
    
    def __init__(self, Power, Number, Position, Voltage, Type):
        """Motion sensor load values"""
        self.Power = Power
        self.Number = Number
        self.Position = Position
        self.Voltage = Voltage
        self.Type = Type
    
    def set_values(self):
        if self.Type == 1:
            # 3DM-GX5-AHRS
            self.Power = 4.5*self.Number
        else:
            # Custom
            self.Power = self.Power*self.Number

# WAVE SENSOR
class Wave_Sensor:
    """Wave sensor load model"""
    
    def __init__(self, Power, Number, Position, Voltage, Type):
        """Wave sensor load values"""
        self.Power = Power
        self.Number = Number
        self.Position = Position
        self.Voltage = Voltage
        self.Type = Type
    
    def set_values(self):
        if self.Type == 1:
            # AXYS Watchman500
            self.Power = 69.0*self.Number
        else:
            # Custom
            self.Power = self.Power*self.Number

# OPTICAL SENSOR
class Optical_Sensor:
    """Optical sensor load model"""
    
    def __init__(self, Power, Number, Position, Voltage, Type):
        """Optical sensor load values"""
        self.Power = Power
        self.Number = Number
        self.Position = Position
        self.Voltage = Voltage
        self.Type = Type
    
    def set_values(self):
        if self.Type == 1:
            # OCR507 ICSW
            self.Power = 0.55*self.Number
        elif self.Type == 1:
            # AC-S
            self.Power = 4.44*self.Number
        else:
            # Custom
            self.Power = self.Power*self.Number

# OPTODE SENSOR
class Optode:
    """Optode load model"""
    
    def __init__(self, Power, Number, Position, Voltage, Type):
        """Optode load values"""
        self.Power = Power
        self.Number = Number
        self.Position = Position
        self.Voltage = Voltage
        self.Type = Type
    
    def set_values(self):
        if self.Type == 1:
            # Optode 4831
            self.Power = 1.4*self.Number
        else:
            # Custom
            self.Power = self.Power*self.Number

# PCO2 SENSOR
class pCO2:
    """pCO2 sensor load model"""
    
    def __init__(self, Power, Number, Position, Voltage, Type):
        """pCO2 sensor load values"""
        self.Power = Power
        self.Number = Number
        self.Position = Position
        self.Voltage = Voltage
        self.Type = Type
    
    def set_values(self):
        if self.Type == 1:
            # Optode 4831
            self.Power = 1.4*self.Number
        else:
            # Custom
            self.Power = self.Power*self.Number

# PYRANOMETER SENSOR
class Pyranometer:
    """Pyranometer load model"""
    
    def __init__(self, Power, Number, Position, Voltage, Type):
        """Pyranometer load values"""
        self.Power = Power
        self.Number = Number
        self.Position = Position
        self.Voltage = Voltage
        self.Type = Type
    
    def set_values(self):
        if self.Type == 1:
            # KippZonen CMP 21
            self.Power = 0.1*self.Number
        elif self.Type == 1:
            # KippZonen CMP 21
            self.Power = 0.1*self.Number
        elif self.Type == 1:
            # Eppley PIR
            self.Power = 0.1*self.Number
        else:
            # Custom
            self.Power = self.Power*self.Number


# DATA LOGGER & COMMUNICATIONS
class DataLogger_Communications:
    """Data logger & comm. load model"""
    
    def __init__(self, Power, Number, Position, Voltage, Type):
        """Data logger & comm. load values"""
        self.Power = Power
        self.Number = Number
        self.Position = Position
        self.Voltage = Voltage
        self.Type = Type
    
    def set_values(self):
        if self.Type == 1:
            # X2-CB
            self.Power = 6*self.Number
        else:
            # Custom
            self.Power = self.Power*self.Number