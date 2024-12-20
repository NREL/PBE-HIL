// generated using template: cop_main.template---------------------------------------------
/******************************************************************************************
**
**  Module Name: cop_main.c
**  NOTE: Automatically generated file. DO NOT MODIFY!
**  Description:
**            Main file
**
******************************************************************************************/
// generated using template: arm/custom_include.template-----------------------------------


#ifdef __cplusplus
#include <limits>

extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <complex.h>

// x86 libraries:
#include "../include/sp_functions_dev0.h"


#ifdef __cplusplus
}
#endif


// ----------------------------------------------------------------------------------------                // generated using template:generic_macros.template-----------------------------------------
/*********************** Macros (Inline Functions) Definitions ***************************/

// ----------------------------------------------------------------------------------------

#ifndef MAX
#define MAX(value, limit) (((value) > (limit)) ? (value) : (limit))
#endif
#ifndef MIN
#define MIN(value, limit) (((value) < (limit)) ? (value) : (limit))
#endif

// generated using template: VirtualHIL/custom_defines.template----------------------------

typedef unsigned char X_UnInt8;
typedef char X_Int8;
typedef signed short X_Int16;
typedef unsigned short X_UnInt16;
typedef int X_Int32;
typedef unsigned int X_UnInt32;
typedef unsigned int uint;
typedef double real;

// ----------------------------------------------------------------------------------------
// generated using template: custom_consts.template----------------------------------------

// arithmetic constants
#define C_SQRT_2                    1.4142135623730950488016887242097f
#define C_SQRT_3                    1.7320508075688772935274463415059f
#define C_PI                        3.1415926535897932384626433832795f
#define C_E                         2.7182818284590452353602874713527f
#define C_2PI                       6.283185307179586476925286766559f

//@cmp.def.start
//component defines



















































//@cmp.def.end


//-----------------------------------------------------------------------------------------
// generated using template: common_variables.template-------------------------------------
// true global variables



// const variables
const double _1d_look_up_table1__lut_table[3] = { 1.0, 2.0, 3.0 };
const double _1d_look_up_table1__lut_addrs[3] = { 1.0, 2.0, 3.0 };

//@cmp.var.start
// variables
double _auv_battery_soc__out;
double _constant2__out = 0.5;
double _constant3__out = 3.0;
double _constant4__out = 2.0;
double _constant5__out = 95.0;
double _constant6__out = 95.0;
double _constant7__out = 1.0;
double _contactor_auv_load__out;
double _contactor_discharge__out;
double _enable__out;
double _i_charge_ia1__out;
double _i_out___reference__out;
double _i_trickle___reference__out;
double _v_c_va1__out;
double _v_charge_va1__out;
double _v_out___reference__out;
double _v_out___tc__out;
double _vs_meas_va1__out;
double _auv_battery_gainsoc__out;
double _logical_operator1__out;
double _sum6__out;
double _sum7__out;
double _sum3__out;
double _relational_operator1__out;
double _relational_operator2__out;
double _relational_operator3__out;
double _relational_operator4__out;
double _integrator1__out;
double _product1__out;
double _logical_operator2__out;
double _product3__out;
double _product2__out;
double _sum8__out;
double _1d_look_up_table1__value;
X_Int32 _1d_look_up_table1__leftIndex;
X_Int32 _1d_look_up_table1__rightIndex;
X_Int32 _1d_look_up_table1__curAddr;
double _1d_look_up_table1__fraction;

double _multiport_signal_switch1__out;
double _gain1__out;
double _gain2__out;
double _sum4__out;
double _limit1__out;
double _gain3__out;
double _sum5__out;
X_UnInt32 _buck___boost_charge_pwm_modulator__channels[1] = {0};
double _buck___boost_charge_pwm_modulator__limited_in[1];
X_UnInt32 _buck___boost_charge_pwm_modulator__update_mask;

//@cmp.var.end

//@cmp.svar.start
// state variables
double _integrator1__state;
double _integrator1__reset_state;
//@cmp.svar.end

//
// Tunable parameters
//
static struct Tunable_params {
} __attribute__((__packed__)) tunable_params;

void *tunable_params_dev0_cpu0_ptr = &tunable_params;

// Dll function pointers
#if defined(_WIN64)
#else
// Define handles for loading dlls
#endif








