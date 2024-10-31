/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: e_private.h
 *
 * Code generated for Simulink model 'e'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Oct 30 23:34:32 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef e_private_h_
#define e_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "e.h"
#include "e_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern void e_DigitalPortRead_Init(DW_DigitalPortRead_e_T *localDW);
extern void e_DigitalPortRead(B_DigitalPortRead_e_T *localB);

#endif                                 /* e_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
