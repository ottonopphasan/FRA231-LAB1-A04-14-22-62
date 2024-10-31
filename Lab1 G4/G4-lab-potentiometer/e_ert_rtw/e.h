/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: e.h
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

#ifndef e_h_
#define e_h_
#ifndef e_COMMON_INCLUDES_
#define e_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "math.h"
#include "main.h"
#endif                                 /* e_COMMON_INCLUDES_ */

#include "e_types.h"
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

/* Block signals for system '<S20>/Digital Port Read' */
typedef struct {
  boolean_T DigitalPortRead;           /* '<S20>/Digital Port Read' */
} B_DigitalPortRead_e_T;

/* Block states (default storage) for system '<S20>/Digital Port Read' */
typedef struct {
  stm32cube_blocks_DigitalPortR_T obj; /* '<S20>/Digital Port Read' */
  boolean_T objisempty;                /* '<S20>/Digital Port Read' */
} DW_DigitalPortRead_e_T;

/* Block signals (default storage) */
typedef struct {
  real_T y;                            /* '<Root>/x4' */
  real_T y_p;                          /* '<Root>/x2' */
  real_T y_o;                          /* '<Root>/x1' */
  real_T out;                          /* '<Root>/MATLAB Function3' */
  real_T v;                            /* '<Root>/MATLAB Function3' */
  real_T plu;                          /* '<Root>/MATLAB Function3' */
  real_T out_n;                        /* '<Root>/MATLAB Function2' */
  real_T v_h;                          /* '<Root>/MATLAB Function2' */
  real_T plu_d;                        /* '<Root>/MATLAB Function2' */
  real_T out_c;                        /* '<Root>/MATLAB Function1' */
  real_T v_j;                          /* '<Root>/MATLAB Function1' */
  real_T plu_l;                        /* '<Root>/MATLAB Function1' */
  uint32_T Encoder;                    /* '<Root>/Encoder' */
  boolean_T DigitalPortRead;           /* '<S18>/Digital Port Read' */
  boolean_T DigitalPortRead_k;         /* '<S16>/Digital Port Read' */
  B_DigitalPortRead_e_T DigitalPortRead_d;/* '<S20>/Digital Port Read' */
  B_DigitalPortRead_e_T DigitalPortRead_l;/* '<S20>/Digital Port Read' */
} B_e_T;

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
  real_T home;                         /* '<Root>/MATLAB Function3' */
  real_T pulse_f;                      /* '<Root>/MATLAB Function2' */
  real_T lastpulse_g;                  /* '<Root>/MATLAB Function2' */
  real_T lastrad_k;                    /* '<Root>/MATLAB Function2' */
  real_T home_m;                       /* '<Root>/MATLAB Function2' */
  real_T pulse_h;                      /* '<Root>/MATLAB Function1' */
  real_T lastpulse_l;                  /* '<Root>/MATLAB Function1' */
  real_T lastrad_b;                    /* '<Root>/MATLAB Function1' */
  real_T home_e;                       /* '<Root>/MATLAB Function1' */
  boolean_T DelayInput1_DSTATE;        /* '<S1>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_e;      /* '<S2>/Delay Input1' */
  DW_DigitalPortRead_e_T DigitalPortRead_d;/* '<S20>/Digital Port Read' */
  DW_DigitalPortRead_e_T DigitalPortRead_l;/* '<S20>/Digital Port Read' */
} DW_e_T;

/* Real-time Model Data Structure */
struct tag_RTM_e_T {
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
extern B_e_T e_B;

/* Block states (default storage) */
extern DW_e_T e_DW;

/* Model entry point functions */
extern void e_initialize(void);
extern void e_step(void);
extern void e_terminate(void);

/* Real-time Model object */
extern RT_MODEL_e_T *const e_M;
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
 * '<Root>' : 'e'
 * '<S1>'   : 'e/Detect Rise Positive'
 * '<S2>'   : 'e/Detect Rise Positive1'
 * '<S3>'   : 'e/Digital Port Read'
 * '<S4>'   : 'e/Digital Port Read1'
 * '<S5>'   : 'e/Digital Port Read2'
 * '<S6>'   : 'e/Digital Port Read3'
 * '<S7>'   : 'e/MATLAB Function1'
 * '<S8>'   : 'e/MATLAB Function2'
 * '<S9>'   : 'e/MATLAB Function3'
 * '<S10>'  : 'e/x1'
 * '<S11>'  : 'e/x2'
 * '<S12>'  : 'e/x4'
 * '<S13>'  : 'e/Detect Rise Positive/Positive'
 * '<S14>'  : 'e/Detect Rise Positive1/Positive'
 * '<S15>'  : 'e/Digital Port Read/ECSoC'
 * '<S16>'  : 'e/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S17>'  : 'e/Digital Port Read1/ECSoC'
 * '<S18>'  : 'e/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S19>'  : 'e/Digital Port Read2/ECSoC'
 * '<S20>'  : 'e/Digital Port Read2/ECSoC/ECSimCodegen'
 * '<S21>'  : 'e/Digital Port Read3/ECSoC'
 * '<S22>'  : 'e/Digital Port Read3/ECSoC/ECSimCodegen'
 */
#endif                                 /* e_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
