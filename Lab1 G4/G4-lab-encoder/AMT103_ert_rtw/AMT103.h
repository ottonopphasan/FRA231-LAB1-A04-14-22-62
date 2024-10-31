/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AMT103.h
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

#ifndef AMT103_h_
#define AMT103_h_
#ifndef AMT103_COMMON_INCLUDES_
#define AMT103_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "main.h"
#endif                                 /* AMT103_COMMON_INCLUDES_ */

#include "AMT103_types.h"
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
  real_T pos;                          /* '<Root>/MATLAB Function6' */
  real_T velo;                         /* '<Root>/MATLAB Function6' */
  real_T pul;                          /* '<Root>/MATLAB Function6' */
  real_T pos_h;                        /* '<Root>/MATLAB Function5' */
  real_T velo_e;                       /* '<Root>/MATLAB Function5' */
  real_T pul_c;                        /* '<Root>/MATLAB Function5' */
  real_T pos_a;                        /* '<Root>/MATLAB Function4' */
  real_T velo_d;                       /* '<Root>/MATLAB Function4' */
  real_T pul_cw;                       /* '<Root>/MATLAB Function4' */
  uint32_T RowSig;                     /* '<Root>/Encoder' */
  boolean_T DigitalPortRead;           /* '<S17>/Digital Port Read' */
  boolean_T DigitalPortRead_k;         /* '<S15>/Digital Port Read' */
  boolean_T DigitalPortRead_kx;        /* '<S13>/Digital Port Read' */
} B_AMT103_T;

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
  real_T pulse;                        /* '<Root>/MATLAB Function6' */
  real_T lastpulse;                    /* '<Root>/MATLAB Function6' */
  real_T lastrad;                      /* '<Root>/MATLAB Function6' */
  real_T home_position;                /* '<Root>/MATLAB Function6' */
  real_T pulse_p;                      /* '<Root>/MATLAB Function5' */
  real_T lastpulse_o;                  /* '<Root>/MATLAB Function5' */
  real_T lastrad_a;                    /* '<Root>/MATLAB Function5' */
  real_T home_position_o;              /* '<Root>/MATLAB Function5' */
  real_T pulse_g;                      /* '<Root>/MATLAB Function4' */
  real_T lastpulse_b;                  /* '<Root>/MATLAB Function4' */
  real_T lastrad_l;                    /* '<Root>/MATLAB Function4' */
  real_T home_position_d;              /* '<Root>/MATLAB Function4' */
  boolean_T DelayInput1_DSTATE;        /* '<S1>/Delay Input1' */
} DW_AMT103_T;

/* Real-time Model Data Structure */
struct tag_RTM_AMT103_T {
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
extern B_AMT103_T AMT103_B;

/* Block states (default storage) */
extern DW_AMT103_T AMT103_DW;

/* Model entry point functions */
extern void AMT103_initialize(void);
extern void AMT103_step(void);
extern void AMT103_terminate(void);

/* Real-time Model object */
extern RT_MODEL_AMT103_T *const AMT103_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'AMT103'
 * '<S1>'   : 'AMT103/Detect Rise Positive'
 * '<S2>'   : 'AMT103/Digital Port Read'
 * '<S3>'   : 'AMT103/Digital Port Read1'
 * '<S4>'   : 'AMT103/Digital Port Read2'
 * '<S5>'   : 'AMT103/MATLAB Function4'
 * '<S6>'   : 'AMT103/MATLAB Function5'
 * '<S7>'   : 'AMT103/MATLAB Function6'
 * '<S8>'   : 'AMT103/x1'
 * '<S9>'   : 'AMT103/x2'
 * '<S10>'  : 'AMT103/x4'
 * '<S11>'  : 'AMT103/Detect Rise Positive/Positive'
 * '<S12>'  : 'AMT103/Digital Port Read/ECSoC'
 * '<S13>'  : 'AMT103/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S14>'  : 'AMT103/Digital Port Read1/ECSoC'
 * '<S15>'  : 'AMT103/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S16>'  : 'AMT103/Digital Port Read2/ECSoC'
 * '<S17>'  : 'AMT103/Digital Port Read2/ECSoC/ECSimCodegen'
 */
#endif                                 /* AMT103_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
