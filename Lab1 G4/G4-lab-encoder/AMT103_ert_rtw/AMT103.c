/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AMT103.c
 *
 * Code generated for Simulink model 'AMT103'.
 *
 * Model version                  : 1.44
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Oct 31 18:14:57 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AMT103.h"
#include "AMT103_types.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "stm_timer_ll.h"
#include "AMT103_private.h"

/* Block signals (default storage) */
B_AMT103_T AMT103_B;

/* Block states (default storage) */
DW_AMT103_T AMT103_DW;

/* Real-time model */
static RT_MODEL_AMT103_T AMT103_M_;
RT_MODEL_AMT103_T *const AMT103_M = &AMT103_M_;

/* Forward declaration for local functions */
static void AMT103_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj);
static void AMT103_SystemCore_setup_j(stm32cube_blocks_EncoderBlock_T *obj);
static void AMT103_SystemCore_setup_ja(stm32cube_blocks_EncoderBlock_T *obj);
static void AMT103_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj)
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

static void AMT103_SystemCore_setup_j(stm32cube_blocks_EncoderBlock_T *obj)
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

static void AMT103_SystemCore_setup_ja(stm32cube_blocks_EncoderBlock_T *obj)
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
void AMT103_step(void)
{
  real_T pulse_diff;
  real_T tmp;
  uint32_T pinReadLoc;
  boolean_T rtb_FixPtRelationalOperator;

  /* MATLABSystem: '<Root>/Encoder' */
  AMT103_B.RowSig = getTimerCounterValueForG4(AMT103_DW.obj_g.TimerHandle, false,
    NULL);

  /* MATLABSystem: '<S17>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

  /* MATLABSystem: '<S17>/Digital Port Read' */
  AMT103_B.DigitalPortRead = ((pinReadLoc & 8192U) != 0U);

  /* RelationalOperator: '<S1>/FixPt Relational Operator' incorporates:
   *  RelationalOperator: '<S11>/Compare'
   *  UnitDelay: '<S1>/Delay Input1'
   *
   * Block description for '<S1>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator = ((int32_T)AMT103_B.DigitalPortRead > (int32_T)
    AMT103_DW.DelayInput1_DSTATE);

  /* MATLAB Function: '<Root>/MATLAB Function5' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  pulse_diff = (real_T)AMT103_B.RowSig - AMT103_DW.lastpulse_o;
  if (fabs(pulse_diff) > 10000.0) {
    if (rtIsNaN(pulse_diff)) {
      tmp = (rtNaN);
    } else if (pulse_diff < 0.0) {
      tmp = -1.0;
    } else {
      tmp = (pulse_diff > 0.0);
    }

    AMT103_DW.pulse_p += 2064.67 * tmp - pulse_diff;
  } else {
    AMT103_DW.pulse_p += pulse_diff;
  }

  if (rtb_FixPtRelationalOperator) {
    AMT103_DW.home_position_o = AMT103_DW.pulse_p;
  }

  AMT103_B.pul_c = AMT103_DW.pulse_p - AMT103_DW.home_position_o;
  AMT103_B.pos_h = AMT103_B.pul_c * 0.26179938779914941;
  AMT103_B.velo_e = (AMT103_B.pos_h - AMT103_DW.lastrad_a) / 0.1;
  AMT103_DW.lastpulse_o = AMT103_B.RowSig;
  AMT103_DW.lastrad_a = AMT103_B.pos_h;

  /* End of MATLAB Function: '<Root>/MATLAB Function5' */
  /* MATLABSystem: '<Root>/Encoder1' */
  pinReadLoc = getTimerCounterValueForG4(AMT103_DW.obj_l.TimerHandle, false,
    NULL);

  /* MATLAB Function: '<Root>/MATLAB Function6' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  MATLABSystem: '<Root>/Encoder1'
   */
  pulse_diff = (real_T)pinReadLoc - AMT103_DW.lastpulse;
  if (fabs(pulse_diff) > 10000.0) {
    if (rtIsNaN(pulse_diff)) {
      tmp = (rtNaN);
    } else if (pulse_diff < 0.0) {
      tmp = -1.0;
    } else {
      tmp = (pulse_diff > 0.0);
    }

    AMT103_DW.pulse += 4129.34 * tmp - pulse_diff;
  } else {
    AMT103_DW.pulse += pulse_diff;
  }

  if (rtb_FixPtRelationalOperator) {
    AMT103_DW.home_position = AMT103_DW.pulse;
  }

  AMT103_B.pul = AMT103_DW.pulse - AMT103_DW.home_position;
  AMT103_B.pos = AMT103_B.pul * 0.1308996938995747;
  AMT103_B.velo = (AMT103_B.pos - AMT103_DW.lastrad) / 0.1;
  AMT103_DW.lastpulse = pinReadLoc;
  AMT103_DW.lastrad = AMT103_B.pos;

  /* End of MATLAB Function: '<Root>/MATLAB Function6' */
  /* MATLABSystem: '<Root>/Encoder2' */
  pinReadLoc = getTimerCounterValueForG4(AMT103_DW.obj.TimerHandle, false, NULL);

  /* MATLAB Function: '<Root>/MATLAB Function4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  MATLABSystem: '<Root>/Encoder2'
   */
  pulse_diff = (real_T)pinReadLoc - AMT103_DW.lastpulse_b;
  if (fabs(pulse_diff) > 10000.0) {
    if (rtIsNaN(pulse_diff)) {
      tmp = (rtNaN);
    } else if (pulse_diff < 0.0) {
      tmp = -1.0;
    } else {
      tmp = (pulse_diff > 0.0);
    }

    AMT103_DW.pulse_g += 8258.68 * tmp - pulse_diff;
  } else {
    AMT103_DW.pulse_g += pulse_diff;
  }

  if (rtb_FixPtRelationalOperator) {
    AMT103_DW.home_position_d = AMT103_DW.pulse_g;
  }

  AMT103_B.pul_cw = AMT103_DW.pulse_g - AMT103_DW.home_position_d;
  AMT103_B.pos_a = AMT103_B.pul_cw * 0.065449846949787352;
  AMT103_B.velo_d = (AMT103_B.pos_a - AMT103_DW.lastrad_l) / 0.1;
  AMT103_DW.lastpulse_b = pinReadLoc;
  AMT103_DW.lastrad_l = AMT103_B.pos_a;

  /* End of MATLAB Function: '<Root>/MATLAB Function4' */
  /* MATLABSystem: '<S13>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

  /* MATLABSystem: '<S13>/Digital Port Read' */
  AMT103_B.DigitalPortRead_kx = ((pinReadLoc & 16U) != 0U);

  /* MATLABSystem: '<S15>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

  /* MATLABSystem: '<S15>/Digital Port Read' */
  AMT103_B.DigitalPortRead_k = ((pinReadLoc & 32U) != 0U);

  /* MATLAB Function: '<Root>/x1' incorporates:
   *  MATLAB Function: '<Root>/x2'
   *  MATLAB Function: '<Root>/x4'
   */
  rtb_FixPtRelationalOperator = !AMT103_B.DigitalPortRead_kx;
  if (rtb_FixPtRelationalOperator && (AMT103_DW.stageA_m != 0.0)) {
    AMT103_DW.stageA_m = 0.0;
    AMT103_DW.c_n = (2.0 * (real_T)AMT103_B.DigitalPortRead_k + AMT103_DW.c_n) -
      1.0;
  } else if (AMT103_B.DigitalPortRead_kx) {
    AMT103_DW.stageA_m = 1.0;
  }

  AMT103_B.y_o = AMT103_DW.c_n;

  /* End of MATLAB Function: '<Root>/x1' */
  /* MATLAB Function: '<Root>/x2' */
  if (rtb_FixPtRelationalOperator && (AMT103_DW.stageA_a != 0.0)) {
    AMT103_DW.stageA_a = 0.0;
    AMT103_DW.c_i = (2.0 * (real_T)AMT103_B.DigitalPortRead_k + AMT103_DW.c_i) -
      1.0;
  } else if (AMT103_B.DigitalPortRead_kx && (!(AMT103_DW.stageA_a != 0.0))) {
    AMT103_DW.stageA_a = 1.0;
    AMT103_DW.c_i = (AMT103_DW.c_i + 1.0) - 2.0 * (real_T)
      AMT103_B.DigitalPortRead_k;
  }

  AMT103_B.y_p = AMT103_DW.c_i;

  /* MATLAB Function: '<Root>/x4' */
  if (rtb_FixPtRelationalOperator && (AMT103_DW.stageA == 1.0)) {
    AMT103_DW.stageA = 0.0;
    if (AMT103_B.DigitalPortRead_k) {
      AMT103_DW.c++;
    } else {
      AMT103_DW.c--;
    }
  } else if (AMT103_B.DigitalPortRead_kx && (AMT103_DW.stageA == 0.0)) {
    AMT103_DW.stageA = 1.0;
    if (!AMT103_B.DigitalPortRead_k) {
      AMT103_DW.c++;
    } else {
      AMT103_DW.c--;
    }
  }

  if ((!AMT103_B.DigitalPortRead_k) && (AMT103_DW.stageB == 1.0)) {
    AMT103_DW.stageB = 0.0;
    if (rtb_FixPtRelationalOperator) {
      AMT103_DW.c++;
    } else {
      AMT103_DW.c--;
    }
  } else if (AMT103_B.DigitalPortRead_k && (AMT103_DW.stageB == 0.0)) {
    AMT103_DW.stageB = 1.0;
    if (AMT103_B.DigitalPortRead_kx) {
      AMT103_DW.c++;
    } else {
      AMT103_DW.c--;
    }
  }

  AMT103_B.y = AMT103_DW.c;

  /* Update for UnitDelay: '<S1>/Delay Input1' incorporates:
   *  RelationalOperator: '<S11>/Compare'
   *
   * Block description for '<S1>/Delay Input1':
   *
   *  Store in Global RAM
   */
  AMT103_DW.DelayInput1_DSTATE = AMT103_B.DigitalPortRead;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  AMT103_M->Timing.taskTime0 =
    ((time_T)(++AMT103_M->Timing.clockTick0)) * AMT103_M->Timing.stepSize0;
}

