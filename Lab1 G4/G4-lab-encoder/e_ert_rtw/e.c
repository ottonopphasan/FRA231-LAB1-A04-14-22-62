/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: e.c
 *
 * Code generated for Simulink model 'e'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Oct 31 01:16:38 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "e.h"
#include "e_types.h"
#include "e_private.h"
#include "rtwtypes.h"
#include "stm_timer_ll.h"

/* Block signals (default storage) */
B_e_T e_B;

/* Block states (default storage) */
DW_e_T e_DW;

/* Real-time model */
static RT_MODEL_e_T e_M_;
RT_MODEL_e_T *const e_M = &e_M_;

/* Forward declaration for local functions */
static void e_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj);
static void e_SystemCore_setup_b(stm32cube_blocks_EncoderBlock_T *obj);
static void e_SystemCore_setup_bh(stm32cube_blocks_EncoderBlock_T *obj);

/* System initialize for atomic system: */
void e_DigitalPortRead_Init(DW_DigitalPortRead_e_T *localDW)
{
  /* Start for MATLABSystem: '<S20>/Digital Port Read' */
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
}

/* Output and update for atomic system: */
void e_DigitalPortRead(B_DigitalPortRead_e_T *localB)
{
  uint32_T pinReadLoc;

  /* MATLABSystem: '<S20>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

  /* MATLABSystem: '<S20>/Digital Port Read' */
  localB->DigitalPortRead = ((pinReadLoc & 8192U) != 0U);
}

static void e_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj)
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

static void e_SystemCore_setup_b(stm32cube_blocks_EncoderBlock_T *obj)
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

