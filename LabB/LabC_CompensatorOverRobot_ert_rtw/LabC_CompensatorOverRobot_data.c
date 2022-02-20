/*
 * LabC_CompensatorOverRobot_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "LabC_CompensatorOverRobot".
 *
 * Model version              : 2.1
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Fri Dec 18 23:11:24 2020
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LabC_CompensatorOverRobot.h"
#include "LabC_CompensatorOverRobot_private.h"

/* Block parameters (default storage) */
P_LabC_CompensatorOverRobot_T LabC_CompensatorOverRobot_P = {
  /* Variable: Ad
   * Referenced by: '<S5>/Gain7'
   */
  { 1.008080132814722, 0.9165562788332714, -0.034614395137017952,
    -3.9299856754134574, 0.018889611252305111, 2.0083781042363276,
    -0.038082111217420174, -4.3236968602669412, 0.0244681770223159,
    2.778414557096565, 0.89692782496290246, -11.563735051569529,
    0.00416127040770144, 0.47201042233839619, -0.0078206004289335575,
    -1.0221271307894866 },

  /* Variable: Bd
   * Referenced by: '<S5>/Gain8'
   */
  { 0.00038254234862350955, 0.043393048058773212, -0.0016387691038655962,
    -0.1860595592674216 },

  /* Variable: Cd
   * Referenced by: '<S5>/Gain10'
   */
  { 1.0, 0.0, 0.0, 0.0 },

  /* Variable: Kd
   * Referenced by: '<S1>/controller'
   */
  { -21.122191683604534, -44.381098044269329, -64.072119035537085,
    -10.434529288236529 },

  /* Variable: Ld
   * Referenced by: '<S5>/Gain9'
   */
  { -21.738073049529966, 6944.430033496621, 7.58003217382404, -16052.91526610734,
    6.9210161383165367, -13576.347620984981, -33.195846643659841,
    31444.178386575986 },

  /* Variable: Md1
   * Referenced by: '<S5>/Gain'
   */
  { 2.1100724730312, 0.0027419358897481302, -4.971511581279958,
    0.051792634988030439, 0.96091142737450619, -0.22103515180457123,
    0.49441309446561316, 0.0011726973621439853, -1.164836908784302 },

  /* Variable: Md2
   * Referenced by: '<S5>/Gain1'
   */
  { 0.045452508264754346, -0.00081202224009479151, -0.19917875804494867 },

  /* Variable: Md3
   * Referenced by: '<S5>/Gain2'
   */
  { 6.3436702322098579, 2.1440387428309036, -38.501853845460715 },

  /* Variable: Md4
   * Referenced by: '<S5>/Gain3'
   */
  { 2.8583491336752616, -0.011103212336680365, -12.181830205820059 },

  /* Variable: Md5
   * Referenced by: '<S5>/Gain4'
   */
  { -5.3836136401410979, -2.1611904322375359, 34.294761938733025 },

  /* Variable: Md6
   * Referenced by: '<S5>/Gain5'
   */
  { 1.0, 0.0, 0.0, -0.0 },

  /* Variable: Md7
   * Referenced by: '<S5>/Gain6'
   */
  { 0.0, 1.0, 0.0, -0.0, 0.0, 0.0, 1.0, -0.0, -0.0, -0.0, -0.0, 1.0 },

  /* Variable: Nud
   * Referenced by: '<S1>/Gain4'
   */
  42.244383367210027,

  /* Variable: Nxd
   * Referenced by: '<S1>/Gain3'
   */
  0.0,

  /* Variable: acc_LSB_per_g
   * Referenced by:
   *   '<S49>/Constant'
   *   '<S50>/Constant'
   */
  16384.0,

  /* Variable: acc_z_offset
   * Referenced by: '<S45>/Constant'
   */
  170.75,

  /* Variable: equ_offset
   * Referenced by: '<S2>/Constant'
   */
  0.040657936268486086,

  /* Variable: fSamplingPeriod
   * Referenced by: '<S2>/integrate, sign from geometry'
   */
  0.01,

  /* Variable: fWheelRadius
   * Referenced by: '<S2>/convert to meters'
   */
  0.0216,

  /* Variable: gyro_LSB_per_deg
   * Referenced by: '<S48>/Scaling factor from datasheet'
   */
  131.0,

  /* Variable: iNumberOfEncoderSteps
   * Referenced by: '<S2>/convert to  radians'
   */
  720.0,

  /* Variable: acc_y_offset
   * Referenced by: '<S45>/Constant1'
   */
  651.5F,

  /* Variable: gyro_x_offset
   * Referenced by: '<S44>/Constant'
   */
  -193.125F,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S6>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScal_g
   * Referenced by: '<S7>/UD'
   */
  0.0,

  /* Mask Parameter: M1V4LeftMotorDriverPWM6D8FST_Vs
   * Referenced by: '<S42>/Saturation -Vsupply to Vsupply'
   */
  7.2F,

  /* Mask Parameter: M1V4MiddleMotorDriverPWM2D5FST_
   * Referenced by: '<S43>/Saturation -Vsupply to Vsupply'
   */
  7.2F,

  /* Expression: 0
   * Referenced by: '<S9>/Serial Transmit'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S46>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S47>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/last value'
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<S41>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 0.98
   * Referenced by: '<S2>/Gain'
   */
  0.98,

  /* Expression: -9.81
   * Referenced by: '<S50>/+ - 9.81'
   */
  -9.81,

  /* Expression: 9.81
   * Referenced by: '<S49>/+9.81'
   */
  9.81,

  /* Expression: -1
   * Referenced by: '<S40>/Gain'
   */
  -1.0,

  /* Expression: 0.02
   * Referenced by: '<S2>/Gain1'
   */
  0.02,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S6>/TSamp'
   */
  100.0,

  /* Computed Parameter: TSamp_WtEt_p
   * Referenced by: '<S7>/TSamp'
   */
  100.0,

  /* Computed Parameter: Internal_1_1_A
   * Referenced by: '<S8>/Internal_1_1'
   */
  -0.0,

  /* Computed Parameter: Internal_1_1_C
   * Referenced by: '<S8>/Internal_1_1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S8>/Internal_1_1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Internal_1_2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Internal_1_3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Internal_1_4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Internal_2_1'
   */
  0.0,

  /* Computed Parameter: Internal_2_2_A
   * Referenced by: '<S8>/Internal_2_2'
   */
  -0.0,

  /* Computed Parameter: Internal_2_2_C
   * Referenced by: '<S8>/Internal_2_2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S8>/Internal_2_2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Internal_2_3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Internal_2_4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Internal_3_1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Internal_3_2'
   */
  0.0,

  /* Computed Parameter: Internal_3_3_A
   * Referenced by: '<S8>/Internal_3_3'
   */
  -0.0,

  /* Computed Parameter: Internal_3_3_C
   * Referenced by: '<S8>/Internal_3_3'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S8>/Internal_3_3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Internal_3_4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Internal_4_1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Internal_4_2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Internal_4_3'
   */
  0.0,

  /* Computed Parameter: Internal_4_4_A
   * Referenced by: '<S8>/Internal_4_4'
   */
  -0.0,

  /* Computed Parameter: Internal_4_4_C
   * Referenced by: '<S8>/Internal_4_4'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S8>/Internal_4_4'
   */
  0.0,

  /* Computed Parameter: Internal_1_1_A_e
   * Referenced by: '<S10>/Internal_1_1'
   */
  -0.0,

  /* Computed Parameter: Internal_1_1_C_a
   * Referenced by: '<S10>/Internal_1_1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S10>/Internal_1_1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/Internal_1_2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/Internal_1_3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/Internal_2_1'
   */
  0.0,

  /* Computed Parameter: Internal_2_2_A_h
   * Referenced by: '<S10>/Internal_2_2'
   */
  -0.0,

  /* Computed Parameter: Internal_2_2_C_o
   * Referenced by: '<S10>/Internal_2_2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S10>/Internal_2_2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/Internal_2_3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/Internal_3_1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/Internal_3_2'
   */
  0.0,

  /* Computed Parameter: Internal_3_3_A_i
   * Referenced by: '<S10>/Internal_3_3'
   */
  -0.0,

  /* Computed Parameter: Internal_3_3_C_f
   * Referenced by: '<S10>/Internal_3_3'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S10>/Internal_3_3'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S5>/10Hz data send trigger'
   */
  1.0,

  /* Expression: 10
   * Referenced by: '<S5>/10Hz data send trigger'
   */
  10.0,

  /* Computed Parameter: Constant_Value_n
   * Referenced by: '<S9>/Constant'
   */
  0.0F,

  /* Computed Parameter: SaturationVsupplytoVsupply_Lowe
   * Referenced by: '<S42>/Saturation -Vsupply to Vsupply'
   */
  -7.2F,

  /* Computed Parameter: conversiontodutycycleconverttou
   * Referenced by: '<S42>/conversion to dutycycle (convert to uint8, overflow will provide reverse polairty magnitued)'
   */
  35.4166679F,

  /* Computed Parameter: SaturationVsupplytoVsupply_Lo_l
   * Referenced by: '<S43>/Saturation -Vsupply to Vsupply'
   */
  -7.2F,

  /* Computed Parameter: conversiontodutycycleconvertt_c
   * Referenced by: '<S43>/conversion to dutycycle (convert to uint8, overflow will provide reverse polairty magnitued)'
   */
  35.4166679F,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<S5>/Manual Switch'
   */
  1U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<S5>/Manual Switch1'
   */
  1U
};
