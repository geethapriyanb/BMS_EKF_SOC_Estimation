/*
 * SOC_Estimation_using_kalman_filter.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SOC_Estimation_using_kalman_filter".
 *
 * Model version              : 1.3
 * Simulink Coder version : 25.2 (R2025b) 28-Jul-2025
 * C source code generated on : Sat Feb 14 14:12:25 2026
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#ifndef SOC_Estimation_using_kalman_filter_h_
#define SOC_Estimation_using_kalman_filter_h_
#ifndef SOC_Estimation_using_kalman_filter_COMMON_INCLUDES_
#define SOC_Estimation_using_kalman_filter_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                 /* SOC_Estimation_using_kalman_filter_COMMON_INCLUDES_ */

#include "SOC_Estimation_using_kalman_filter_types.h"
#include <float.h>
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#define SOC_Estimation_using_kalman_filter_M (SOC_Estimation_using_kalman__M)

/* Block signals (default storage) */
typedef struct {
  real_T TrueSOC;                      /* '<Root>/Integrator' */
  real_T EKFEstimate;                  /* '<Root>/Unit Delay' */
  real_T Error;                        /* '<Root>/Error' */
  real_T Current;                      /* '<Root>/Pulse Generator' */
  real_T uDLookupTable;                /* '<Root>/1-D Lookup Table' */
  real_T uDLookupTable1;               /* '<Root>/1-D Lookup Table1' */
  real_T InternalFrictionPolarization;
                                 /* '<Root>/Internal Friction (Polarization)' */
  real_T InternalResistance;           /* '<Root>/Internal Resistance' */
  real_T Add;                          /* '<Root>/Add' */
  real_T AmpstoSOC;                    /* '<Root>/Amps to SOC' */
  real_T DiscretetimeofRCCircuit;     /* '<Root>/Discrete time of RC Circuit' */
  real_T UnitDelay1;                   /* '<Root>/Unit Delay1' */
  real_T Gain4;                        /* '<Root>/Gain4' */
  real_T Internalresistance;           /* '<Root>/Internal resistance' */
  real_T SOCDrop;                      /* '<Root>/SOC Drop ' */
  real_T Sum2;                         /* '<Root>/Sum2' */
  real_T Sum3;                         /* '<Root>/Sum3' */
  real_T SOCKalmangain;                /* '<Root>/SOC Kalman gain' */
  real_T Sum;                          /* '<Root>/Sum' */
  real_T Voltagekalmangain;            /* '<Root>/Voltage kalman gain' */
  real_T Sum1;                         /* '<Root>/Sum1' */
} B_SOC_Estimation_using_kalman_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<Root>/Unit Delay1' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} DW_SOC_Estimation_using_kalma_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T InternalFrictionPolarization_CS;
                                 /* '<Root>/Internal Friction (Polarization)' */
} X_SOC_Estimation_using_kalman_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T InternalFrictionPolarization_CS;
                                 /* '<Root>/Internal Friction (Polarization)' */
} XDot_SOC_Estimation_using_kal_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
  boolean_T InternalFrictionPolarization_CS;
                                 /* '<Root>/Internal Friction (Polarization)' */
} XDis_SOC_Estimation_using_kal_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_SOC_Estimation_using_kalman_T_ {
  real_T Integrator_IC;                /* Expression: 1
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0.5
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 2
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<Root>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<Root>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T uDLookupTable_tableData[6];   /* Expression: [3, 3.2, 3.5, 3.8, 4, 4.2]
                                        * Referenced by: '<Root>/1-D Lookup Table'
                                        */
  real_T uDLookupTable_bp01Data[6];    /* Expression: [0, 0.2, 0.4, 0.6, 0.8, 1]
                                        * Referenced by: '<Root>/1-D Lookup Table'
                                        */
  real_T uDLookupTable1_tableData[6];  /* Expression: [3, 3.2, 3.5, 3.8, 4, 4.2]
                                        * Referenced by: '<Root>/1-D Lookup Table1'
                                        */
  real_T uDLookupTable1_bp01Data[6];   /* Expression: [0, 0.2, 0.4, 0.6, 0.8, 1]
                                        * Referenced by: '<Root>/1-D Lookup Table1'
                                        */
  real_T InternalFrictionPolarization_A;
                           /* Computed Parameter: InternalFrictionPolarization_A
                            * Referenced by: '<Root>/Internal Friction (Polarization)'
                            */
  real_T InternalFrictionPolarization_C;
                           /* Computed Parameter: InternalFrictionPolarization_C
                            * Referenced by: '<Root>/Internal Friction (Polarization)'
                            */
  real_T InternalResistance_Gain;      /* Expression: 0.05
                                        * Referenced by: '<Root>/Internal Resistance'
                                        */
  real_T AmpstoSOC_Gain;               /* Expression: -1/7200
                                        * Referenced by: '<Root>/Amps to SOC'
                                        */
  real_T DiscretetimeofRCCircuit_Gain; /* Expression: 0.01*(1-exp(-0.1/20))
                                        * Referenced by: '<Root>/Discrete time of RC Circuit'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay1'
                                        */
  real_T Gain4_Gain;                   /* Expression: exp(-0.1/20)
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T Internalresistance_Gain;      /* Expression: 0.05
                                        * Referenced by: '<Root>/Internal resistance'
                                        */
  real_T SOCDrop_Gain;                 /* Expression: -0.1/7200
                                        * Referenced by: '<Root>/SOC Drop '
                                        */
  real_T SOCKalmangain_Gain;           /* Expression: 0.5
                                        * Referenced by: '<Root>/SOC Kalman gain'
                                        */
  real_T Voltagekalmangain_Gain;       /* Expression: -0.1
                                        * Referenced by: '<Root>/Voltage kalman gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_SOC_Estimation_using__T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_SOC_Estimation_using_kalman_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_SOC_Estimation_using_kal_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tStart;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_SOC_Estimation_using_kalman_T SOC_Estimation_using_kalman_f_P;

/* Block signals (default storage) */
extern B_SOC_Estimation_using_kalman_T SOC_Estimation_using_kalman_f_B;

/* Continuous states (default storage) */
extern X_SOC_Estimation_using_kalman_T SOC_Estimation_using_kalman_f_X;

/* Disabled states (default storage) */
extern XDis_SOC_Estimation_using_kal_T SOC_Estimation_using_kalma_XDis;

/* Block states (default storage) */
extern DW_SOC_Estimation_using_kalma_T SOC_Estimation_using_kalman__DW;

/* Model entry point functions */
extern void SOC_Estimation_using_kalman_filter_initialize(void);
extern void SOC_Estimation_using_kalman_filter_step(void);
extern void SOC_Estimation_using_kalman_filter_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SOC_Estimation_using_T *const SOC_Estimation_using_kalman__M;

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
 * '<Root>' : 'SOC_Estimation_using_kalman_filter'
 */
#endif                               /* SOC_Estimation_using_kalman_filter_h_ */
