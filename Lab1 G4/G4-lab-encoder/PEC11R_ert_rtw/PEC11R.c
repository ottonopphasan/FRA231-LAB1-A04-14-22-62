/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PEC11R.c
 *
 * Code generated for Simulink model 'PEC11R'.
 *
 * Model version                  : 1.34
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Oct 31 17:17:16 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PEC11R.h"
#include "PEC11R_types.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "stm_timer_ll.h"
#include "PEC11R_private.h"

/* Block signals (default storage) */
B_PEC11R_T PEC11R_B;

/* Block states (default storage) */
DW_PEC11R_T PEC11R_DW;

/* Real-time model */
static RT_MODEL_PEC11R_T PEC11R_M_;
RT_MODEL_PEC11R_T *const PEC11R_M = &PEC11R_M_;

/* Forward declaration for local functions */
static void PEC11R_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj);
static void PEC11R_SystemCore_setup_k(stm32cube_blocks_EncoderBlock_T *obj);
static void PEC11R_SystemCore_setup_ks(stm32cube_blocks_EncoderBlock_T *obj);
static void PEC11R_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Encoder' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void PEC11R_SystemCore_setup_k(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM4;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Encoder1' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void PEC11R_SystemCore_setup_ks(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Encoder2' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM8;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Encoder2' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/Encoder2' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Encoder2' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

/* Model step function */
void PEC11R_step(void)
{
  real_T pulse_diff;
  real_T tmp;
  uint32_T pinReadLoc;
  boolean_T rtb_FixPtRelationalOperator;

  /* MATLABSystem: '<Root>/Encoder' */
  PEC11R_B.RowSig = getTimerCounterValueForG4(PEC11R_DW.obj_g.TimerHandle, false,
    NULL);

  /* MATLABSystem: '<S20>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

  /* MATLABSystem: '<S20>/Digital Port Read' */
  PEC11R_B.DigitalPortRead = ((pinReadLoc & 8192U) != 0U);

  /* RelationalOperator: '<S1>/FixPt Relational Operator' incorporates:
   *  RelationalOperator: '<S13>/Compare'
   *  UnitDelay: '<S1>/Delay Input1'
   *
   * Block description for '<S1>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator = ((int32_T)PEC11R_B.DigitalPortRead > (int32_T)
    PEC11R_DW.DelayInput1_DSTATE);

  /* MATLAB Function: '<Root>/MATLAB Function2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  pulse_diff = (real_T)PEC11R_B.RowSig - PEC11R_DW.lastpulse_g;
  if (fabs(pulse_diff) > 10000.0) {
    if (rtIsNaN(pulse_diff)) {
      tmp = (rtNaN);
    } else if (pulse_diff < 0.0) {
      tmp = -1.0;
    } else {
      tmp = (pulse_diff > 0.0);
    }

    PEC11R_DW.pulse_f += 65520.0 * tmp - pulse_diff;
  } else {
    PEC11R_DW.pulse_f += pulse_diff;
  }

  if (rtb_FixPtRelationalOperator) {
    PEC11R_DW.home_position_o = PEC11R_DW.pulse_f;
  }

  PEC11R_B.pul_l = PEC11R_DW.pulse_f - PEC11R_DW.home_position_o;
  PEC11R_B.pos_c = PEC11R_B.pul_l * 0.26179938779914941;
  PEC11R_B.velo_m = (PEC11R_B.pos_c - PEC11R_DW.lastrad_k) / 0.1;
  PEC11R_DW.lastpulse_g = PEC11R_B.RowSig;
  PEC11R_DW.lastrad_k = PEC11R_B.pos_c;

  /* End of MATLAB Function: '<Root>/MATLAB Function2' */
  /* MATLABSystem: '<Root>/Encoder1' */
  pinReadLoc = getTimerCounterValueForG4(PEC11R_DW.obj_l.TimerHandle, false,
    NULL);

  /* MATLAB Function: '<Root>/MATLAB Function3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  MATLABSystem: '<Root>/Encoder1'
   */
  pulse_diff = (real_T)pinReadLoc - PEC11R_DW.lastpulse;
  if (fabs(pulse_diff) > 10000.0) {
    if (rtIsNaN(pulse_diff)) {
      tmp = (rtNaN);
    } else if (pulse_diff < 0.0) {
      tmp = -1.0;
    } else {
      tmp = (pulse_diff > 0.0);
    }

    PEC11R_DW.pulse += 65520.0 * tmp - pulse_diff;
  } else {
    PEC11R_DW.pulse += pulse_diff;
  }

  if (rtb_FixPtRelationalOperator) {
    PEC11R_DW.home_position = PEC11R_DW.pulse;
  }

  PEC11R_B.pul = PEC11R_DW.pulse - PEC11R_DW.home_position;
  PEC11R_B.pos = PEC11R_B.pul * 0.1308996938995747;
  PEC11R_B.velo = (PEC11R_B.pos - PEC11R_DW.lastrad) / 0.1;
  PEC11R_DW.lastpulse = pinReadLoc;
  PEC11R_DW.lastrad = PEC11R_B.pos;

  /* End of MATLAB Function: '<Root>/MATLAB Function3' */
  /* MATLABSystem: '<Root>/Encoder2' */
  pinReadLoc = getTimerCounterValueForG4(PEC11R_DW.obj.TimerHandle, false, NULL);

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  MATLABSystem: '<Root>/Encoder2'
   */
  pulse_diff = (real_T)pinReadLoc - PEC11R_DW.lastpulse_l;
  if (fabs(pulse_diff) > 10000.0) {
    if (rtIsNaN(pulse_diff)) {
      tmp = (rtNaN);
    } else if (pulse_diff < 0.0) {
      tmp = -1.0;
    } else {
      tmp = (pulse_diff > 0.0);
    }

    PEC11R_DW.pulse_h += 65472.0 * tmp - pulse_diff;
  } else {
    PEC11R_DW.pulse_h += pulse_diff;
  }

  if (rtb_FixPtRelationalOperator) {
    PEC11R_DW.home_position_l = PEC11R_DW.pulse_h;
  }

  PEC11R_B.pul_p = PEC11R_DW.pulse_h - PEC11R_DW.home_position_l;
  PEC11R_B.pos_h = PEC11R_B.pul_p * 0.065449846949787352;
  PEC11R_B.velo_l = (PEC11R_B.pos_h - PEC11R_DW.lastrad_b) / 0.1;
  PEC11R_DW.lastpulse_l = pinReadLoc;
  PEC11R_DW.lastrad_b = PEC11R_B.pos_h;

  /* End of MATLAB Function: '<Root>/MATLAB Function1' */
  /* MATLABSystem: '<S22>/Digital Port Read' */
  LL_GPIO_ReadInputPort(GPIOC);

  /* MATLABSystem: '<S16>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

  /* MATLABSystem: '<S16>/Digital Port Read' */
  PEC11R_B.DigitalPortRead_kx = ((pinReadLoc & 16U) != 0U);

  /* MATLABSystem: '<S18>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

  /* MATLABSystem: '<S18>/Digital Port Read' */
  PEC11R_B.DigitalPortRead_k = ((pinReadLoc & 32U) != 0U);

  /* MATLAB Function: '<Root>/x1' incorporates:
   *  MATLAB Function: '<Root>/x2'
   *  MATLAB Function: '<Root>/x4'
   */
  rtb_FixPtRelationalOperator = !PEC11R_B.DigitalPortRead_kx;
  if (rtb_FixPtRelationalOperator && (PEC11R_DW.stageA_m != 0.0)) {
    PEC11R_DW.stageA_m = 0.0;
    PEC11R_DW.c_n = (2.0 * (real_T)PEC11R_B.DigitalPortRead_k + PEC11R_DW.c_n) -
      1.0;
  } else if (PEC11R_B.DigitalPortRead_kx) {
    PEC11R_DW.stageA_m = 1.0;
  }

  PEC11R_B.y_o = PEC11R_DW.c_n;

  /* End of MATLAB Function: '<Root>/x1' */
  /* MATLAB Function: '<Root>/x2' */
  if (rtb_FixPtRelationalOperator && (PEC11R_DW.stageA_a != 0.0)) {
    PEC11R_DW.stageA_a = 0.0;
    PEC11R_DW.c_i = (2.0 * (real_T)PEC11R_B.DigitalPortRead_k + PEC11R_DW.c_i) -
      1.0;
  } else if (PEC11R_B.DigitalPortRead_kx && (!(PEC11R_DW.stageA_a != 0.0))) {
    PEC11R_DW.stageA_a = 1.0;
    PEC11R_DW.c_i = (PEC11R_DW.c_i + 1.0) - 2.0 * (real_T)
      PEC11R_B.DigitalPortRead_k;
  }

  PEC11R_B.y_p = PEC11R_DW.c_i;

  /* MATLAB Function: '<Root>/x4' */
  if (rtb_FixPtRelationalOperator && (PEC11R_DW.stageA != 0.0)) {
    PEC11R_DW.stageA = 0.0;
    PEC11R_DW.c = (2.0 * (real_T)PEC11R_B.DigitalPortRead_k + PEC11R_DW.c) - 1.0;
  } else if (PEC11R_B.DigitalPortRead_kx && (!(PEC11R_DW.stageA != 0.0))) {
    PEC11R_DW.stageA = 1.0;
    PEC11R_DW.c = (PEC11R_DW.c + 1.0) - 2.0 * (real_T)PEC11R_B.DigitalPortRead_k;
  }

  if ((!PEC11R_B.DigitalPortRead_k) && (PEC11R_DW.stageB != 0.0)) {
    PEC11R_DW.stageB = 0.0;
    PEC11R_DW.c = (2.0 * (real_T)rtb_FixPtRelationalOperator + PEC11R_DW.c) -
      1.0;
  } else if (PEC11R_B.DigitalPortRead_k && (!(PEC11R_DW.stageB != 0.0))) {
    PEC11R_DW.stageB = 1.0;
    PEC11R_DW.c = (2.0 * (real_T)PEC11R_B.DigitalPortRead_kx + PEC11R_DW.c) -
      1.0;
  }

  PEC11R_B.y = PEC11R_DW.c;

  /* Update for UnitDelay: '<S1>/Delay Input1' incorporates:
   *  RelationalOperator: '<S13>/Compare'
   *
   * Block description for '<S1>/Delay Input1':
   *
   *  Store in Global RAM
   */
  PEC11R_DW.DelayInput1_DSTATE = PEC11R_B.DigitalPortRead;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  PEC11R_M->Timing.taskTime0 =
    ((time_T)(++PEC11R_M->Timing.clockTick0)) * PEC11R_M->Timing.stepSize0;
}

/* Model initialize function */
void PEC11R_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(PEC11R_M, 10.0);
  PEC11R_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  PEC11R_M->Sizes.checksums[0] = (481398498U);
  PEC11R_M->Sizes.checksums[1] = (637467848U);
  PEC11R_M->Sizes.checksums[2] = (2899143361U);
  PEC11R_M->Sizes.checksums[3] = (283113094U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[14];
    PEC11R_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PEC11R_M->extModeInfo,
      &PEC11R_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PEC11R_M->extModeInfo, PEC11R_M->Sizes.checksums);
    rteiSetTPtr(PEC11R_M->extModeInfo, rtmGetTPtr(PEC11R_M));
  }

  /* SystemInitialize for MATLAB Function: '<Root>/x1' */
  PEC11R_DW.stageA_m = 1.0;

  /* SystemInitialize for MATLAB Function: '<Root>/x2' */
  PEC11R_DW.stageA_a = 1.0;

  /* SystemInitialize for MATLAB Function: '<Root>/x4' */
  PEC11R_DW.stageA = 1.0;
  PEC11R_DW.stageB = 1.0;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  PEC11R_DW.obj_g.isInitialized = 0;
  PEC11R_DW.obj_g.matlabCodegenIsDeleted = false;
  PEC11R_SystemCore_setup(&PEC11R_DW.obj_g);

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  PEC11R_DW.obj_l.isInitialized = 0;
  PEC11R_DW.obj_l.matlabCodegenIsDeleted = false;
  PEC11R_SystemCore_setup_k(&PEC11R_DW.obj_l);

  /* Start for MATLABSystem: '<Root>/Encoder2' */
  PEC11R_DW.obj.isInitialized = 0;
  PEC11R_DW.obj.matlabCodegenIsDeleted = false;
  PEC11R_SystemCore_setup_ks(&PEC11R_DW.obj);
}

