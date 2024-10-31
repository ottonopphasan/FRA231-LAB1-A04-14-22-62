/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PEC11R.h
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

#ifndef PEC11R_h_
#define PEC11R_h_
#ifndef PEC11R_COMMON_INCLUDES_
#define PEC11R_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "main.h"
#endif                                 /* PEC11R_COMMON_INCLUDES_ */

#include "PEC11R_types.h"
#include "rtGetNaN.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T y;                            /* '<Root>/x4' */
  real_T y_p;                          /* '<Root>/x2' */
  real_T y_o;                          /* '<Root>/x1' */
  real_T pos;                          /* '<Root>/MATLAB Function3' */
  real_T velo;                         /* '<Root>/MATLAB Function3' */
  real_T pul;                          /* '<Root>/MATLAB Function3' */
  real_T pos_c;                        /* '<Root>/MATLAB Function2' */
  real_T velo_m;                       /* '<Root>/MATLAB Function2' */
  real_T pul_l;                        /* '<Root>/MATLAB Function2' */
  real_T pos_h;                        /* '<Root>/MATLAB Function1' */
  real_T velo_l;                       /* '<Root>/MATLAB Function1' */
  real_T pul_p;                        /* '<Root>/MATLAB Function1' */
  uint32_T RowSig;                     /* '<Root>/Encoder' */
  boolean_T DigitalPortRead;           /* '<S20>/Digital Port Read' */
  boolean_T DigitalPortRead_k;         /* '<S18>/Digital Port Read' */
  boolean_T DigitalPortRead_kx;        /* '<S16>/Digital Port Read' */
} B_PEC11R_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_EncoderBlock_T obj; /* '<Root>/Encoder2' */
  stm32cube_blocks_EncoderBlock_T obj_l;/* '<Root>/Encoder1' */
  stm32cube_blocks_EncoderBlock_T obj_g;/* '<Root>/Encoder' */
  real_T c;                            /* '<Root>/x4' */
  real_T stageA;                       /* '<Root>/x4' */
  real_T stageB;                       /* '<Root>/x4' */
  real_T c_i;                          /* '<Root>/x2' */
  real_T stageA_a;                     /* '<Root>/x2' */
  real_T c_n;                          /* '<Root>/x1' */
  real_T stageA_m;                     /* '<Root>/x1' */
  real_T pulse;                        /* '<Root>/MATLAB Function3' */
  real_T lastpulse;                    /* '<Root>/MATLAB Function3' */
  real_T lastrad;                      /* '<Root>/MATLAB Function3' */
  real_T home_position;                /* '<Root>/MATLAB Function3' */
  real_T pulse_f;                      /* '<Root>/MATLAB Function2' */
  real_T lastpulse_g;                  /* '<Root>/MATLAB Function2' */
  real_T lastrad_k;                    /* '<Root>/MATLAB Function2' */
  real_T home_position_o;              /* '<Root>/MATLAB Function2' */
  real_T pulse_h;                      /* '<Root>/MATLAB Function1' */
  real_T lastpulse_l;                  /* '<Root>/MATLAB Function1' */
  real_T lastrad_b;                    /* '<Root>/MATLAB Function1' */
  real_T home_position_l;              /* '<Root>/MATLAB Function1' */
  boolean_T DelayInput1_DSTATE;        /* '<S1>/Delay Input1' */
} DW_PEC11R_T;

/* Real-time Model Data Structure */
struct tag_RTM_PEC11R_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (default storage) */
extern B_PEC11R_T PEC11R_B;

/* Block states (default storage) */
extern DW_PEC11R_T PEC11R_DW;

/* Model entry point functions */
extern void PEC11R_initialize(void);
extern void PEC11R_step(void);
extern void PEC11R_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PEC11R_T *const PEC11R_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Delay Input1' : Unused code path elimination
 * Block '<S2>/FixPt Relational Operator' : Unused code path elimination
 * Block '<S14>/Compare' : Unused code path elimination
 * Block '<S14>/Constant' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PEC11R'
 * '<S1>'   : 'PEC11R/Detect Rise Positive'
 * '<S2>'   : 'PEC11R/Detect Rise Positive1'
 * '<S3>'   : 'PEC11R/Digital Port Read'
 * '<S4>'   : 'PEC11R/Digital Port Read1'
 * '<S5>'   : 'PEC11R/Digital Port Read2'
 * '<S6>'   : 'PEC11R/Digital Port Read3'
 * '<S7>'   : 'PEC11R/MATLAB Function1'
 * '<S8>'   : 'PEC11R/MATLAB Function2'
 * '<S9>'   : 'PEC11R/MATLAB Function3'
 * '<S10>'  : 'PEC11R/x1'
 * '<S11>'  : 'PEC11R/x2'
 * '<S12>'  : 'PEC11R/x4'
 * '<S13>'  : 'PEC11R/Detect Rise Positive/Positive'
 * '<S14>'  : 'PEC11R/Detect Rise Positive1/Positive'
 * '<S15>'  : 'PEC11R/Digital Port Read/ECSoC'
 * '<S16>'  : 'PEC11R/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S17>'  : 'PEC11R/Digital Port Read1/ECSoC'
 * '<S18>'  : 'PEC11R/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S19>'  : 'PEC11R/Digital Port Read2/ECSoC'
 * '<S20>'  : 'PEC11R/Digital Port Read2/ECSoC/ECSimCodegen'
 * '<S21>'  : 'PEC11R/Digital Port Read3/ECSoC'
 * '<S22>'  : 'PEC11R/Digital Port Read3/ECSoC/ECSimCodegen'
 */
#endif                                 /* PEC11R_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
