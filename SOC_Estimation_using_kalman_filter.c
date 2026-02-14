/*
 * SOC_Estimation_using_kalman_filter.c
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

#include "SOC_Estimation_using_kalman_filter.h"
#include "rtwtypes.h"
#include "SOC_Estimation_using_kalman_filter_private.h"
#include <string.h>

/* Block signals (default storage) */
B_SOC_Estimation_using_kalman_T SOC_Estimation_using_kalman_f_B;

/* Continuous states */
X_SOC_Estimation_using_kalman_T SOC_Estimation_using_kalman_f_X;

/* Disabled State Vector */
XDis_SOC_Estimation_using_kal_T SOC_Estimation_using_kalma_XDis;

/* Block states (default storage) */
DW_SOC_Estimation_using_kalma_T SOC_Estimation_using_kalman__DW;

/* Real-time model */
static RT_MODEL_SOC_Estimation_using_T SOC_Estimation_using_kalman__M_;
RT_MODEL_SOC_Estimation_using_T *const SOC_Estimation_using_kalman__M =
  &SOC_Estimation_using_kalman__M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  SOC_Estimation_using_kalman_filter_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  SOC_Estimation_using_kalman_filter_step();
  SOC_Estimation_using_kalman_filter_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  SOC_Estimation_using_kalman_filter_step();
  SOC_Estimation_using_kalman_filter_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void SOC_Estimation_using_kalman_filter_step(void)
{
  boolean_T tmp;
  if (rtmIsMajorTimeStep(SOC_Estimation_using_kalman__M)) {
    /* set solver stop time */
    if (!(SOC_Estimation_using_kalman__M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&SOC_Estimation_using_kalman__M->solverInfo,
                            ((SOC_Estimation_using_kalman__M->Timing.clockTickH0
        + 1) * SOC_Estimation_using_kalman__M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&SOC_Estimation_using_kalman__M->solverInfo,
                            ((SOC_Estimation_using_kalman__M->Timing.clockTick0
        + 1) * SOC_Estimation_using_kalman__M->Timing.stepSize0 +
        SOC_Estimation_using_kalman__M->Timing.clockTickH0 *
        SOC_Estimation_using_kalman__M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(SOC_Estimation_using_kalman__M)) {
    SOC_Estimation_using_kalman__M->Timing.t[0] = rtsiGetT
      (&SOC_Estimation_using_kalman__M->solverInfo);
  }

  /* Integrator: '<Root>/Integrator' */
  SOC_Estimation_using_kalman_f_B.TrueSOC =
    SOC_Estimation_using_kalman_f_X.Integrator_CSTATE;
  tmp = rtmIsMajorTimeStep(SOC_Estimation_using_kalman__M);
  if (tmp) {
    /* UnitDelay: '<Root>/Unit Delay' */
    SOC_Estimation_using_kalman_f_B.EKFEstimate =
      SOC_Estimation_using_kalman__DW.UnitDelay_DSTATE;
  }

  /* Sum: '<Root>/Error' */
  SOC_Estimation_using_kalman_f_B.Error =
    SOC_Estimation_using_kalman_f_B.TrueSOC -
    SOC_Estimation_using_kalman_f_B.EKFEstimate;
  if (tmp) {
    /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
    if ((SOC_Estimation_using_kalman__DW.clockTickCounter <
         SOC_Estimation_using_kalman_f_P.PulseGenerator_Duty) &&
        (SOC_Estimation_using_kalman__DW.clockTickCounter >= 0)) {
      /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
      SOC_Estimation_using_kalman_f_B.Current =
        SOC_Estimation_using_kalman_f_P.PulseGenerator_Amp;
    } else {
      /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
      SOC_Estimation_using_kalman_f_B.Current = 0.0;
    }

    if (SOC_Estimation_using_kalman__DW.clockTickCounter >=
        SOC_Estimation_using_kalman_f_P.PulseGenerator_Period - 1.0) {
      SOC_Estimation_using_kalman__DW.clockTickCounter = 0;
    } else {
      SOC_Estimation_using_kalman__DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */
    /* Lookup_n-D: '<Root>/1-D Lookup Table1' incorporates:
     *  UnitDelay: '<Root>/Unit Delay'
     */
    SOC_Estimation_using_kalman_f_B.uDLookupTable1 = look1_binlxpw
      (SOC_Estimation_using_kalman_f_B.EKFEstimate,
       SOC_Estimation_using_kalman_f_P.uDLookupTable1_bp01Data,
       SOC_Estimation_using_kalman_f_P.uDLookupTable1_tableData, 5U);

    /* Gain: '<Root>/Internal Resistance' */
    SOC_Estimation_using_kalman_f_B.InternalResistance =
      SOC_Estimation_using_kalman_f_P.InternalResistance_Gain *
      SOC_Estimation_using_kalman_f_B.Current;

    /* Gain: '<Root>/Amps to SOC' */
    SOC_Estimation_using_kalman_f_B.AmpstoSOC =
      SOC_Estimation_using_kalman_f_P.AmpstoSOC_Gain *
      SOC_Estimation_using_kalman_f_B.Current;

    /* Gain: '<Root>/Discrete time of RC Circuit' */
    SOC_Estimation_using_kalman_f_B.DiscretetimeofRCCircuit =
      SOC_Estimation_using_kalman_f_P.DiscretetimeofRCCircuit_Gain *
      SOC_Estimation_using_kalman_f_B.Current;

    /* UnitDelay: '<Root>/Unit Delay1' */
    SOC_Estimation_using_kalman_f_B.UnitDelay1 =
      SOC_Estimation_using_kalman__DW.UnitDelay1_DSTATE;

    /* Gain: '<Root>/Gain4' */
    SOC_Estimation_using_kalman_f_B.Gain4 =
      SOC_Estimation_using_kalman_f_P.Gain4_Gain *
      SOC_Estimation_using_kalman_f_B.UnitDelay1;

    /* Gain: '<Root>/Internal resistance' */
    SOC_Estimation_using_kalman_f_B.Internalresistance =
      SOC_Estimation_using_kalman_f_P.Internalresistance_Gain *
      SOC_Estimation_using_kalman_f_B.Current;

    /* Gain: '<Root>/SOC Drop ' */
    SOC_Estimation_using_kalman_f_B.SOCDrop =
      SOC_Estimation_using_kalman_f_P.SOCDrop_Gain *
      SOC_Estimation_using_kalman_f_B.Current;

    /* Sum: '<Root>/Sum2' */
    SOC_Estimation_using_kalman_f_B.Sum2 =
      (SOC_Estimation_using_kalman_f_B.uDLookupTable1 -
       SOC_Estimation_using_kalman_f_B.UnitDelay1) -
      SOC_Estimation_using_kalman_f_B.Internalresistance;
  }

  /* Lookup_n-D: '<Root>/1-D Lookup Table' incorporates:
   *  Integrator: '<Root>/Integrator'
   */
  SOC_Estimation_using_kalman_f_B.uDLookupTable = look1_binlxpw
    (SOC_Estimation_using_kalman_f_B.TrueSOC,
     SOC_Estimation_using_kalman_f_P.uDLookupTable_bp01Data,
     SOC_Estimation_using_kalman_f_P.uDLookupTable_tableData, 5U);

  /* TransferFcn: '<Root>/Internal Friction (Polarization)' */
  SOC_Estimation_using_kalman_f_B.InternalFrictionPolarization =
    SOC_Estimation_using_kalman_f_P.InternalFrictionPolarization_C *
    SOC_Estimation_using_kalman_f_X.InternalFrictionPolarization_CS;

  /* Sum: '<Root>/Add' */
  SOC_Estimation_using_kalman_f_B.Add =
    (SOC_Estimation_using_kalman_f_B.uDLookupTable -
     SOC_Estimation_using_kalman_f_B.InternalFrictionPolarization) -
    SOC_Estimation_using_kalman_f_B.InternalResistance;

  /* Sum: '<Root>/Sum3' */
  SOC_Estimation_using_kalman_f_B.Sum3 = SOC_Estimation_using_kalman_f_B.Add -
    SOC_Estimation_using_kalman_f_B.Sum2;

  /* Gain: '<Root>/SOC Kalman gain' */
  SOC_Estimation_using_kalman_f_B.SOCKalmangain =
    SOC_Estimation_using_kalman_f_P.SOCKalmangain_Gain *
    SOC_Estimation_using_kalman_f_B.Sum3;

  /* Sum: '<Root>/Sum' */
  SOC_Estimation_using_kalman_f_B.Sum = (SOC_Estimation_using_kalman_f_B.SOCDrop
    + SOC_Estimation_using_kalman_f_B.EKFEstimate) +
    SOC_Estimation_using_kalman_f_B.SOCKalmangain;

  /* Gain: '<Root>/Voltage kalman gain' */
  SOC_Estimation_using_kalman_f_B.Voltagekalmangain =
    SOC_Estimation_using_kalman_f_P.Voltagekalmangain_Gain *
    SOC_Estimation_using_kalman_f_B.Sum3;

  /* Sum: '<Root>/Sum1' */
  SOC_Estimation_using_kalman_f_B.Sum1 =
    (SOC_Estimation_using_kalman_f_B.DiscretetimeofRCCircuit +
     SOC_Estimation_using_kalman_f_B.Gain4) +
    SOC_Estimation_using_kalman_f_B.Voltagekalmangain;
  if (rtmIsMajorTimeStep(SOC_Estimation_using_kalman__M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(SOC_Estimation_using_kalman__M->rtwLogInfo,
                        (SOC_Estimation_using_kalman__M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(SOC_Estimation_using_kalman__M)) {
    if (rtmIsMajorTimeStep(SOC_Estimation_using_kalman__M)) {
      /* Update for UnitDelay: '<Root>/Unit Delay' */
      SOC_Estimation_using_kalman__DW.UnitDelay_DSTATE =
        SOC_Estimation_using_kalman_f_B.Sum;

      /* Update for UnitDelay: '<Root>/Unit Delay1' */
      SOC_Estimation_using_kalman__DW.UnitDelay1_DSTATE =
        SOC_Estimation_using_kalman_f_B.Sum1;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(SOC_Estimation_using_kalman__M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(SOC_Estimation_using_kalman__M)!=-1) &&
          !((rtmGetTFinal(SOC_Estimation_using_kalman__M)-
             (((SOC_Estimation_using_kalman__M->Timing.clockTick1+
                SOC_Estimation_using_kalman__M->Timing.clockTickH1* 4294967296.0))
              * 50.0)) > (((SOC_Estimation_using_kalman__M->Timing.clockTick1+
                            SOC_Estimation_using_kalman__M->Timing.clockTickH1*
                            4294967296.0)) * 50.0) * (DBL_EPSILON))) {
        rtmSetErrorStatus(SOC_Estimation_using_kalman__M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&SOC_Estimation_using_kalman__M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++SOC_Estimation_using_kalman__M->Timing.clockTick0)) {
      ++SOC_Estimation_using_kalman__M->Timing.clockTickH0;
    }

    SOC_Estimation_using_kalman__M->Timing.t[0] = rtsiGetSolverStopTime
      (&SOC_Estimation_using_kalman__M->solverInfo);

    {
      /* Update absolute timer for sample time: [50.0s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 50.0, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      SOC_Estimation_using_kalman__M->Timing.clockTick1++;
      if (!SOC_Estimation_using_kalman__M->Timing.clockTick1) {
        SOC_Estimation_using_kalman__M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void SOC_Estimation_using_kalman_filter_derivatives(void)
{
  XDot_SOC_Estimation_using_kal_T *_rtXdot;
  _rtXdot = ((XDot_SOC_Estimation_using_kal_T *)
             SOC_Estimation_using_kalman__M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = SOC_Estimation_using_kalman_f_B.AmpstoSOC;

  /* Derivatives for TransferFcn: '<Root>/Internal Friction (Polarization)' */
  _rtXdot->InternalFrictionPolarization_CS =
    SOC_Estimation_using_kalman_f_P.InternalFrictionPolarization_A *
    SOC_Estimation_using_kalman_f_X.InternalFrictionPolarization_CS;
  _rtXdot->InternalFrictionPolarization_CS +=
    SOC_Estimation_using_kalman_f_B.Current;
}

/* Model initialize function */
void SOC_Estimation_using_kalman_filter_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)SOC_Estimation_using_kalman__M, 0,
                sizeof(RT_MODEL_SOC_Estimation_using_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&SOC_Estimation_using_kalman__M->solverInfo,
                          &SOC_Estimation_using_kalman__M->Timing.simTimeStep);
    rtsiSetTPtr(&SOC_Estimation_using_kalman__M->solverInfo, &rtmGetTPtr
                (SOC_Estimation_using_kalman__M));
    rtsiSetStepSizePtr(&SOC_Estimation_using_kalman__M->solverInfo,
                       &SOC_Estimation_using_kalman__M->Timing.stepSize0);
    rtsiSetdXPtr(&SOC_Estimation_using_kalman__M->solverInfo,
                 &SOC_Estimation_using_kalman__M->derivs);
    rtsiSetContStatesPtr(&SOC_Estimation_using_kalman__M->solverInfo, (real_T **)
                         &SOC_Estimation_using_kalman__M->contStates);
    rtsiSetNumContStatesPtr(&SOC_Estimation_using_kalman__M->solverInfo,
      &SOC_Estimation_using_kalman__M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&SOC_Estimation_using_kalman__M->solverInfo,
      &SOC_Estimation_using_kalman__M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&SOC_Estimation_using_kalman__M->solverInfo,
       &SOC_Estimation_using_kalman__M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&SOC_Estimation_using_kalman__M->solverInfo,
       &SOC_Estimation_using_kalman__M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&SOC_Estimation_using_kalman__M->solverInfo,
      (boolean_T**) &SOC_Estimation_using_kalman__M->contStateDisabled);
    rtsiSetErrorStatusPtr(&SOC_Estimation_using_kalman__M->solverInfo,
                          (&rtmGetErrorStatus(SOC_Estimation_using_kalman__M)));
    rtsiSetRTModelPtr(&SOC_Estimation_using_kalman__M->solverInfo,
                      SOC_Estimation_using_kalman__M);
  }

  rtsiSetSimTimeStep(&SOC_Estimation_using_kalman__M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange
    (&SOC_Estimation_using_kalman__M->solverInfo, false);
  rtsiSetIsContModeFrozen(&SOC_Estimation_using_kalman__M->solverInfo, false);
  SOC_Estimation_using_kalman__M->intgData.y =
    SOC_Estimation_using_kalman__M->odeY;
  SOC_Estimation_using_kalman__M->intgData.f[0] =
    SOC_Estimation_using_kalman__M->odeF[0];
  SOC_Estimation_using_kalman__M->intgData.f[1] =
    SOC_Estimation_using_kalman__M->odeF[1];
  SOC_Estimation_using_kalman__M->intgData.f[2] =
    SOC_Estimation_using_kalman__M->odeF[2];
  SOC_Estimation_using_kalman__M->contStates = ((X_SOC_Estimation_using_kalman_T
    *) &SOC_Estimation_using_kalman_f_X);
  SOC_Estimation_using_kalman__M->contStateDisabled =
    ((XDis_SOC_Estimation_using_kal_T *) &SOC_Estimation_using_kalma_XDis);
  SOC_Estimation_using_kalman__M->Timing.tStart = (0.0);
  rtsiSetSolverData(&SOC_Estimation_using_kalman__M->solverInfo, (void *)
                    &SOC_Estimation_using_kalman__M->intgData);
  rtsiSetSolverName(&SOC_Estimation_using_kalman__M->solverInfo,"ode3");
  rtmSetTPtr(SOC_Estimation_using_kalman__M,
             &SOC_Estimation_using_kalman__M->Timing.tArray[0]);
  rtmSetTFinal(SOC_Estimation_using_kalman__M, 500.0);
  SOC_Estimation_using_kalman__M->Timing.stepSize0 = 50.0;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    SOC_Estimation_using_kalman__M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(SOC_Estimation_using_kalman__M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(SOC_Estimation_using_kalman__M->rtwLogInfo, (NULL));
    rtliSetLogT(SOC_Estimation_using_kalman__M->rtwLogInfo, "tout");
    rtliSetLogX(SOC_Estimation_using_kalman__M->rtwLogInfo, "");
    rtliSetLogXFinal(SOC_Estimation_using_kalman__M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(SOC_Estimation_using_kalman__M->rtwLogInfo, "rt_");
    rtliSetLogFormat(SOC_Estimation_using_kalman__M->rtwLogInfo, 4);
    rtliSetLogMaxRows(SOC_Estimation_using_kalman__M->rtwLogInfo, 0);
    rtliSetLogDecimation(SOC_Estimation_using_kalman__M->rtwLogInfo, 1);
    rtliSetLogY(SOC_Estimation_using_kalman__M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(SOC_Estimation_using_kalman__M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(SOC_Estimation_using_kalman__M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &SOC_Estimation_using_kalman_f_B), 0,
                sizeof(B_SOC_Estimation_using_kalman_T));

  /* states (continuous) */
  {
    (void) memset((void *)&SOC_Estimation_using_kalman_f_X, 0,
                  sizeof(X_SOC_Estimation_using_kalman_T));
  }

  /* disabled states */
  {
    (void) memset((void *)&SOC_Estimation_using_kalma_XDis, 0,
                  sizeof(XDis_SOC_Estimation_using_kal_T));
  }

  /* states (dwork) */
  (void) memset((void *)&SOC_Estimation_using_kalman__DW, 0,
                sizeof(DW_SOC_Estimation_using_kalma_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(SOC_Estimation_using_kalman__M->rtwLogInfo,
    0.0, rtmGetTFinal(SOC_Estimation_using_kalman__M),
    SOC_Estimation_using_kalman__M->Timing.stepSize0, (&rtmGetErrorStatus
    (SOC_Estimation_using_kalman__M)));

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  SOC_Estimation_using_kalman__DW.clockTickCounter = 0;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  SOC_Estimation_using_kalman_f_X.Integrator_CSTATE =
    SOC_Estimation_using_kalman_f_P.Integrator_IC;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  SOC_Estimation_using_kalman__DW.UnitDelay_DSTATE =
    SOC_Estimation_using_kalman_f_P.UnitDelay_InitialCondition;

  /* InitializeConditions for TransferFcn: '<Root>/Internal Friction (Polarization)' */
  SOC_Estimation_using_kalman_f_X.InternalFrictionPolarization_CS = 0.0;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay1' */
  SOC_Estimation_using_kalman__DW.UnitDelay1_DSTATE =
    SOC_Estimation_using_kalman_f_P.UnitDelay1_InitialCondition;
}

/* Model terminate function */
void SOC_Estimation_using_kalman_filter_terminate(void)
{
  /* (no terminate code required) */
}