/* Model initialize function */
void AMT103_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(AMT103_M, -1);
  AMT103_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  AMT103_M->Sizes.checksums[0] = (4196041323U);
  AMT103_M->Sizes.checksums[1] = (1176289201U);
  AMT103_M->Sizes.checksums[2] = (260223167U);
  AMT103_M->Sizes.checksums[3] = (2114933501U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[13];
    AMT103_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(AMT103_M->extModeInfo,
      &AMT103_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(AMT103_M->extModeInfo, AMT103_M->Sizes.checksums);
    rteiSetTPtr(AMT103_M->extModeInfo, rtmGetTPtr(AMT103_M));
  }

  /* SystemInitialize for MATLAB Function: '<Root>/x1' */
  AMT103_DW.stageA_m = 1.0;

  /* SystemInitialize for MATLAB Function: '<Root>/x2' */
  AMT103_DW.stageA_a = 1.0;

  /* SystemInitialize for MATLAB Function: '<Root>/x4' */
  AMT103_DW.stageA = 1.0;
  AMT103_DW.stageB = 1.0;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  AMT103_DW.obj_g.isInitialized = 0;
  AMT103_DW.obj_g.matlabCodegenIsDeleted = false;
  AMT103_SystemCore_setup(&AMT103_DW.obj_g);

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  AMT103_DW.obj_l.isInitialized = 0;
  AMT103_DW.obj_l.matlabCodegenIsDeleted = false;
  AMT103_SystemCore_setup_j(&AMT103_DW.obj_l);

  /* Start for MATLABSystem: '<Root>/Encoder2' */
  AMT103_DW.obj.isInitialized = 0;
  AMT103_DW.obj.matlabCodegenIsDeleted = false;
  AMT103_SystemCore_setup_ja(&AMT103_DW.obj);
}