// generated using template: virtual_hil/custom_functions.template---------------------------------
void ReInit_user_sp_cpu0_dev0() {
#if DEBUG_MODE
    printf("\n\rReInitTimer");
#endif
    //@cmp.init.block.start
    XIo_OutFloat(0x55000120, 0.0f);
    XIo_OutFloat(0x55000128, 0.0f);
    XIo_OutFloat(0x5500012c, 0.0f);
    XIo_OutFloat(0x5500011c, 0.0f);
    _integrator1__state = 0.0;
    _integrator1__reset_state = 2;
    XIo_OutFloat(0x55000124, 0.0f);
    _buck___boost_charge_pwm_modulator__update_mask = 1;
    HIL_OutInt32(0x2000080 + _buck___boost_charge_pwm_modulator__channels[0], 4000);
    HIL_OutInt32(0x20000c0 + _buck___boost_charge_pwm_modulator__channels[0], 800);
    HIL_OutInt32(0x20001c0 + _buck___boost_charge_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000200 + _buck___boost_charge_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000240 + _buck___boost_charge_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000300 + _buck___boost_charge_pwm_modulator__channels[0], 1);
    HIL_OutInt32(0x2000340 + _buck___boost_charge_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000140, _buck___boost_charge_pwm_modulator__update_mask);
    HIL_OutAO(0x4000, 0.0f);
    //@cmp.init.block.end
}


// Dll function pointers and dll reload function
#if defined(_WIN64)
// Define method for reloading dll functions
void ReloadDllFunctions_user_sp_cpu0_dev0(void) {
    // Load each library and setup function pointers
}

void FreeDllFunctions_user_sp_cpu0_dev0(void) {
}

#else
// Define method for reloading dll functions
void ReloadDllFunctions_user_sp_cpu0_dev0(void) {
    // Load each library and setup function pointers
}

void FreeDllFunctions_user_sp_cpu0_dev0(void) {
}
#endif

void load_fmi_libraries_user_sp_cpu0_dev0(void) {
#if defined(_WIN64)
#else
#endif
}


void ReInit_sp_scope_user_sp_cpu0_dev0() {
    // initialise SP Scope buffer pointer
}
// generated using template: common_timer_counter_handler.template-------------------------

/*****************************************************************************************/
/**
* This function is the handler which performs processing for the timer counter.
* It is called from an interrupt context such that the amount of processing
* performed should be minimized.  It is called when the timer counter expires
* if interrupts are enabled.
*
*
* @param    None
*
* @return   None
*
* @note     None
*
*****************************************************************************************/