static void e_SystemCore_setup_bh(stm32cube_blocks_EncoderBlock_T *obj)
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
void e_step(void)
{
  real_T tmp;
  uint32_T timerCounts;
  boolean_T rtb_FixPtRelationalOperator;
  boolean_T tmp_0;

  /* MATLABSystem: '<Root>/Encoder' */
  e_B.Encoder = getTimerCounterValueForG4(e_DW.obj_g.TimerHandle, false, NULL);
  e_DigitalPortRead(&e_B.DigitalPortRead_l);

  /* RelationalOperator: '<S1>/FixPt Relational Operator' incorporates:
   *  RelationalOperator: '<S13>/Compare'
   *  UnitDelay: '<S1>/Delay Input1'
   *
   * Block description for '<S1>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator = ((int32_T)e_B.DigitalPortRead_l.DigitalPortRead >
    (int32_T)e_DW.DelayInput1_DSTATE);

  /* MATLAB Function: '<Root>/MATLAB Function2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  if (e_B.Encoder > e_DW.lastpulse_g) {
    if ((real_T)e_B.Encoder - e_DW.lastpulse_g > 10000.0) {
      e_DW.pulse_f -= 65520.0 - (real_T)e_B.Encoder;
    } else {
      e_DW.pulse_f += (real_T)e_B.Encoder - e_DW.lastpulse_g;
    }
  } else if (e_B.Encoder < e_DW.lastpulse_g) {
    if (e_DW.lastpulse_g - (real_T)e_B.Encoder > 10000.0) {
      e_DW.pulse_f += (real_T)e_B.Encoder;
    } else {
      e_DW.pulse_f -= e_DW.lastpulse_g - (real_T)e_B.Encoder;
    }
  }

  if (rtb_FixPtRelationalOperator) {
    e_DW.home_m = e_DW.pulse_f;
  }

  e_B.plu_d = e_DW.pulse_f - e_DW.home_m;
  e_B.out_n = e_B.plu_d * 0.26179938779914941;
  e_B.v_h = (e_DW.pulse_f * 0.26179938779914941 - e_DW.lastrad_k) / 0.1;
  e_DW.lastpulse_g = e_B.Encoder;
  e_DW.lastrad_k = e_DW.pulse_f * 0.26179938779914941;

  /* End of MATLAB Function: '<Root>/MATLAB Function2' */
  /* MATLABSystem: '<Root>/Encoder1' */
  timerCounts = getTimerCounterValueForG4(e_DW.obj_l.TimerHandle, false, NULL);

  /* MATLAB Function: '<Root>/MATLAB Function3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  MATLABSystem: '<Root>/Encoder1'
   */
  if (timerCounts > e_DW.lastpulse) {
    tmp = (real_T)timerCounts - e_DW.lastpulse;
    if (tmp > 10000.0) {
      e_DW.pulse -= 65520.0 - (real_T)timerCounts;
    } else {
      e_DW.pulse += tmp;
    }
  } else if (timerCounts < e_DW.lastpulse) {
    tmp = e_DW.lastpulse - (real_T)timerCounts;
    if (tmp > 10000.0) {
      e_DW.pulse += (real_T)timerCounts;
    } else {
      e_DW.pulse -= tmp;
    }
  }

  if (rtb_FixPtRelationalOperator) {
    e_DW.home = e_DW.pulse;
  }

  e_B.plu = e_DW.pulse - e_DW.home;
  e_B.out = e_B.plu * 0.1308996938995747;
  e_B.v = (e_DW.pulse * 0.1308996938995747 - e_DW.lastrad) / 0.1;
  e_DW.lastpulse = timerCounts;
  e_DW.lastrad = e_DW.pulse * 0.1308996938995747;

  /* End of MATLAB Function: '<Root>/MATLAB Function3' */
  /* MATLABSystem: '<Root>/Encoder2' */
  timerCounts = getTimerCounterValueForG4(e_DW.obj.TimerHandle, false, NULL);

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  MATLABSystem: '<Root>/Encoder2'
   */
  if (timerCounts > e_DW.lastpulse_l) {
    tmp = (real_T)timerCounts - e_DW.lastpulse_l;
    if (tmp > 10000.0) {
      e_DW.pulse_h -= 65472.0 - (real_T)timerCounts;
    } else {
      e_DW.pulse_h += tmp;
    }
  } else if (timerCounts < e_DW.lastpulse_l) {
    tmp = e_DW.lastpulse_l - (real_T)timerCounts;
    if (tmp > 10000.0) {
      e_DW.pulse_h += (real_T)timerCounts;
    } else {
      e_DW.pulse_h -= tmp;
    }
  }

  if (rtb_FixPtRelationalOperator) {
    e_DW.home_e = e_DW.pulse_h;
  }

  e_B.plu_l = e_DW.pulse_h - e_DW.home_e;
  e_B.out_c = e_B.plu_l * 0.065449846949787352;
  e_B.v_j = (e_DW.pulse_h * 0.065449846949787352 - e_DW.lastrad_b) / 0.1;
  e_DW.lastpulse_l = timerCounts;
  e_DW.lastrad_b = e_DW.pulse_h * 0.065449846949787352;

  /* End of MATLAB Function: '<Root>/MATLAB Function1' */
  e_DigitalPortRead(&e_B.DigitalPortRead_d);

  /* RelationalOperator: '<S2>/FixPt Relational Operator' incorporates:
   *  RelationalOperator: '<S14>/Compare'
   *  UnitDelay: '<S2>/Delay Input1'
   *
   * Block description for '<S2>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator = ((int32_T)e_B.DigitalPortRead_d.DigitalPortRead >
    (int32_T)e_DW.DelayInput1_DSTATE_e);

  /* MATLABSystem: '<S16>/Digital Port Read' */
  timerCounts = LL_GPIO_ReadInputPort(GPIOB);

  /* MATLABSystem: '<S16>/Digital Port Read' */
  e_B.DigitalPortRead_k = ((timerCounts & 16U) != 0U);

  /* MATLABSystem: '<S18>/Digital Port Read' */
  timerCounts = LL_GPIO_ReadInputPort(GPIOB);

  /* MATLABSystem: '<S18>/Digital Port Read' */
  e_B.DigitalPortRead = ((timerCounts & 32U) != 0U);

  /* MATLAB Function: '<Root>/x1' incorporates:
   *  MATLAB Function: '<Root>/x2'
   *  MATLAB Function: '<Root>/x4'
   */
  if (rtb_FixPtRelationalOperator) {
    e_DW.c_n = 0.0;
  }

  tmp_0 = !e_B.DigitalPortRead_k;
  if (tmp_0 && (e_DW.stageA_m == 1.0)) {
    e_DW.stageA_m = 0.0;
    if (e_B.DigitalPortRead) {
      e_DW.c_n++;
    } else {
      e_DW.c_n--;
    }
  } else if (e_B.DigitalPortRead_k) {
    e_DW.stageA_m = 1.0;
  }

  e_B.y_o = e_DW.c_n;

  /* End of MATLAB Function: '<Root>/x1' */
  /* MATLAB Function: '<Root>/x2' */
  if (rtb_FixPtRelationalOperator) {
    e_DW.c_i = 0.0;
  }

  if (tmp_0 && (e_DW.stageA_a == 1.0)) {
    e_DW.stageA_a = 0.0;
    if (e_B.DigitalPortRead) {
      e_DW.c_i++;
    } else {
      e_DW.c_i--;
    }
  } else if (e_B.DigitalPortRead_k && (e_DW.stageA_a == 0.0)) {
    e_DW.stageA_a = 1.0;
    if (!e_B.DigitalPortRead) {
      e_DW.c_i++;
    } else {
      e_DW.c_i--;
    }
  }

  e_B.y_p = e_DW.c_i;

  /* MATLAB Function: '<Root>/x4' */
  if (rtb_FixPtRelationalOperator) {
    e_DW.c = 0.0;
  }

  if (tmp_0 && (e_DW.stageA == 1.0)) {
    e_DW.stageA = 0.0;
    if (e_B.DigitalPortRead) {
      e_DW.c++;
    } else {
      e_DW.c--;
    }
  } else if (e_B.DigitalPortRead_k && (e_DW.stageA == 0.0)) {
    e_DW.stageA = 1.0;
    if (!e_B.DigitalPortRead) {
      e_DW.c++;
    } else {
      e_DW.c--;
    }
  }

  if ((!e_B.DigitalPortRead) && (e_DW.stageB == 1.0)) {
    e_DW.stageB = 0.0;
    if (!e_B.DigitalPortRead_k) {
      e_DW.c++;
    } else {
      e_DW.c--;
    }
  } else if (e_B.DigitalPortRead && (e_DW.stageB == 0.0)) {
    e_DW.stageB = 1.0;
    if (e_B.DigitalPortRead_k) {
      e_DW.c++;
    } else {
      e_DW.c--;
    }
  }

  e_B.y = e_DW.c;

  /* Update for UnitDelay: '<S1>/Delay Input1' incorporates:
   *  RelationalOperator: '<S13>/Compare'
   *
   * Block description for '<S1>/Delay Input1':
   *
   *  Store in Global RAM
   */
  e_DW.DelayInput1_DSTATE = e_B.DigitalPortRead_l.DigitalPortRead;

  /* Update for UnitDelay: '<S2>/Delay Input1' incorporates:
   *  RelationalOperator: '<S14>/Compare'
   *
   * Block description for '<S2>/Delay Input1':
   *
   *  Store in Global RAM
   */
  e_DW.DelayInput1_DSTATE_e = e_B.DigitalPortRead_d.DigitalPortRead;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  e_M->Timing.taskTime0 =
    ((time_T)(++e_M->Timing.clockTick0)) * e_M->Timing.stepSize0;
}

