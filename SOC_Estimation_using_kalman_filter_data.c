/*
 * SOC_Estimation_using_kalman_filter_data.c
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

/* Block parameters (default storage) */
P_SOC_Estimation_using_kalman_T SOC_Estimation_using_kalman_f_P = {
  /* Expression: 1
   * Referenced by: '<Root>/Integrator'
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<Root>/Unit Delay'
   */
  0.5,

  /* Expression: 2
   * Referenced by: '<Root>/Pulse Generator'
   */
  2.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<Root>/Pulse Generator'
   */
  2.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<Root>/Pulse Generator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Pulse Generator'
   */
  0.0,

  /* Expression: [3, 3.2, 3.5, 3.8, 4, 4.2]
   * Referenced by: '<Root>/1-D Lookup Table'
   */
  { 3.0, 3.2, 3.5, 3.8, 4.0, 4.2 },

  /* Expression: [0, 0.2, 0.4, 0.6, 0.8, 1]
   * Referenced by: '<Root>/1-D Lookup Table'
   */
  { 0.0, 0.2, 0.4, 0.6, 0.8, 1.0 },

  /* Expression: [3, 3.2, 3.5, 3.8, 4, 4.2]
   * Referenced by: '<Root>/1-D Lookup Table1'
   */
  { 3.0, 3.2, 3.5, 3.8, 4.0, 4.2 },

  /* Expression: [0, 0.2, 0.4, 0.6, 0.8, 1]
   * Referenced by: '<Root>/1-D Lookup Table1'
   */
  { 0.0, 0.2, 0.4, 0.6, 0.8, 1.0 },

  /* Computed Parameter: InternalFrictionPolarization_A
   * Referenced by: '<Root>/Internal Friction (Polarization)'
   */
  -0.05,

  /* Computed Parameter: InternalFrictionPolarization_C
   * Referenced by: '<Root>/Internal Friction (Polarization)'
   */
  0.0005,

  /* Expression: 0.05
   * Referenced by: '<Root>/Internal Resistance'
   */
  0.05,

  /* Expression: -1/7200
   * Referenced by: '<Root>/Amps to SOC'
   */
  -0.00013888888888888889,

  /* Expression: 0.01*(1-exp(-0.1/20))
   * Referenced by: '<Root>/Discrete time of RC Circuit'
   */
  4.9875208073176804E-5,

  /* Expression: 0
   * Referenced by: '<Root>/Unit Delay1'
   */
  0.0,

  /* Expression: exp(-0.1/20)
   * Referenced by: '<Root>/Gain4'
   */
  0.99501247919268232,

  /* Expression: 0.05
   * Referenced by: '<Root>/Internal resistance'
   */
  0.05,

  /* Expression: -0.1/7200
   * Referenced by: '<Root>/SOC Drop '
   */
  -1.388888888888889E-5,

  /* Expression: 0.5
   * Referenced by: '<Root>/SOC Kalman gain'
   */
  0.5,

  /* Expression: -0.1
   * Referenced by: '<Root>/Voltage kalman gain'
   */
  -0.1
};