/* Model terminate function */
void AMT103_terminate(void)
{
  uint8_T ChannelInfo;

  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!AMT103_DW.obj_g.matlabCodegenIsDeleted) {
    AMT103_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((AMT103_DW.obj_g.isInitialized == 1) && AMT103_DW.obj_g.isSetupComplete)
    {
      disableCounter(AMT103_DW.obj_g.TimerHandle);
      disableTimerInterrupts(AMT103_DW.obj_g.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(AMT103_DW.obj_g.TimerHandle, ChannelInfo);
      disableTimerChannel2(AMT103_DW.obj_g.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */
  /* Terminate for MATLABSystem: '<Root>/Encoder1' */
  if (!AMT103_DW.obj_l.matlabCodegenIsDeleted) {
    AMT103_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((AMT103_DW.obj_l.isInitialized == 1) && AMT103_DW.obj_l.isSetupComplete)
    {
      disableCounter(AMT103_DW.obj_l.TimerHandle);
      disableTimerInterrupts(AMT103_DW.obj_l.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(AMT103_DW.obj_l.TimerHandle, ChannelInfo);
      disableTimerChannel2(AMT103_DW.obj_l.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder1' */
  /* Terminate for MATLABSystem: '<Root>/Encoder2' */
  if (!AMT103_DW.obj.matlabCodegenIsDeleted) {
    AMT103_DW.obj.matlabCodegenIsDeleted = true;
    if ((AMT103_DW.obj.isInitialized == 1) && AMT103_DW.obj.isSetupComplete) {
      disableCounter(AMT103_DW.obj.TimerHandle);
      disableTimerInterrupts(AMT103_DW.obj.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(AMT103_DW.obj.TimerHandle, ChannelInfo);
      disableTimerChannel2(AMT103_DW.obj.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