/* Model initialize function */
void e_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(e_M, -1);
  e_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  e_M->Sizes.checksums[0] = (2814741144U);
  e_M->Sizes.checksums[1] = (785077957U);
  e_M->Sizes.checksums[2] = (3463624952U);
  e_M->Sizes.checksums[3] = (4285149158U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[14];
    e_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(e_M->extModeInfo, &e_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(e_M->extModeInfo, e_M->Sizes.checksums);
    rteiSetTPtr(e_M->extModeInfo, rtmGetTPtr(e_M));
  }

  /* SystemInitialize for MATLAB Function: '<Root>/x1' */
  e_DW.stageA_m = 1.0;

  /* SystemInitialize for MATLAB Function: '<Root>/x2' */
  e_DW.stageA_a = 1.0;

  /* SystemInitialize for MATLAB Function: '<Root>/x4' */
  e_DW.stageA = 1.0;
  e_DW.stageB = 1.0;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  e_DW.obj_g.isInitialized = 0;
  e_DW.obj_g.matlabCodegenIsDeleted = false;
  e_SystemCore_setup(&e_DW.obj_g);
  e_DigitalPortRead_Init(&e_DW.DigitalPortRead_l);

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  e_DW.obj_l.isInitialized = 0;
  e_DW.obj_l.matlabCodegenIsDeleted = false;
  e_SystemCore_setup_b(&e_DW.obj_l);

  /* Start for MATLABSystem: '<Root>/Encoder2' */
  e_DW.obj.isInitialized = 0;
  e_DW.obj.matlabCodegenIsDeleted = false;
  e_SystemCore_setup_bh(&e_DW.obj);
  e_DigitalPortRead_Init(&e_DW.DigitalPortRead_d);
}

/* Model terminate function */
void e_terminate(void)
{
  uint8_T ChannelInfo;

  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!e_DW.obj_g.matlabCodegenIsDeleted) {
    e_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((e_DW.obj_g.isInitialized == 1) && e_DW.obj_g.isSetupComplete) {
      disableCounter(e_DW.obj_g.TimerHandle);
      disableTimerInterrupts(e_DW.obj_g.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(e_DW.obj_g.TimerHandle, ChannelInfo);
      disableTimerChannel2(e_DW.obj_g.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */
  /* Terminate for MATLABSystem: '<Root>/Encoder1' */
  if (!e_DW.obj_l.matlabCodegenIsDeleted) {
    e_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((e_DW.obj_l.isInitialized == 1) && e_DW.obj_l.isSetupComplete) {
      disableCounter(e_DW.obj_l.TimerHandle);
      disableTimerInterrupts(e_DW.obj_l.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(e_DW.obj_l.TimerHandle, ChannelInfo);
      disableTimerChannel2(e_DW.obj_l.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder1' */
  /* Terminate for MATLABSystem: '<Root>/Encoder2' */
  if (!e_DW.obj.matlabCodegenIsDeleted) {
    e_DW.obj.matlabCodegenIsDeleted = true;
    if ((e_DW.obj.isInitialized == 1) && e_DW.obj.isSetupComplete) {
      disableCounter(e_DW.obj.TimerHandle);
      disableTimerInterrupts(e_DW.obj.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(e_DW.obj.TimerHandle, ChannelInfo);
      disableTimerChannel2(e_DW.obj.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
