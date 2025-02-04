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

//@cmp.var.start
// variables
double _boost_discharge_circuit__out;
double _constant1__out = 0.5;
double _constant2__out = 0.5;
double _constant3__out = 0.5;
double _constant4__out = 0.5;
double _constant5__out = 0.5;
double _constant6__out = 0.5;
double _constant7__out = 0.5;
double _enable___seafloor__out;
double _enable___surface__out;
double _i___energy_storage_ia1__out;
double _i___sea_surface_load_12v_ia1__out;
double _i___sea_surface_load_24v_ia1__out;
double _i___sea_surface_load_5v_ia1__out;
double _i___seafloor_load_12v_ia1__out;
double _i___seafloor_load_24v_ia1__out;
double _i___seafloor_load_5v_ia1__out;
double _voltage___boost_converter_va1__out;
double _voltage___energy_storage_va1__out;
double _voltage___sea_surface_load_12v_va1__out;
double _voltage___sea_surface_load_24v_va1__out;
double _voltage___sea_surface_load_5v_va1__out;
double _voltage___seafloor_load_12v_va1__out;
double _voltage___seafloor_load_24v_va1__out;
double _voltage___seafloor_load_5v_va1__out;
double _voltage_seafloor___reference_12v__out;
double _voltage_seafloor___reference_24v__out;
double _voltage_seafloor___reference_5v__out;
double _voltage_surface___reference__out;
double _voltage_surface___reference_12v__out;
double _voltage_surface___reference_24v__out;
double _voltage_surface___reference_5v__out;
double _logical_operator1__out;
double _logical_operator2__out;
double _logical_operator6__out;
double _logical_operator7__out;
double _logical_operator3__out;
double _logical_operator4__out;
double _logical_operator5__out;
double _sum5__out;
double _sum17__out;
double _sum20__out;
double _sum2__out;
double _sum11__out;
double _sum8__out;
double _sum14__out;
double _integrator1__out;
double _integrator2__out;
double _integrator6__out;
double _integrator7__out;
double _integrator3__out;
double _integrator4__out;
double _integrator5__out;
double _gain4__out;
double _gain5__out;
double _gain16__out;
double _gain17__out;
double _i_floor_5v__out;
double _p_floor_5v__out;
double _gain1__out;
double _gain2__out;
double _gain10__out;
double _gain11__out;
double _i_surface_24v_1__out;
double _p_surface_24v__out;
double _gain13__out;
double _gain14__out;
double _sum6__out;
double _sum18__out;
double _sum21__out;
double _sum3__out;
double _sum12__out;
double _sum9__out;
double _sum15__out;
double _limit2__out;
double _limit6__out;
double _limit7__out;
double _limit1__out;
double _limit4__out;
double _limit3__out;
double _limit5__out;
double _gain6__out;
double _gain18__out;
double _gain21__out;
double _gain3__out;
double _gain12__out;
double _gain9__out;
double _gain15__out;
double _sum7__out;
double _sum19__out;
double _sum22__out;
double _sum4__out;
double _sum13__out;
double _sum10__out;
double _sum16__out;
X_UnInt32 _seafloor_dc_dc_12v_pwm_modulator__channels[1] = {3};
double _seafloor_dc_dc_12v_pwm_modulator__limited_in[1];
X_UnInt32 _seafloor_dc_dc_12v_pwm_modulator__update_mask;

X_UnInt32 _seafloor_dc_dc_24v_pwm_modulator__channels[1] = {4};
double _seafloor_dc_dc_24v_pwm_modulator__limited_in[1];
X_UnInt32 _seafloor_dc_dc_24v_pwm_modulator__update_mask;

X_UnInt32 _seafloor_dc_dc_5v_pwm_modulator__channels[1] = {5};
double _seafloor_dc_dc_5v_pwm_modulator__limited_in[1];
X_UnInt32 _seafloor_dc_dc_5v_pwm_modulator__update_mask;

X_UnInt32 _surface_2_seafloor_dc_dc_igbt_leg_pwm_modulator__channels[1] = {6};
double _surface_2_seafloor_dc_dc_igbt_leg_pwm_modulator__limited_in[1];
X_UnInt32 _surface_2_seafloor_dc_dc_igbt_leg_pwm_modulator__update_mask;

X_UnInt32 _sea_surface_dc_dc_12v_pwm_modulator__channels[1] = {0};
double _sea_surface_dc_dc_12v_pwm_modulator__limited_in[1];
X_UnInt32 _sea_surface_dc_dc_12v_pwm_modulator__update_mask;