/* Model terminate function */
void PEC11R_terminate(void)
{
  uint8_T ChannelInfo;

  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!PEC11R_DW.obj_g.matlabCodegenIsDeleted) {
    PEC11R_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((PEC11R_DW.obj_g.isInitialized == 1) && PEC11R_DW.obj_g.isSetupComplete)
    {
      disableCounter(PEC11R_DW.obj_g.TimerHandle);
      disableTimerInterrupts(PEC11R_DW.obj_g.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(PEC11R_DW.obj_g.TimerHandle, ChannelInfo);
      disableTimerChannel2(PEC11R_DW.obj_g.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */
  /* Terminate for MATLABSystem: '<Root>/Encoder1' */
  if (!PEC11R_DW.obj_l.matlabCodegenIsDeleted) {
    PEC11R_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((PEC11R_DW.obj_l.isInitialized == 1) && PEC11R_DW.obj_l.isSetupComplete)
    {
      disableCounter(PEC11R_DW.obj_l.TimerHandle);
      disableTimerInterrupts(PEC11R_DW.obj_l.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(PEC11R_DW.obj_l.TimerHandle, ChannelInfo);
      disableTimerChannel2(PEC11R_DW.obj_l.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder1' */
  /* Terminate for MATLABSystem: '<Root>/Encoder2' */
  if (!PEC11R_DW.obj.matlabCodegenIsDeleted) {
    PEC11R_DW.obj.matlabCodegenIsDeleted = true;
    if ((PEC11R_DW.obj.isInitialized == 1) && PEC11R_DW.obj.isSetupComplete) {
      disableCounter(PEC11R_DW.obj.TimerHandle);
      disableTimerInterrupts(PEC11R_DW.obj.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(PEC11R_DW.obj.TimerHandle, ChannelInfo);
      disableTimerChannel2(PEC11R_DW.obj.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