void TimerCounterHandler_0_user_sp_cpu0_dev0() {
#if DEBUG_MODE
    printf("\n\rTimerCounterHandler_0");
#endif
    //////////////////////////////////////////////////////////////////////////
    // Set tunable parameters
    //////////////////////////////////////////////////////////////////////////
    // Generated from the component: Constant2
    // Generated from the component: Constant3
    // Generated from the component: Constant4
    // Generated from the component: Constant5
    // Generated from the component: Constant6
    // Generated from the component: Constant7
//////////////////////////////////////////////////////////////////////////
    // Output block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.out.block.start
    // Generated from the component: AUV_battery.SOC
    _auv_battery_soc__out = (HIL_InFloat(0xc80000 + 0x3));
    // Generated from the component: Contactor AUV-load
    _contactor_auv_load__out = XIo_InFloat(0x55000100);
    // Generated from the component: Contactor Discharge
    _contactor_discharge__out = XIo_InFloat(0x55000104);
    // Generated from the component: Enable
    _enable__out = XIo_InFloat(0x55000108);
    // Generated from the component: I_charge.Ia1
    _i_charge_ia1__out = (HIL_InFloat(0xc80000 + 0xa));
    // Generated from the component: I_out - Reference
    _i_out___reference__out = XIo_InFloat(0x5500010c);
    // Generated from the component: I_trickle - Reference
    _i_trickle___reference__out = XIo_InFloat(0x55000110);
    // Generated from the component: V_C.Va1
    _v_c_va1__out = (HIL_InFloat(0xc80000 + 0x5));
    // Generated from the component: V_charge.Va1
    _v_charge_va1__out = (HIL_InFloat(0xc80000 + 0x6));
    // Generated from the component: V_out - Reference
    _v_out___reference__out = XIo_InFloat(0x55000114);
    // Generated from the component: V_out - TC
    _v_out___tc__out = XIo_InFloat(0x55000118);
    // Generated from the component: Vs_meas.Va1
    _vs_meas_va1__out = (HIL_InFloat(0xc80000 + 0x7));
    // Generated from the component: AUV_battery.GainSOC
    _auv_battery_gainsoc__out = 100.0 * _auv_battery_soc__out;
    // Generated from the component: S_AUV_load.CTC_Wrapper
    if (_contactor_auv_load__out == 0x0) {
        HIL_OutInt32(0x8240481, 0x0);
    }
    else {
        HIL_OutInt32(0x8240481, 0x1);
    }
    // Generated from the component: S_discharge.CTC_Wrapper
    if (_contactor_discharge__out == 0x0) {
        HIL_OutInt32(0x8240482, 0x0);
    }
    else {
        HIL_OutInt32(0x8240482, 0x1);
    }
    // Generated from the component: Logical operator1
    _logical_operator1__out = !_enable__out;
    // Generated from the component: S_AUV.CTC_Wrapper
    if (_enable__out == 0x0) {
        HIL_OutInt32(0x8240480, 0x0);
    }
    else {
        HIL_OutInt32(0x8240480, 0x1);
    }
    // Generated from the component: I_charge - Measured
    XIo_OutFloat(0x55000120, (float)_i_charge_ia1__out);
    // Generated from the component: Sum6
    _sum6__out = _i_out___reference__out - _i_charge_ia1__out;
    // Generated from the component: Sum7
    _sum7__out = _i_trickle___reference__out - _i_charge_ia1__out;
    // Generated from the component: V_out - Measured
    XIo_OutFloat(0x55000128, (float)_v_c_va1__out);
    // Generated from the component: Sum3
    _sum3__out = _v_out___reference__out - _v_charge_va1__out;
    // Generated from the component: Relational operator1
    _relational_operator1__out = (_v_charge_va1__out <= _v_out___tc__out) ? 1 : 0;
    // Generated from the component: Relational operator2
    _relational_operator2__out = (_v_charge_va1__out >= _v_out___tc__out) ? 1 : 0;
    // Generated from the component: V_source - Measured
    XIo_OutFloat(0x5500012c, (float)_vs_meas_va1__out);
    // Generated from the component: AUV_SOC - Measured
    XIo_OutFloat(0x5500011c, (float)_auv_battery_gainsoc__out);
    // Generated from the component: Relational operator3
    _relational_operator3__out = (_auv_battery_gainsoc__out <= _constant5__out) ? 1 : 0;
    // Generated from the component: Relational operator4
    _relational_operator4__out = (_auv_battery_gainsoc__out >= _constant6__out) ? 1 : 0;
    // Generated from the component: Integrator1
    if ((_logical_operator1__out != 0.0) || (_integrator1__reset_state != 0)) {
        _integrator1__state = 0.0;
    }
    _integrator1__out = _integrator1__state;
    // Generated from the component: Product1
    _product1__out = (_constant3__out * _relational_operator1__out);
    // Generated from the component: Logical operator2
    _logical_operator2__out = _relational_operator3__out && _relational_operator2__out ;
    // Generated from the component: Product3
    _product3__out = (_constant7__out * _relational_operator4__out);
    // Generated from the component: Product2
    _product2__out = (_constant4__out * _logical_operator2__out);
    // Generated from the component: Sum8
    _sum8__out = _product3__out + _product2__out + _product1__out;
    // Generated from the component: 1D look-up table1
    if(_sum8__out <= _1d_look_up_table1__lut_addrs[0]) {
        _1d_look_up_table1__fraction = (_sum8__out - _1d_look_up_table1__lut_addrs[0])
                                       / (_1d_look_up_table1__lut_addrs[1] - _1d_look_up_table1__lut_addrs[0]);
        _1d_look_up_table1__leftIndex = 0;
    }
    else if(_sum8__out < _1d_look_up_table1__lut_addrs[2]) {
        _1d_look_up_table1__curAddr = 2 >> 1;
        _1d_look_up_table1__leftIndex = 0;
        _1d_look_up_table1__rightIndex = 2;
        while (1 < _1d_look_up_table1__rightIndex - _1d_look_up_table1__leftIndex) {
            if (_sum8__out < _1d_look_up_table1__lut_addrs[_1d_look_up_table1__curAddr]) {
                _1d_look_up_table1__rightIndex = _1d_look_up_table1__curAddr;
            }
            else {
                _1d_look_up_table1__leftIndex = _1d_look_up_table1__curAddr;
            }
            _1d_look_up_table1__curAddr = (_1d_look_up_table1__leftIndex + _1d_look_up_table1__rightIndex) >> 1;
        }
        _1d_look_up_table1__fraction = (_sum8__out - _1d_look_up_table1__lut_addrs[_1d_look_up_table1__leftIndex])
                                       / (_1d_look_up_table1__lut_addrs[_1d_look_up_table1__leftIndex + 1] - _1d_look_up_table1__lut_addrs[_1d_look_up_table1__leftIndex]);
    }
    else {
        _1d_look_up_table1__fraction = (_sum8__out - _1d_look_up_table1__lut_addrs[1])
                                       / (_1d_look_up_table1__lut_addrs[2] - _1d_look_up_table1__lut_addrs[1]);
        _1d_look_up_table1__leftIndex = 1;
    }
    _1d_look_up_table1__value = (_1d_look_up_table1__lut_table[_1d_look_up_table1__leftIndex + 1] - _1d_look_up_table1__lut_table[_1d_look_up_table1__leftIndex])
                                * _1d_look_up_table1__fraction + _1d_look_up_table1__lut_table[_1d_look_up_table1__leftIndex];
    // Generated from the component: Mode
    XIo_OutFloat(0x55000124, (float)_1d_look_up_table1__value);
    // Generated from the component: Multiport signal switch1
    switch((X_UnInt32) _1d_look_up_table1__value) {
    case 1:
        _multiport_signal_switch1__out = _sum3__out;
        break;
    case 2:
        _multiport_signal_switch1__out = _sum6__out;
        break;
    case 3:
        _multiport_signal_switch1__out = _sum7__out;
        break;
    default:
        _multiport_signal_switch1__out = 0x0;
    }
    // Generated from the component: Gain1
    _gain1__out = 0.0015 * _multiport_signal_switch1__out;
    // Generated from the component: Gain2
    _gain2__out = 5.0 * _multiport_signal_switch1__out;
    // Generated from the component: Sum4
    _sum4__out = _gain1__out + _integrator1__out;
    // Generated from the component: Limit1
    _limit1__out = MIN(MAX(_sum4__out, -1.0), 1.0);
    // Generated from the component: Gain3
    _gain3__out = 0.5 * _limit1__out;
    // Generated from the component: Sum5
    _sum5__out = _gain3__out + _constant2__out;
    // Generated from the component: Buck - Boost Charge.PWM_Modulator
    _buck___boost_charge_pwm_modulator__limited_in[0] = MIN(MAX(_sum5__out, 0.0), 1.0);
    HIL_OutInt32(0x2000040 + _buck___boost_charge_pwm_modulator__channels[0], ((X_UnInt32)((_buck___boost_charge_pwm_modulator__limited_in[0] - (0.0)) * 4000.0)));
    if (_enable__out == 0x0) {
        // pwm_modulator_en
        HIL_OutInt32(0x2000000 + _buck___boost_charge_pwm_modulator__channels[0], 0x0);
    }
    else {
        // pwm_modulator_en
        HIL_OutInt32(0x2000000 + _buck___boost_charge_pwm_modulator__channels[0], 0x1);
    }
    HIL_OutInt32(0x2000140, _buck___boost_charge_pwm_modulator__update_mask);
    // Generated from the component: Probe1
    HIL_OutAO(0x4000, (float)_sum5__out);
//@cmp.out.block.end
    //////////////////////////////////////////////////////////////////////////
    // Update block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.update.block.start
    // Generated from the component: Integrator1
    _integrator1__state = (_logical_operator1__out == 0) ? _integrator1__state + _gain2__out * 0.0001 : 0.0;
    if (_logical_operator1__out > 0)
        _integrator1__reset_state = 1;
    else if (_logical_operator1__out < 0)
        _integrator1__reset_state = -1;
    else
        _integrator1__reset_state = 0;
    //@cmp.update.block.end
}
// ----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------