X_UnInt32 _sea_surface_dc_dc_24v_pwm_modulator__channels[1] = {1};
double _sea_surface_dc_dc_24v_pwm_modulator__limited_in[1];
X_UnInt32 _sea_surface_dc_dc_24v_pwm_modulator__update_mask;

X_UnInt32 _sea_surface_dc_dc_5v_pwm_modulator__channels[1] = {2};
double _sea_surface_dc_dc_5v_pwm_modulator__limited_in[1];
X_UnInt32 _sea_surface_dc_dc_5v_pwm_modulator__update_mask;

//@cmp.var.end

//@cmp.svar.start
// state variables
double _integrator1__state;
double _integrator1__reset_state;
double _integrator2__state;
double _integrator2__reset_state;
double _integrator6__state;
double _integrator6__reset_state;
double _integrator7__state;
double _integrator7__reset_state;
double _integrator3__state;
double _integrator3__reset_state;
double _integrator4__state;
double _integrator4__reset_state;
double _integrator5__state;
double _integrator5__reset_state;
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
    XIo_OutFloat(0x55000128, 0.0f);
    XIo_OutFloat(0x55000138, 0.0f);
    XIo_OutFloat(0x5500013c, 0.0f);
    XIo_OutFloat(0x55000140, 0.0f);
    XIo_OutFloat(0x5500012c, 0.0f);
    XIo_OutFloat(0x55000130, 0.0f);
    XIo_OutFloat(0x55000134, 0.0f);
    XIo_OutFloat(0x55000144, 0.0f);
    XIo_OutFloat(0x55000148, 0.0f);
    XIo_OutFloat(0x5500014c, 0.0f);
    XIo_OutFloat(0x55000150, 0.0f);
    XIo_OutFloat(0x55000154, 0.0f);
    XIo_OutFloat(0x55000158, 0.0f);
    XIo_OutFloat(0x5500015c, 0.0f);
    XIo_OutFloat(0x55000160, 0.0f);
    _integrator1__state = 0.0;
    _integrator1__reset_state = 2;
    _integrator2__state = 0.0;
    _integrator2__reset_state = 2;
    _integrator6__state = 0.0;
    _integrator6__reset_state = 2;
    _integrator7__state = 0.0;
    _integrator7__reset_state = 2;
    _integrator3__state = 0.0;
    _integrator3__reset_state = 2;
    _integrator4__state = 0.0;
    _integrator4__reset_state = 2;
    _integrator5__state = 0.0;
    _integrator5__reset_state = 2;
    _seafloor_dc_dc_12v_pwm_modulator__update_mask = 8;
    HIL_OutInt32(0x2000080 + _seafloor_dc_dc_12v_pwm_modulator__channels[0], 4000);
    HIL_OutInt32(0x20000c0 + _seafloor_dc_dc_12v_pwm_modulator__channels[0], 800);
    HIL_OutInt32(0x20001c0 + _seafloor_dc_dc_12v_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000200 + _seafloor_dc_dc_12v_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000240 + _seafloor_dc_dc_12v_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000300 + _seafloor_dc_dc_12v_pwm_modulator__channels[0], 1);
    HIL_OutInt32(0x2000340 + _seafloor_dc_dc_12v_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000140, _seafloor_dc_dc_12v_pwm_modulator__update_mask);
    _seafloor_dc_dc_24v_pwm_modulator__update_mask = 16;
    HIL_OutInt32(0x2000080 + _seafloor_dc_dc_24v_pwm_modulator__channels[0], 4000);
    HIL_OutInt32(0x20000c0 + _seafloor_dc_dc_24v_pwm_modulator__channels[0], 800);
    HIL_OutInt32(0x20001c0 + _seafloor_dc_dc_24v_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000200 + _seafloor_dc_dc_24v_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000240 + _seafloor_dc_dc_24v_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000300 + _seafloor_dc_dc_24v_pwm_modulator__channels[0], 1);
    HIL_OutInt32(0x2000340 + _seafloor_dc_dc_24v_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000140, _seafloor_dc_dc_24v_pwm_modulator__update_mask);
    _seafloor_dc_dc_5v_pwm_modulator__update_mask = 32;
    HIL_OutInt32(0x2000080 + _seafloor_dc_dc_5v_pwm_modulator__channels[0], 4000);
    HIL_OutInt32(0x20000c0 + _seafloor_dc_dc_5v_pwm_modulator__channels[0], 800);
    HIL_OutInt32(0x20001c0 + _seafloor_dc_dc_5v_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000200 + _seafloor_dc_dc_5v_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000240 + _seafloor_dc_dc_5v_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000300 + _seafloor_dc_dc_5v_pwm_modulator__channels[0], 1);
    HIL_OutInt32(0x2000340 + _seafloor_dc_dc_5v_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000140, _seafloor_dc_dc_5v_pwm_modulator__update_mask);
    _surface_2_seafloor_dc_dc_igbt_leg_pwm_modulator__update_mask = 64;
    HIL_OutInt32(0x2000080 + _surface_2_seafloor_dc_dc_igbt_leg_pwm_modulator__channels[0], 4000);
    HIL_OutInt32(0x20000c0 + _surface_2_seafloor_dc_dc_igbt_leg_pwm_modulator__channels[0], 800);
    HIL_OutInt32(0x20001c0 + _surface_2_seafloor_dc_dc_igbt_leg_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000200 + _surface_2_seafloor_dc_dc_igbt_leg_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000240 + _surface_2_seafloor_dc_dc_igbt_leg_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000300 + _surface_2_seafloor_dc_dc_igbt_leg_pwm_modulator__channels[0], 1);
    HIL_OutInt32(0x2000340 + _surface_2_seafloor_dc_dc_igbt_leg_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000140, _surface_2_seafloor_dc_dc_igbt_leg_pwm_modulator__update_mask);
    _sea_surface_dc_dc_12v_pwm_modulator__update_mask = 1;
    HIL_OutInt32(0x2000080 + _sea_surface_dc_dc_12v_pwm_modulator__channels[0], 4000);
    HIL_OutInt32(0x20000c0 + _sea_surface_dc_dc_12v_pwm_modulator__channels[0], 800);
    HIL_OutInt32(0x20001c0 + _sea_surface_dc_dc_12v_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000200 + _sea_surface_dc_dc_12v_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000240 + _sea_surface_dc_dc_12v_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000300 + _sea_surface_dc_dc_12v_pwm_modulator__channels[0], 1);
    HIL_OutInt32(0x2000340 + _sea_surface_dc_dc_12v_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000140, _sea_surface_dc_dc_12v_pwm_modulator__update_mask);
    _sea_surface_dc_dc_24v_pwm_modulator__update_mask = 2;
    HIL_OutInt32(0x2000080 + _sea_surface_dc_dc_24v_pwm_modulator__channels[0], 4000);
    HIL_OutInt32(0x20000c0 + _sea_surface_dc_dc_24v_pwm_modulator__channels[0], 800);
    HIL_OutInt32(0x20001c0 + _sea_surface_dc_dc_24v_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000200 + _sea_surface_dc_dc_24v_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000240 + _sea_surface_dc_dc_24v_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000300 + _sea_surface_dc_dc_24v_pwm_modulator__channels[0], 1);
    HIL_OutInt32(0x2000340 + _sea_surface_dc_dc_24v_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000140, _sea_surface_dc_dc_24v_pwm_modulator__update_mask);
    _sea_surface_dc_dc_5v_pwm_modulator__update_mask = 4;
    HIL_OutInt32(0x2000080 + _sea_surface_dc_dc_5v_pwm_modulator__channels[0], 4000);
    HIL_OutInt32(0x20000c0 + _sea_surface_dc_dc_5v_pwm_modulator__channels[0], 800);
    HIL_OutInt32(0x20001c0 + _sea_surface_dc_dc_5v_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000200 + _sea_surface_dc_dc_5v_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000240 + _sea_surface_dc_dc_5v_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000300 + _sea_surface_dc_dc_5v_pwm_modulator__channels[0], 1);
    HIL_OutInt32(0x2000340 + _sea_surface_dc_dc_5v_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000140, _sea_surface_dc_dc_5v_pwm_modulator__update_mask);
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
    // Generated from the component: Constant1
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
    // Generated from the component: Boost Discharge Circuit
    _boost_discharge_circuit__out = XIo_InFloat(0x55000100);
    // Generated from the component: Enable - Seafloor
    _enable___seafloor__out = XIo_InFloat(0x55000104);
    // Generated from the component: Enable - Surface
    _enable___surface__out = XIo_InFloat(0x55000108);
    // Generated from the component: I - Energy Storage.Ia1
    _i___energy_storage_ia1__out = (HIL_InFloat(0xc80000 + 0x20a));
    // Generated from the component: I - Sea-surface Load 12V.Ia1
    _i___sea_surface_load_12v_ia1__out = (HIL_InFloat(0xc80000 + 0x20b));
    // Generated from the component: I - Sea-surface Load 24V.Ia1
    _i___sea_surface_load_24v_ia1__out = (HIL_InFloat(0xc80000 + 0x20c));
    // Generated from the component: I - Sea-surface Load 5V.Ia1
    _i___sea_surface_load_5v_ia1__out = (HIL_InFloat(0xc80000 + 0x20d));
    // Generated from the component: I - Seafloor Load 12V.Ia1
    _i___seafloor_load_12v_ia1__out = (HIL_InFloat(0xc80000 + 0x409));
    // Generated from the component: I - Seafloor Load 24V.Ia1
    _i___seafloor_load_24v_ia1__out = (HIL_InFloat(0xc80000 + 0x40a));
    // Generated from the component: I - Seafloor Load 5V.Ia1
    _i___seafloor_load_5v_ia1__out = (HIL_InFloat(0xc80000 + 0x40b));
    // Generated from the component: Voltage - Boost Converter.Va1
    _voltage___boost_converter_va1__out = (HIL_InFloat(0xc80000 + 0x2));
    // Generated from the component: Voltage - Energy Storage.Va1
    _voltage___energy_storage_va1__out = (HIL_InFloat(0xc80000 + 0x206));
    // Generated from the component: Voltage - Sea-surface Load 12V.Va1
    _voltage___sea_surface_load_12v_va1__out = (HIL_InFloat(0xc80000 + 0x207));
    // Generated from the component: Voltage - Sea-surface Load 24V.Va1
    _voltage___sea_surface_load_24v_va1__out = (HIL_InFloat(0xc80000 + 0x208));
    // Generated from the component: Voltage - Sea-surface Load 5V.Va1
    _voltage___sea_surface_load_5v_va1__out = (HIL_InFloat(0xc80000 + 0x209));
    // Generated from the component: Voltage - Seafloor Load 12V.Va1
    _voltage___seafloor_load_12v_va1__out = (HIL_InFloat(0xc80000 + 0x406));
    // Generated from the component: Voltage - Seafloor Load 24V.Va1
    _voltage___seafloor_load_24v_va1__out = (HIL_InFloat(0xc80000 + 0x407));
    // Generated from the component: Voltage - Seafloor Load 5V.Va1
    _voltage___seafloor_load_5v_va1__out = (HIL_InFloat(0xc80000 + 0x408));
    // Generated from the component: Voltage Seafloor - Reference 12V
    _voltage_seafloor___reference_12v__out = XIo_InFloat(0x5500010c);
    // Generated from the component: Voltage Seafloor - Reference 24V
    _voltage_seafloor___reference_24v__out = XIo_InFloat(0x55000110);
    // Generated from the component: Voltage Seafloor - Reference 5V
    _voltage_seafloor___reference_5v__out = XIo_InFloat(0x55000114);
    // Generated from the component: Voltage Surface - Reference
    _voltage_surface___reference__out = XIo_InFloat(0x55000118);
    // Generated from the component: Voltage Surface - Reference 12V
    _voltage_surface___reference_12v__out = XIo_InFloat(0x5500011c);
    // Generated from the component: Voltage Surface - Reference 24V
    _voltage_surface___reference_24v__out = XIo_InFloat(0x55000120);
    // Generated from the component: Voltage Surface - Reference 5V
    _voltage_surface___reference_5v__out = XIo_InFloat(0x55000124);
    // Generated from the component: S3.CTC_Wrapper
    if (_boost_discharge_circuit__out == 0x0) {
        HIL_OutInt32(0x8a40480, 0x0);
    }
    else {
        HIL_OutInt32(0x8a40480, 0x1);
    }
    // Generated from the component: Logical operator1
    _logical_operator1__out = !_enable___seafloor__out;
    // Generated from the component: Logical operator2
    _logical_operator2__out = !_enable___seafloor__out;
    // Generated from the component: Logical operator6
    _logical_operator6__out = !_enable___seafloor__out;
    // Generated from the component: Logical operator7
    _logical_operator7__out = !_enable___seafloor__out;
    // Generated from the component: S1.CTC_Wrapper
    if (_enable___seafloor__out == 0x0) {
        HIL_OutInt32(0x8240480, 0x0);
    }
    else {
        HIL_OutInt32(0x8240480, 0x1);
    }
    // Generated from the component: Surface 2 Seafloor DC-DC.IGBT Leg.IGBT Leg global gds ovs.termination1
    // Generated from the component: Logical operator3
    _logical_operator3__out = !_enable___surface__out;
    // Generated from the component: Logical operator4
    _logical_operator4__out = !_enable___surface__out;
    // Generated from the component: Logical operator5
    _logical_operator5__out = !_enable___surface__out;
    // Generated from the component: Switch Sea-surface 24V.CTC_Wrapper
    if (_enable___surface__out == 0x0) {
        HIL_OutInt32(0x8640480, 0x0);
    }
    else {
        HIL_OutInt32(0x8640480, 0x1);
    }
    // Generated from the component: I - Energy Storage (SCADA)
    XIo_OutFloat(0x55000128, (float)_i___energy_storage_ia1__out);
    // Generated from the component: I Surface 12V
    XIo_OutFloat(0x55000138, (float)_i___sea_surface_load_12v_ia1__out);
    // Generated from the component: I Surface 24V
    XIo_OutFloat(0x5500013c, (float)_i___sea_surface_load_24v_ia1__out);
    // Generated from the component: I Surface 5V
    XIo_OutFloat(0x55000140, (float)_i___sea_surface_load_5v_ia1__out);
    // Generated from the component: I Seafloor 12V
    XIo_OutFloat(0x5500012c, (float)_i___seafloor_load_12v_ia1__out);
    // Generated from the component: I Seafloor 24V
    XIo_OutFloat(0x55000130, (float)_i___seafloor_load_24v_ia1__out);
    // Generated from the component: I Seafloor 5V
    XIo_OutFloat(0x55000134, (float)_i___seafloor_load_5v_ia1__out);
    // Generated from the component: SCADA Output1
    XIo_OutFloat(0x55000144, (float)_voltage___boost_converter_va1__out);
    // Generated from the component: V - Energy Storage
    XIo_OutFloat(0x55000148, (float)_voltage___energy_storage_va1__out);
    // Generated from the component: V - Sea-surface Load 12V
    XIo_OutFloat(0x5500014c, (float)_voltage___sea_surface_load_12v_va1__out);
    // Generated from the component: V - Sea-surface Load 24V
    XIo_OutFloat(0x55000150, (float)_voltage___sea_surface_load_24v_va1__out);
    // Generated from the component: V - Sea-surface Load 5V
    XIo_OutFloat(0x55000154, (float)_voltage___sea_surface_load_5v_va1__out);
    // Generated from the component: V - Seafloor Load 12V
    XIo_OutFloat(0x55000158, (float)_voltage___seafloor_load_12v_va1__out);
    // Generated from the component: V - Seafloor Load 24V
    XIo_OutFloat(0x5500015c, (float)_voltage___seafloor_load_24v_va1__out);
    // Generated from the component: V - Seafloor Load 5V
    XIo_OutFloat(0x55000160, (float)_voltage___seafloor_load_5v_va1__out);
    // Generated from the component: Sum5
    _sum5__out = _voltage_seafloor___reference_12v__out - _voltage___seafloor_load_12v_va1__out;
    // Generated from the component: Sum17
    _sum17__out = _voltage_seafloor___reference_24v__out - _voltage___seafloor_load_24v_va1__out;
    // Generated from the component: Sum20
    _sum20__out = _voltage_seafloor___reference_5v__out - _voltage___seafloor_load_5v_va1__out;
    // Generated from the component: Sum2
    _sum2__out = _voltage_surface___reference__out - _voltage___boost_converter_va1__out;
    // Generated from the component: Sum11
    _sum11__out = _voltage_surface___reference_12v__out - _voltage___sea_surface_load_12v_va1__out;
    // Generated from the component: Sum8
    _sum8__out = _voltage_surface___reference_24v__out - _voltage___sea_surface_load_24v_va1__out;
    // Generated from the component: Sum14
    _sum14__out = _voltage_surface___reference_5v__out - _voltage___sea_surface_load_5v_va1__out;
    // Generated from the component: Integrator1
    if ((_logical_operator1__out != 0.0) || (_integrator1__reset_state != 0)) {
        _integrator1__state = 0.0;
    }
    _integrator1__out = _integrator1__state;
    // Generated from the component: Integrator2
    if ((_logical_operator2__out != 0.0) || (_integrator2__reset_state != 0)) {
        _integrator2__state = 0.0;
    }
    _integrator2__out = _integrator2__state;
    // Generated from the component: Integrator6
    if ((_logical_operator6__out != 0.0) || (_integrator6__reset_state != 0)) {
        _integrator6__state = 0.0;
    }
    _integrator6__out = _integrator6__state;
    // Generated from the component: Integrator7
    if ((_logical_operator7__out != 0.0) || (_integrator7__reset_state != 0)) {
        _integrator7__state = 0.0;
    }
    _integrator7__out = _integrator7__state;
    // Generated from the component: Integrator3
    if ((_logical_operator3__out != 0.0) || (_integrator3__reset_state != 0)) {
        _integrator3__state = 0.0;
    }
    _integrator3__out = _integrator3__state;
    // Generated from the component: Integrator4
    if ((_logical_operator4__out != 0.0) || (_integrator4__reset_state != 0)) {
        _integrator4__state = 0.0;
    }
    _integrator4__out = _integrator4__state;
    // Generated from the component: Integrator5
    if ((_logical_operator5__out != 0.0) || (_integrator5__reset_state != 0)) {
        _integrator5__state = 0.0;
    }
    _integrator5__out = _integrator5__state;
    // Generated from the component: Gain4
    _gain4__out = 0.38999804999999993 * _sum5__out;
    // Generated from the component: Gain5
    _gain5__out = 50.0 * _sum5__out;
    // Generated from the component: Gain16
    _gain16__out = 0.62499375 * _sum17__out;
    // Generated from the component: Gain17
    _gain17__out = 50.0 * _sum17__out;
    // Generated from the component: I_Floor_5V
    _i_floor_5v__out = 50.0 * _sum20__out;
    // Generated from the component: P_Floor_5V
    _p_floor_5v__out = 0.35999925000000005 * _sum20__out;
    // Generated from the component: Gain1
    _gain1__out = 0.00025200000000000005 * _sum2__out;
    // Generated from the component: Gain2
    _gain2__out = 5.0 * _sum2__out;
    // Generated from the component: Gain10
    _gain10__out = 1.7331450020833334 * _sum11__out;
    // Generated from the component: Gain11
    _gain11__out = 50.0 * _sum11__out;
    // Generated from the component: I_surface_24V
    _i_surface_24v_1__out = 50.0 * _sum8__out;
    // Generated from the component: P_surface_24V
    _p_surface_24v__out = 0.9059773499999999 * _sum8__out;
    // Generated from the component: Gain13
    _gain13__out = 0.39599793750000006 * _sum14__out;
    // Generated from the component: Gain14
    _gain14__out = 50.0 * _sum14__out;
    // Generated from the component: Sum6
    _sum6__out = _gain4__out + _integrator2__out;
    // Generated from the component: Sum18
    _sum18__out = _gain16__out + _integrator6__out;
    // Generated from the component: Sum21
    _sum21__out = _p_floor_5v__out + _integrator7__out;
    // Generated from the component: Sum3
    _sum3__out = _gain1__out + _integrator1__out;
    // Generated from the component: Sum12
    _sum12__out = _gain10__out + _integrator4__out;
    // Generated from the component: Sum9
    _sum9__out = _p_surface_24v__out + _integrator3__out;
    // Generated from the component: Sum15
    _sum15__out = _gain13__out + _integrator5__out;
    // Generated from the component: Limit2
    _limit2__out = MIN(MAX(_sum6__out, -1.0), 1.0);
    // Generated from the component: Limit6
    _limit6__out = MIN(MAX(_sum18__out, -1.0), 1.0);
    // Generated from the component: Limit7
    _limit7__out = MIN(MAX(_sum21__out, -1.0), 1.0);
    // Generated from the component: Limit1
    _limit1__out = MIN(MAX(_sum3__out, -1.0), 1.0);
    // Generated from the component: Limit4
    _limit4__out = MIN(MAX(_sum12__out, -1.0), 1.0);
    // Generated from the component: Limit3
    _limit3__out = MIN(MAX(_sum9__out, -1.0), 1.0);
    // Generated from the component: Limit5
    _limit5__out = MIN(MAX(_sum15__out, -1.0), 1.0);
    // Generated from the component: Gain6
    _gain6__out = 0.5 * _limit2__out;
    // Generated from the component: Gain18
    _gain18__out = 0.5 * _limit6__out;
    // Generated from the component: Gain21
    _gain21__out = 0.5 * _limit7__out;
    // Generated from the component: Gain3
    _gain3__out = 0.5 * _limit1__out;
    // Generated from the component: Gain12
    _gain12__out = 0.5 * _limit4__out;
    // Generated from the component: Gain9
    _gain9__out = 0.5 * _limit3__out;
    // Generated from the component: Gain15
    _gain15__out = 0.5 * _limit5__out;
    // Generated from the component: Sum7
    _sum7__out = _gain6__out + _constant2__out;
    // Generated from the component: Sum19
    _sum19__out = _gain18__out + _constant6__out;
    // Generated from the component: Sum22
    _sum22__out = _gain21__out + _constant7__out;
    // Generated from the component: Sum4
    _sum4__out = _gain3__out + _constant1__out;
    // Generated from the component: Sum13
    _sum13__out = _gain12__out + _constant4__out;
    // Generated from the component: Sum10
    _sum10__out = _gain9__out + _constant3__out;
    // Generated from the component: Sum16
    _sum16__out = _gain15__out + _constant5__out;
    // Generated from the component: Seafloor DC-DC 12V.PWM_Modulator
    _seafloor_dc_dc_12v_pwm_modulator__limited_in[0] = MIN(MAX(_sum7__out, 0.0), 1.0);
    HIL_OutInt32(0x2000040 + _seafloor_dc_dc_12v_pwm_modulator__channels[0], ((X_UnInt32)((_seafloor_dc_dc_12v_pwm_modulator__limited_in[0] - (0.0)) * 4000.0)));
    if (_enable___seafloor__out == 0x0) {
        // pwm_modulator_en
        HIL_OutInt32(0x2000000 + _seafloor_dc_dc_12v_pwm_modulator__channels[0], 0x0);
    }
    else {
        // pwm_modulator_en
        HIL_OutInt32(0x2000000 + _seafloor_dc_dc_12v_pwm_modulator__channels[0], 0x1);
    }
    HIL_OutInt32(0x2000140, _seafloor_dc_dc_12v_pwm_modulator__update_mask);
    // Generated from the component: Seafloor DC-DC 24V.PWM_Modulator
    _seafloor_dc_dc_24v_pwm_modulator__limited_in[0] = MIN(MAX(_sum19__out, 0.0), 1.0);
    HIL_OutInt32(0x2000040 + _seafloor_dc_dc_24v_pwm_modulator__channels[0], ((X_UnInt32)((_seafloor_dc_dc_24v_pwm_modulator__limited_in[0] - (0.0)) * 4000.0)));
    if (_enable___seafloor__out == 0x0) {
        // pwm_modulator_en
        HIL_OutInt32(0x2000000 + _seafloor_dc_dc_24v_pwm_modulator__channels[0], 0x0);
    }
    else {
        // pwm_modulator_en
        HIL_OutInt32(0x2000000 + _seafloor_dc_dc_24v_pwm_modulator__channels[0], 0x1);
    }
    HIL_OutInt32(0x2000140, _seafloor_dc_dc_24v_pwm_modulator__update_mask);
    // Generated from the component: Seafloor DC-DC 5V.PWM_Modulator
    _seafloor_dc_dc_5v_pwm_modulator__limited_in[0] = MIN(MAX(_sum22__out, 0.0), 1.0);
    HIL_OutInt32(0x2000040 + _seafloor_dc_dc_5v_pwm_modulator__channels[0], ((X_UnInt32)((_seafloor_dc_dc_5v_pwm_modulator__limited_in[0] - (0.0)) * 4000.0)));
    if (_enable___seafloor__out == 0x0) {
        // pwm_modulator_en
        HIL_OutInt32(0x2000000 + _seafloor_dc_dc_5v_pwm_modulator__channels[0], 0x0);
    }
    else {
        // pwm_modulator_en
        HIL_OutInt32(0x2000000 + _seafloor_dc_dc_5v_pwm_modulator__channels[0], 0x1);
    }
    HIL_OutInt32(0x2000140, _seafloor_dc_dc_5v_pwm_modulator__update_mask);
    // Generated from the component: Surface 2 Seafloor DC-DC.IGBT Leg.PWM_Modulator
    _surface_2_seafloor_dc_dc_igbt_leg_pwm_modulator__limited_in[0] = MIN(MAX(_sum4__out, 0.0), 1.0);
    HIL_OutInt32(0x2000040 + _surface_2_seafloor_dc_dc_igbt_leg_pwm_modulator__channels[0], ((X_UnInt32)((_surface_2_seafloor_dc_dc_igbt_leg_pwm_modulator__limited_in[0] - (0.0)) * 4000.0)));
    if (_enable___seafloor__out == 0x0) {
        // pwm_modulator_en
        HIL_OutInt32(0x2000000 + _surface_2_seafloor_dc_dc_igbt_leg_pwm_modulator__channels[0], 0x0);
    }
    else {
        // pwm_modulator_en
        HIL_OutInt32(0x2000000 + _surface_2_seafloor_dc_dc_igbt_leg_pwm_modulator__channels[0], 0x1);
    }
    HIL_OutInt32(0x2000140, _surface_2_seafloor_dc_dc_igbt_leg_pwm_modulator__update_mask);
    // Generated from the component: Sea-surface DC-DC 12V.PWM_Modulator
    _sea_surface_dc_dc_12v_pwm_modulator__limited_in[0] = MIN(MAX(_sum13__out, 0.0), 1.0);
    HIL_OutInt32(0x2000040 + _sea_surface_dc_dc_12v_pwm_modulator__channels[0], ((X_UnInt32)((_sea_surface_dc_dc_12v_pwm_modulator__limited_in[0] - (0.0)) * 4000.0)));
    if (_enable___surface__out == 0x0) {
        // pwm_modulator_en
        HIL_OutInt32(0x2000000 + _sea_surface_dc_dc_12v_pwm_modulator__channels[0], 0x0);
    }
    else {
        // pwm_modulator_en
        HIL_OutInt32(0x2000000 + _sea_surface_dc_dc_12v_pwm_modulator__channels[0], 0x1);
    }
    HIL_OutInt32(0x2000140, _sea_surface_dc_dc_12v_pwm_modulator__update_mask);
    // Generated from the component: Sea-surface DC-DC 24V.PWM_Modulator
    _sea_surface_dc_dc_24v_pwm_modulator__limited_in[0] = MIN(MAX(_sum10__out, 0.0), 1.0);
    HIL_OutInt32(0x2000040 + _sea_surface_dc_dc_24v_pwm_modulator__channels[0], ((X_UnInt32)((_sea_surface_dc_dc_24v_pwm_modulator__limited_in[0] - (0.0)) * 4000.0)));
    if (_enable___surface__out == 0x0) {
        // pwm_modulator_en
        HIL_OutInt32(0x2000000 + _sea_surface_dc_dc_24v_pwm_modulator__channels[0], 0x0);
    }
    else {
        // pwm_modulator_en
        HIL_OutInt32(0x2000000 + _sea_surface_dc_dc_24v_pwm_modulator__channels[0], 0x1);
    }
    HIL_OutInt32(0x2000140, _sea_surface_dc_dc_24v_pwm_modulator__update_mask);
    // Generated from the component: Sea-surface DC-DC 5V.PWM_Modulator
    _sea_surface_dc_dc_5v_pwm_modulator__limited_in[0] = MIN(MAX(_sum16__out, 0.0), 1.0);
    HIL_OutInt32(0x2000040 + _sea_surface_dc_dc_5v_pwm_modulator__channels[0], ((X_UnInt32)((_sea_surface_dc_dc_5v_pwm_modulator__limited_in[0] - (0.0)) * 4000.0)));
    if (_enable___surface__out == 0x0) {
        // pwm_modulator_en
        HIL_OutInt32(0x2000000 + _sea_surface_dc_dc_5v_pwm_modulator__channels[0], 0x0);
    }
    else {
        // pwm_modulator_en
        HIL_OutInt32(0x2000000 + _sea_surface_dc_dc_5v_pwm_modulator__channels[0], 0x1);
    }
    HIL_OutInt32(0x2000140, _sea_surface_dc_dc_5v_pwm_modulator__update_mask);
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
    // Generated from the component: Integrator2
    _integrator2__state = (_logical_operator2__out == 0) ? _integrator2__state + _gain5__out * 0.0001 : 0.0;
    if (_logical_operator2__out > 0)
        _integrator2__reset_state = 1;
    else if (_logical_operator2__out < 0)
        _integrator2__reset_state = -1;
    else
        _integrator2__reset_state = 0;
    // Generated from the component: Integrator6
    _integrator6__state = (_logical_operator6__out == 0) ? _integrator6__state + _gain17__out * 0.0001 : 0.0;
    if (_logical_operator6__out > 0)
        _integrator6__reset_state = 1;
    else if (_logical_operator6__out < 0)
        _integrator6__reset_state = -1;
    else
        _integrator6__reset_state = 0;
    // Generated from the component: Integrator7
    _integrator7__state = (_logical_operator7__out == 0) ? _integrator7__state + _i_floor_5v__out * 0.0001 : 0.0;
    if (_logical_operator7__out > 0)
        _integrator7__reset_state = 1;
    else if (_logical_operator7__out < 0)
        _integrator7__reset_state = -1;
    else
        _integrator7__reset_state = 0;
    // Generated from the component: Integrator3
    _integrator3__state = (_logical_operator3__out == 0) ? _integrator3__state + _i_surface_24v_1__out * 0.0001 : 0.0;
    if (_logical_operator3__out > 0)
        _integrator3__reset_state = 1;
    else if (_logical_operator3__out < 0)
        _integrator3__reset_state = -1;
    else
        _integrator3__reset_state = 0;
    // Generated from the component: Integrator4
    _integrator4__state = (_logical_operator4__out == 0) ? _integrator4__state + _gain11__out * 0.0001 : 0.0;
    if (_logical_operator4__out > 0)
        _integrator4__reset_state = 1;
    else if (_logical_operator4__out < 0)
        _integrator4__reset_state = -1;
    else
        _integrator4__reset_state = 0;
    // Generated from the component: Integrator5
    _integrator5__state = (_logical_operator5__out == 0) ? _integrator5__state + _gain14__out * 0.0001 : 0.0;
    if (_logical_operator5__out > 0)
        _integrator5__reset_state = 1;
    else if (_logical_operator5__out < 0)
        _integrator5__reset_state = -1;
    else
        _integrator5__reset_state = 0;
    //@cmp.update.block.end
}
// ----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------