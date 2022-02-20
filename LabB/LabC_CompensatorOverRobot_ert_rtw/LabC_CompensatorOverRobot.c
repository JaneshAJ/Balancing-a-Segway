/*
 * LabC_CompensatorOverRobot.c
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

/* Block signals (default storage) */
B_LabC_CompensatorOverRobot_T LabC_CompensatorOverRobot_B;

/* Block states (default storage) */
DW_LabC_CompensatorOverRobot_T LabC_CompensatorOverRobot_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_LabC_CompensatorOverR_T LabC_CompensatorOverRob_PrevZCX;

/* Real-time model */
static RT_MODEL_LabC_CompensatorOver_T LabC_CompensatorOverRobot_M_;
RT_MODEL_LabC_CompensatorOver_T *const LabC_CompensatorOverRobot_M =
  &LabC_CompensatorOverRobot_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int16_T u0_0;
  int16_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void LabC_CompensatorOverRobot_step(void)
{
  /* local block i/o variables */
  real_T rtb_TSamp;
  real_T rtb_TSamp_m;
  real_T rtb_Internal_4_4;
  codertarget_arduinobase_inter_T *obj;
  int32_T rtb_Encoder_0;
  real32_T tmp;
  int16_T out[3];
  int16_T out_0[3];
  int16_T i;
  ZCEventType zcEvent;

  /* FromWorkspace: '<S4>/FromWs' */
  {
    real_T *pDataValues = (real_T *)
      LabC_CompensatorOverRobot_DW.FromWs_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      LabC_CompensatorOverRobot_DW.FromWs_PWORK.TimePtr;
    int_T currTimeIndex = LabC_CompensatorOverRobot_DW.FromWs_IWORK.PrevIndex;
    real_T t = LabC_CompensatorOverRobot_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[3]) {
      currTimeIndex = 2;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    LabC_CompensatorOverRobot_DW.FromWs_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          LabC_CompensatorOverRobot_B.FromWs = pDataValues[currTimeIndex];
        } else {
          LabC_CompensatorOverRobot_B.FromWs = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        LabC_CompensatorOverRobot_B.FromWs = (real_T) rtInterpolate(d1, d2, f1,
          f2);
        pDataValues += 4;
      }
    }
  }

  /* MATLABSystem: '<S3>/Encoder' */
  rtb_Encoder_0 = enc_output(1.0);

  /* Gain: '<S2>/convert to meters' incorporates:
   *  DataTypeConversion: '<S3>/Cast To Double'
   *  Gain: '<S2>/convert to  radians'
   *  MATLABSystem: '<S3>/Encoder'
   */
  LabC_CompensatorOverRobot_B.converttometers = -6.2831853071795862 /
    LabC_CompensatorOverRobot_P.iNumberOfEncoderSteps * (real_T)rtb_Encoder_0 *
    LabC_CompensatorOverRobot_P.fWheelRadius;

  /* Memory: '<S2>/last value' */
  LabC_CompensatorOverRobot_B.lastvalue =
    LabC_CompensatorOverRobot_DW.lastvalue_PreviousInput;

  /* MATLABSystem: '<S3>/Gyroscope' */
  MPU6050Gyro_Read(&out[0]);

  /* MATLABSystem: '<S3>/Accelerometer +-2g, 16 bit signed int' */
  MPU6050Accel_Read(&out_0[0]);

  /* Sum: '<S2>/Sum1' incorporates:
   *  Constant: '<S44>/Constant'
   *  Constant: '<S45>/Constant'
   *  Constant: '<S45>/Constant1'
   *  Constant: '<S48>/Scaling factor from datasheet'
   *  Constant: '<S49>/Constant'
   *  Constant: '<S50>/Constant'
   *  Gain: '<S2>/Gain'
   *  Gain: '<S2>/Gain1'
   *  Gain: '<S2>/integrate, sign from geometry'
   *  Gain: '<S40>/Gain'
   *  Gain: '<S41>/Gain1'
   *  Gain: '<S49>/+9.81'
   *  Gain: '<S50>/+ - 9.81'
   *  MATLABSystem: '<S3>/Accelerometer +-2g, 16 bit signed int'
   *  MATLABSystem: '<S3>/Gyroscope'
   *  Product: '<S48>/Divide'
   *  Product: '<S49>/Divide'
   *  Product: '<S50>/Divide'
   *  Sum: '<S2>/Sum2'
   *  Sum: '<S44>/Sum'
   *  Sum: '<S45>/Sum'
   *  Sum: '<S45>/Sum1'
   *  Trigonometry: '<S40>/Atan2'
   */
  LabC_CompensatorOverRobot_B.Sum1 = (((real32_T)out[0] -
    LabC_CompensatorOverRobot_P.gyro_x_offset) /
    LabC_CompensatorOverRobot_P.gyro_LSB_per_deg *
    LabC_CompensatorOverRobot_P.Gain1_Gain *
    -LabC_CompensatorOverRobot_P.fSamplingPeriod +
    LabC_CompensatorOverRobot_B.lastvalue) *
    LabC_CompensatorOverRobot_P.Gain_Gain + rt_atan2d_snf(((real_T)out_0[2] -
    LabC_CompensatorOverRobot_P.acc_z_offset) /
    LabC_CompensatorOverRobot_P.acc_LSB_per_g *
    LabC_CompensatorOverRobot_P.u81_Gain, ((real32_T)out_0[1] -
    LabC_CompensatorOverRobot_P.acc_y_offset) /
    LabC_CompensatorOverRobot_P.acc_LSB_per_g *
    LabC_CompensatorOverRobot_P.u81_Gain_m *
    LabC_CompensatorOverRobot_P.Gain_Gain_g) *
    LabC_CompensatorOverRobot_P.Gain1_Gain_a;

  /* Sum: '<S2>/Sum' incorporates:
   *  Constant: '<S2>/Constant'
   */
  LabC_CompensatorOverRobot_B.Sum = LabC_CompensatorOverRobot_B.Sum1 -
    LabC_CompensatorOverRobot_P.equ_offset;

  /* Gain: '<S1>/Gain3' */
  LabC_CompensatorOverRobot_B.Gain3 = LabC_CompensatorOverRobot_P.Nxd *
    LabC_CompensatorOverRobot_B.FromWs;

  /* SampleTimeMath: '<S6>/TSamp'
   *
   * About '<S6>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = LabC_CompensatorOverRobot_B.converttometers *
    LabC_CompensatorOverRobot_P.TSamp_WtEt;

  /* Sum: '<S6>/Diff' incorporates:
   *  UnitDelay: '<S6>/UD'
   */
  LabC_CompensatorOverRobot_B.Diff = rtb_TSamp -
    LabC_CompensatorOverRobot_DW.UD_DSTATE;

  /* SampleTimeMath: '<S7>/TSamp'
   *
   * About '<S7>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_m = LabC_CompensatorOverRobot_B.Sum *
    LabC_CompensatorOverRobot_P.TSamp_WtEt_p;

  /* Sum: '<S7>/Diff' incorporates:
   *  UnitDelay: '<S7>/UD'
   */
  LabC_CompensatorOverRobot_B.Diff_d = rtb_TSamp_m -
    LabC_CompensatorOverRobot_DW.UD_DSTATE_m;

  /* DiscreteStateSpace: '<S8>/Internal_1_1' */
  {
    rtb_Internal_4_4 = LabC_CompensatorOverRobot_P.Internal_1_1_C*
      LabC_CompensatorOverRobot_DW.Internal_1_1_DSTATE;
  }

  /* DiscreteStateSpace: '<S8>/Internal_1_2' */
  {
    LabC_CompensatorOverRobot_B.Internal_3_3 = 0.0;
  }

  /* DiscreteStateSpace: '<S8>/Internal_1_3' */
  {
    LabC_CompensatorOverRobot_B.Internal_3_2 = 0.0;
  }

  /* DiscreteStateSpace: '<S8>/Internal_1_4' */
  {
    LabC_CompensatorOverRobot_B.Internal_3_1 = 0.0;
  }

  /* Sum: '<S8>/Sum1' */
  LabC_CompensatorOverRobot_B.Sum1_o = ((rtb_Internal_4_4 +
    LabC_CompensatorOverRobot_B.Internal_3_3) +
    LabC_CompensatorOverRobot_B.Internal_3_2) +
    LabC_CompensatorOverRobot_B.Internal_3_1;

  /* DiscreteStateSpace: '<S8>/Internal_2_1' */
  {
    LabC_CompensatorOverRobot_B.Internal_3_1 = 0.0;
  }

  /* DiscreteStateSpace: '<S8>/Internal_2_2' */
  {
    LabC_CompensatorOverRobot_B.Internal_3_2 =
      LabC_CompensatorOverRobot_P.Internal_2_2_C*
      LabC_CompensatorOverRobot_DW.Internal_2_2_DSTATE;
  }

  /* DiscreteStateSpace: '<S8>/Internal_2_3' */
  {
    LabC_CompensatorOverRobot_B.Internal_3_3 = 0.0;
  }

  /* DiscreteStateSpace: '<S8>/Internal_2_4' */
  {
    rtb_Internal_4_4 = 0.0;
  }

  /* Sum: '<S8>/Sum2' */
  LabC_CompensatorOverRobot_B.Sum2 = ((LabC_CompensatorOverRobot_B.Internal_3_1
    + LabC_CompensatorOverRobot_B.Internal_3_2) +
    LabC_CompensatorOverRobot_B.Internal_3_3) + rtb_Internal_4_4;

  /* DiscreteStateSpace: '<S8>/Internal_3_1' */
  {
    LabC_CompensatorOverRobot_B.Internal_3_1 = 0.0;
  }

  /* DiscreteStateSpace: '<S8>/Internal_3_2' */
  {
    LabC_CompensatorOverRobot_B.Internal_3_2 = 0.0;
  }

  /* DiscreteStateSpace: '<S8>/Internal_3_3' */
  {
    LabC_CompensatorOverRobot_B.Internal_3_3 =
      LabC_CompensatorOverRobot_P.Internal_3_3_C*
      LabC_CompensatorOverRobot_DW.Internal_3_3_DSTATE;
  }

  /* DiscreteStateSpace: '<S8>/Internal_3_4' */
  {
    rtb_Internal_4_4 = 0.0;
  }

  /* Sum: '<S8>/Sum3' */
  LabC_CompensatorOverRobot_B.Sum3 = ((LabC_CompensatorOverRobot_B.Internal_3_1
    + LabC_CompensatorOverRobot_B.Internal_3_2) +
    LabC_CompensatorOverRobot_B.Internal_3_3) + rtb_Internal_4_4;

  /* DiscreteStateSpace: '<S8>/Internal_4_1' */
  {
    LabC_CompensatorOverRobot_B.Internal_3_1 = 0.0;
  }

  /* DiscreteStateSpace: '<S8>/Internal_4_2' */
  {
    LabC_CompensatorOverRobot_B.Internal_3_2 = 0.0;
  }

  /* DiscreteStateSpace: '<S8>/Internal_4_3' */
  {
    LabC_CompensatorOverRobot_B.Internal_3_3 = 0.0;
  }

  /* DiscreteStateSpace: '<S8>/Internal_4_4' */
  {
    rtb_Internal_4_4 = LabC_CompensatorOverRobot_P.Internal_4_4_C*
      LabC_CompensatorOverRobot_DW.Internal_4_4_DSTATE;
  }

  /* Sum: '<S8>/Sum4' */
  LabC_CompensatorOverRobot_B.Sum4 = ((LabC_CompensatorOverRobot_B.Internal_3_1
    + LabC_CompensatorOverRobot_B.Internal_3_2) +
    LabC_CompensatorOverRobot_B.Internal_3_3) + rtb_Internal_4_4;

  /* DiscreteStateSpace: '<S10>/Internal_1_1' */
  {
    LabC_CompensatorOverRobot_B.Internal_3_1 =
      LabC_CompensatorOverRobot_P.Internal_1_1_C_a*
      LabC_CompensatorOverRobot_DW.Internal_1_1_DSTATE_l;
  }

  /* DiscreteStateSpace: '<S10>/Internal_1_2' */
  {
    LabC_CompensatorOverRobot_B.Internal_3_2 = 0.0;
  }

  /* DiscreteStateSpace: '<S10>/Internal_1_3' */
  {
    LabC_CompensatorOverRobot_B.Internal_3_3 = 0.0;
  }

  /* Sum: '<S10>/Sum1' */
  LabC_CompensatorOverRobot_B.Sum1_g = (LabC_CompensatorOverRobot_B.Internal_3_1
    + LabC_CompensatorOverRobot_B.Internal_3_2) +
    LabC_CompensatorOverRobot_B.Internal_3_3;

  /* DiscreteStateSpace: '<S10>/Internal_2_1' */
  {
    LabC_CompensatorOverRobot_B.Internal_3_1 = 0.0;
  }

  /* DiscreteStateSpace: '<S10>/Internal_2_2' */
  {
    LabC_CompensatorOverRobot_B.Internal_3_2 =
      LabC_CompensatorOverRobot_P.Internal_2_2_C_o*
      LabC_CompensatorOverRobot_DW.Internal_2_2_DSTATE_a;
  }

  /* DiscreteStateSpace: '<S10>/Internal_2_3' */
  {
    LabC_CompensatorOverRobot_B.Internal_3_3 = 0.0;
  }

  /* Sum: '<S10>/Sum2' */
  LabC_CompensatorOverRobot_B.Sum2_a = (LabC_CompensatorOverRobot_B.Internal_3_1
    + LabC_CompensatorOverRobot_B.Internal_3_2) +
    LabC_CompensatorOverRobot_B.Internal_3_3;

  /* DiscreteStateSpace: '<S10>/Internal_3_1' */
  {
    LabC_CompensatorOverRobot_B.Internal_3_1 = 0.0;
  }

  /* DiscreteStateSpace: '<S10>/Internal_3_2' */
  {
    LabC_CompensatorOverRobot_B.Internal_3_2 = 0.0;
  }

  /* DiscreteStateSpace: '<S10>/Internal_3_3' */
  {
    LabC_CompensatorOverRobot_B.Internal_3_3 =
      LabC_CompensatorOverRobot_P.Internal_3_3_C_f*
      LabC_CompensatorOverRobot_DW.Internal_3_3_DSTATE_b;
  }

  /* Sum: '<S10>/Sum3' */
  LabC_CompensatorOverRobot_B.Sum3_h = (LabC_CompensatorOverRobot_B.Internal_3_1
    + LabC_CompensatorOverRobot_B.Internal_3_2) +
    LabC_CompensatorOverRobot_B.Internal_3_3;

  /* Sum: '<S5>/Add1' incorporates:
   *  Gain: '<S5>/Gain4'
   */
  LabC_CompensatorOverRobot_B.rtb_Add1_idx_0 = LabC_CompensatorOverRobot_P.Md5[0]
    * LabC_CompensatorOverRobot_B.converttometers +
    LabC_CompensatorOverRobot_B.Sum1_g;
  LabC_CompensatorOverRobot_B.rtb_Add1_idx_1 = LabC_CompensatorOverRobot_P.Md5[1]
    * LabC_CompensatorOverRobot_B.converttometers +
    LabC_CompensatorOverRobot_B.Sum2_a;
  LabC_CompensatorOverRobot_B.rtb_Add1_idx_2 = LabC_CompensatorOverRobot_P.Md5[2]
    * LabC_CompensatorOverRobot_B.converttometers +
    LabC_CompensatorOverRobot_B.Sum3_h;
  for (i = 0; i < 4; i++) {
    /* Sum: '<S5>/Add2' incorporates:
     *  Gain: '<S5>/Gain5'
     *  Gain: '<S5>/Gain6'
     *  Sum: '<S5>/Add1'
     */
    LabC_CompensatorOverRobot_B.Add2[i] = ((LabC_CompensatorOverRobot_P.Md7[i +
      4] * LabC_CompensatorOverRobot_B.rtb_Add1_idx_1 +
      LabC_CompensatorOverRobot_P.Md7[i] *
      LabC_CompensatorOverRobot_B.rtb_Add1_idx_0) +
      LabC_CompensatorOverRobot_P.Md7[i + 8] *
      LabC_CompensatorOverRobot_B.rtb_Add1_idx_2) +
      LabC_CompensatorOverRobot_P.Md6[i] *
      LabC_CompensatorOverRobot_B.converttometers;
  }

  /* ManualSwitch: '<S5>/Manual Switch1' incorporates:
   *  Gain: '<S5>/Gain8'
   *  ManualSwitch: '<S5>/Manual Switch'
   *  Sum: '<S5>/Add2'
   */
  if (LabC_CompensatorOverRobot_P.ManualSwitch1_CurrentSetting == 1) {
    LabC_CompensatorOverRobot_B.Gain8[0] =
      LabC_CompensatorOverRobot_B.converttometers;
    LabC_CompensatorOverRobot_B.Gain8[1] = LabC_CompensatorOverRobot_B.Diff;
    LabC_CompensatorOverRobot_B.Gain8[2] = LabC_CompensatorOverRobot_B.Sum;
    LabC_CompensatorOverRobot_B.Gain8[3] = LabC_CompensatorOverRobot_B.Diff_d;
  } else if (LabC_CompensatorOverRobot_P.ManualSwitch_CurrentSetting == 1) {
    /* ManualSwitch: '<S5>/Manual Switch' incorporates:
     *  Gain: '<S5>/Gain8'
     */
    LabC_CompensatorOverRobot_B.Gain8[0] = LabC_CompensatorOverRobot_B.Sum1_o;
    LabC_CompensatorOverRobot_B.Gain8[1] = LabC_CompensatorOverRobot_B.Sum2;
    LabC_CompensatorOverRobot_B.Gain8[2] = LabC_CompensatorOverRobot_B.Sum3;
    LabC_CompensatorOverRobot_B.Gain8[3] = LabC_CompensatorOverRobot_B.Sum4;
  } else {
    LabC_CompensatorOverRobot_B.Gain8[0] = LabC_CompensatorOverRobot_B.Add2[0];
    LabC_CompensatorOverRobot_B.Gain8[1] = LabC_CompensatorOverRobot_B.Add2[1];
    LabC_CompensatorOverRobot_B.Gain8[2] = LabC_CompensatorOverRobot_B.Add2[2];
    LabC_CompensatorOverRobot_B.Gain8[3] = LabC_CompensatorOverRobot_B.Add2[3];
  }

  /* End of ManualSwitch: '<S5>/Manual Switch1' */

  /* Product: '<S1>/Product1' incorporates:
   *  Fcn: '<S1>/turn off the motor if the measured angle is greater than X degrees'
   *  Gain: '<S1>/Gain4'
   *  Gain: '<S1>/controller'
   *  Gain: '<S5>/Gain8'
   *  Sum: '<S1>/Sum'
   *  Sum: '<S1>/Sum1'
   */
  LabC_CompensatorOverRobot_B.Product1 = (((((LabC_CompensatorOverRobot_B.Gain3
    + LabC_CompensatorOverRobot_B.Gain8[0]) * LabC_CompensatorOverRobot_P.Kd[0]
    + (LabC_CompensatorOverRobot_B.Gain3 + LabC_CompensatorOverRobot_B.Gain8[1])
    * LabC_CompensatorOverRobot_P.Kd[1]) + (LabC_CompensatorOverRobot_B.Gain3 +
    LabC_CompensatorOverRobot_B.Gain8[2]) * LabC_CompensatorOverRobot_P.Kd[2]) +
    (LabC_CompensatorOverRobot_B.Gain3 + LabC_CompensatorOverRobot_B.Gain8[3]) *
    LabC_CompensatorOverRobot_P.Kd[3]) + -LabC_CompensatorOverRobot_P.Nud *
    LabC_CompensatorOverRobot_B.FromWs) * (real_T)(fabs
    (LabC_CompensatorOverRobot_B.Sum) < 0.75);

  /* SignalGenerator: '<S5>/10Hz data send trigger' */
  LabC_CompensatorOverRobot_B.Gain3 =
    LabC_CompensatorOverRobot_P.u0Hzdatasendtrigger_Frequency *
    LabC_CompensatorOverRobot_M->Timing.t[0];

  /* SignalGenerator: '<S5>/10Hz data send trigger' */
  LabC_CompensatorOverRobot_B.u0Hzdatasendtrigger = (1.0 -
    (LabC_CompensatorOverRobot_B.Gain3 - floor(LabC_CompensatorOverRobot_B.Gain3))
    * 2.0) * LabC_CompensatorOverRobot_P.u0Hzdatasendtrigger_Amplitude;

  /* Outputs for Triggered SubSystem: '<S5>/Send serial data' incorporates:
   *  TriggerPort: '<S9>/Trigger'
   */
  zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,
                     &LabC_CompensatorOverRob_PrevZCX.Sendserialdata_Trig_ZCE,
                     (LabC_CompensatorOverRobot_B.u0Hzdatasendtrigger));
  if (zcEvent != NO_ZCEVENT) {
    /* MATLABSystem: '<S9>/Serial Transmit' incorporates:
     *  Constant: '<S9>/Constant'
     *  DataTypeConversion: '<S9>/Cast To Single'
     *  DataTypeConversion: '<S9>/Cast To Single1'
     *  DataTypeConversion: '<S9>/Cast To Single2'
     *  DataTypeConversion: '<S9>/Cast To Single3'
     *  DataTypeConversion: '<S9>/Cast To Single5'
     *  DataTypeConversion: '<S9>/Cast To Single6'
     *  DataTypeConversion: '<S9>/Cast To Single7'
     */
    if (LabC_CompensatorOverRobot_DW.obj.Protocol !=
        LabC_CompensatorOverRobot_P.SerialTransmit_Protocol) {
      LabC_CompensatorOverRobot_DW.obj.Protocol =
        LabC_CompensatorOverRobot_P.SerialTransmit_Protocol;
    }

    LabC_CompensatorOverRobot_B.dataIn[0] =
      LabC_CompensatorOverRobot_P.Constant_Value_n;
    LabC_CompensatorOverRobot_B.dataIn[1] = (real32_T)
      LabC_CompensatorOverRobot_B.converttometers;
    LabC_CompensatorOverRobot_B.dataIn[2] = (real32_T)
      LabC_CompensatorOverRobot_B.Add2[0];
    LabC_CompensatorOverRobot_B.dataIn[3] = (real32_T)
      LabC_CompensatorOverRobot_B.Sum1_o;
    LabC_CompensatorOverRobot_B.dataIn[4] = (real32_T)
      LabC_CompensatorOverRobot_B.Sum;
    LabC_CompensatorOverRobot_B.dataIn[5] = (real32_T)
      LabC_CompensatorOverRobot_B.Add2[2];
    LabC_CompensatorOverRobot_B.dataIn[6] = (real32_T)
      LabC_CompensatorOverRobot_B.Sum3;
    LabC_CompensatorOverRobot_B.dataIn[7] = (real32_T)
      LabC_CompensatorOverRobot_B.Product1;
    MW_Serial_write(LabC_CompensatorOverRobot_DW.obj.port,
                    &LabC_CompensatorOverRobot_B.dataIn[0], 8.0,
                    LabC_CompensatorOverRobot_DW.obj.dataSizeInBytes,
                    LabC_CompensatorOverRobot_DW.obj.sendModeEnum,
                    LabC_CompensatorOverRobot_DW.obj.dataType,
                    LabC_CompensatorOverRobot_DW.obj.sendFormatEnum, 2.0, '\x00');

    /* End of MATLABSystem: '<S9>/Serial Transmit' */
  }

  /* End of Outputs for SubSystem: '<S5>/Send serial data' */
  for (i = 0; i < 3; i++) {
    /* Sum: '<S5>/Add' incorporates:
     *  Gain: '<S5>/Gain'
     *  Gain: '<S5>/Gain1'
     *  Gain: '<S5>/Gain2'
     *  Gain: '<S5>/Gain3'
     *  Sum: '<S5>/Add1'
     */
    LabC_CompensatorOverRobot_B.Add[i] = ((LabC_CompensatorOverRobot_P.Md1[i + 3]
      * LabC_CompensatorOverRobot_B.rtb_Add1_idx_1 +
      LabC_CompensatorOverRobot_P.Md1[i] *
      LabC_CompensatorOverRobot_B.rtb_Add1_idx_0) +
      LabC_CompensatorOverRobot_P.Md1[i + 6] *
      LabC_CompensatorOverRobot_B.rtb_Add1_idx_2) +
      ((LabC_CompensatorOverRobot_P.Md4[i] * LabC_CompensatorOverRobot_B.Sum +
        LabC_CompensatorOverRobot_P.Md3[i] *
        LabC_CompensatorOverRobot_B.converttometers) +
       LabC_CompensatorOverRobot_P.Md2[i] * LabC_CompensatorOverRobot_B.Product1);
  }

  /* SignalConversion generated from: '<S5>/Gain10' */
  LabC_CompensatorOverRobot_B.Gain8[0] = LabC_CompensatorOverRobot_B.Sum1_o;
  LabC_CompensatorOverRobot_B.Gain8[1] = LabC_CompensatorOverRobot_B.Sum2;
  LabC_CompensatorOverRobot_B.Gain8[2] = LabC_CompensatorOverRobot_B.Sum3;
  LabC_CompensatorOverRobot_B.Gain8[3] = LabC_CompensatorOverRobot_B.Sum4;

  /* Gain: '<S5>/Gain10' */
  LabC_CompensatorOverRobot_B.Gain3 = 0.0;
  for (i = 0; i < 4; i++) {
    LabC_CompensatorOverRobot_B.Gain3 += LabC_CompensatorOverRobot_P.Cd[i] *
      LabC_CompensatorOverRobot_B.Gain8[i];

    /* Gain: '<S5>/Gain7' incorporates:
     *  SignalConversion generated from: '<S5>/Gain10'
     */
    LabC_CompensatorOverRobot_B.Gain7[i] = 0.0;
    LabC_CompensatorOverRobot_B.Gain7[i] += LabC_CompensatorOverRobot_P.Ad[i] *
      LabC_CompensatorOverRobot_B.Sum1_o;
    LabC_CompensatorOverRobot_B.Gain7[i] += LabC_CompensatorOverRobot_P.Ad[i + 4]
      * LabC_CompensatorOverRobot_B.Sum2;
    LabC_CompensatorOverRobot_B.Gain7[i] += LabC_CompensatorOverRobot_P.Ad[i + 8]
      * LabC_CompensatorOverRobot_B.Sum3;
    LabC_CompensatorOverRobot_B.Gain7[i] += LabC_CompensatorOverRobot_P.Ad[i +
      12] * LabC_CompensatorOverRobot_B.Sum4;
  }

  /* Gain: '<S5>/Gain10' */
  LabC_CompensatorOverRobot_B.Gain10 = LabC_CompensatorOverRobot_B.Gain3;

  /* Sum: '<S5>/Sum' */
  LabC_CompensatorOverRobot_B.Gain3 =
    LabC_CompensatorOverRobot_B.converttometers -
    LabC_CompensatorOverRobot_B.Gain10;
  LabC_CompensatorOverRobot_B.rtb_Add1_idx_0 = LabC_CompensatorOverRobot_B.Sum -
    LabC_CompensatorOverRobot_B.Gain10;
  for (i = 0; i < 4; i++) {
    /* Sum: '<S5>/Add3' incorporates:
     *  Gain: '<S5>/Gain8'
     *  Gain: '<S5>/Gain9'
     */
    LabC_CompensatorOverRobot_B.Add3[i] = (LabC_CompensatorOverRobot_P.Bd[i] *
      LabC_CompensatorOverRobot_B.Product1 + (LabC_CompensatorOverRobot_P.Ld[i +
      4] * LabC_CompensatorOverRobot_B.rtb_Add1_idx_0 +
      LabC_CompensatorOverRobot_P.Ld[i] * LabC_CompensatorOverRobot_B.Gain3)) +
      LabC_CompensatorOverRobot_B.Gain7[i];
  }

  /* MATLABSystem: '<S42>/Digital Output1' incorporates:
   *  Constant: '<S46>/Constant'
   *  RelationalOperator: '<S46>/Compare'
   */
  writeDigitalPin(8, (uint8_T)(LabC_CompensatorOverRobot_B.Product1 <
    LabC_CompensatorOverRobot_P.Constant_Value));

  /* MATLABSystem: '<S42>/PWM' */
  obj = &LabC_CompensatorOverRobot_DW.obj_j;
  obj->MW_PWM_HANDLE = MW_PWM_GetHandle
    (LabC_CompensatorOverRobot_DW.obj_j.PinPWM);

  /* Saturate: '<S42>/Saturation -Vsupply to Vsupply' */
  if (LabC_CompensatorOverRobot_B.Product1 >
      LabC_CompensatorOverRobot_P.M1V4LeftMotorDriverPWM6D8FST_Vs) {
    LabC_CompensatorOverRobot_B.Gain3 =
      LabC_CompensatorOverRobot_P.M1V4LeftMotorDriverPWM6D8FST_Vs;
  } else if (LabC_CompensatorOverRobot_B.Product1 <
             LabC_CompensatorOverRobot_P.SaturationVsupplytoVsupply_Lowe) {
    LabC_CompensatorOverRobot_B.Gain3 =
      LabC_CompensatorOverRobot_P.SaturationVsupplytoVsupply_Lowe;
  } else {
    LabC_CompensatorOverRobot_B.Gain3 = LabC_CompensatorOverRobot_B.Product1;
  }

  /* Gain: '<S42>/conversion to dutycycle (convert to uint8, overflow will provide reverse polairty magnitued)' incorporates:
   *  Saturate: '<S42>/Saturation -Vsupply to Vsupply'
   */
  tmp = (real32_T)floor
    (LabC_CompensatorOverRobot_P.conversiontodutycycleconverttou * (real32_T)
     LabC_CompensatorOverRobot_B.Gain3);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 256.0);
  }

  /* MATLABSystem: '<S42>/PWM' incorporates:
   *  Gain: '<S42>/conversion to dutycycle (convert to uint8, overflow will provide reverse polairty magnitued)'
   */
  MW_PWM_SetDutyCycle(LabC_CompensatorOverRobot_DW.obj_j.MW_PWM_HANDLE, (real_T)
                      (tmp < 0.0F ? (int16_T)(uint8_T)-(int8_T)(uint8_T)-tmp :
                       (int16_T)(uint8_T)tmp));

  /* MATLABSystem: '<S43>/Digital Output1' incorporates:
   *  Constant: '<S47>/Constant'
   *  RelationalOperator: '<S47>/Compare'
   */
  writeDigitalPin(5, (uint8_T)(LabC_CompensatorOverRobot_B.Product1 <
    LabC_CompensatorOverRobot_P.Constant_Value_i));

  /* MATLABSystem: '<S43>/PWM' */
  obj = &LabC_CompensatorOverRobot_DW.obj_f;
  obj->MW_PWM_HANDLE = MW_PWM_GetHandle
    (LabC_CompensatorOverRobot_DW.obj_f.PinPWM);

  /* Saturate: '<S43>/Saturation -Vsupply to Vsupply' */
  if (LabC_CompensatorOverRobot_B.Product1 >
      LabC_CompensatorOverRobot_P.M1V4MiddleMotorDriverPWM2D5FST_) {
    LabC_CompensatorOverRobot_B.Gain3 =
      LabC_CompensatorOverRobot_P.M1V4MiddleMotorDriverPWM2D5FST_;
  } else if (LabC_CompensatorOverRobot_B.Product1 <
             LabC_CompensatorOverRobot_P.SaturationVsupplytoVsupply_Lo_l) {
    LabC_CompensatorOverRobot_B.Gain3 =
      LabC_CompensatorOverRobot_P.SaturationVsupplytoVsupply_Lo_l;
  } else {
    LabC_CompensatorOverRobot_B.Gain3 = LabC_CompensatorOverRobot_B.Product1;
  }

  /* Gain: '<S43>/conversion to dutycycle (convert to uint8, overflow will provide reverse polairty magnitued)' incorporates:
   *  Saturate: '<S43>/Saturation -Vsupply to Vsupply'
   */
  tmp = (real32_T)floor
    (LabC_CompensatorOverRobot_P.conversiontodutycycleconvertt_c * (real32_T)
     LabC_CompensatorOverRobot_B.Gain3);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 256.0);
  }

  /* MATLABSystem: '<S43>/PWM' incorporates:
   *  Gain: '<S43>/conversion to dutycycle (convert to uint8, overflow will provide reverse polairty magnitued)'
   */
  MW_PWM_SetDutyCycle(LabC_CompensatorOverRobot_DW.obj_f.MW_PWM_HANDLE, (real_T)
                      (tmp < 0.0F ? (int16_T)(uint8_T)-(int8_T)(uint8_T)-tmp :
                       (int16_T)(uint8_T)tmp));

  /* Update for Memory: '<S2>/last value' */
  LabC_CompensatorOverRobot_DW.lastvalue_PreviousInput =
    LabC_CompensatorOverRobot_B.Sum1;

  /* Update for UnitDelay: '<S6>/UD' */
  LabC_CompensatorOverRobot_DW.UD_DSTATE = rtb_TSamp;

  /* Update for UnitDelay: '<S7>/UD' */
  LabC_CompensatorOverRobot_DW.UD_DSTATE_m = rtb_TSamp_m;

  /* Update for DiscreteStateSpace: '<S8>/Internal_1_1' */
  {
    LabC_CompensatorOverRobot_DW.Internal_1_1_DSTATE =
      LabC_CompensatorOverRobot_B.Add3[0] +
      (LabC_CompensatorOverRobot_P.Internal_1_1_A)*
      LabC_CompensatorOverRobot_DW.Internal_1_1_DSTATE;
  }

  /* Update for DiscreteStateSpace: '<S8>/Internal_2_2' */
  {
    LabC_CompensatorOverRobot_DW.Internal_2_2_DSTATE =
      LabC_CompensatorOverRobot_B.Add3[1] +
      (LabC_CompensatorOverRobot_P.Internal_2_2_A)*
      LabC_CompensatorOverRobot_DW.Internal_2_2_DSTATE;
  }

  /* Update for DiscreteStateSpace: '<S8>/Internal_3_3' */
  {
    LabC_CompensatorOverRobot_DW.Internal_3_3_DSTATE =
      LabC_CompensatorOverRobot_B.Add3[2] +
      (LabC_CompensatorOverRobot_P.Internal_3_3_A)*
      LabC_CompensatorOverRobot_DW.Internal_3_3_DSTATE;
  }

  /* Update for DiscreteStateSpace: '<S8>/Internal_4_4' */
  {
    LabC_CompensatorOverRobot_DW.Internal_4_4_DSTATE =
      LabC_CompensatorOverRobot_B.Add3[3] +
      (LabC_CompensatorOverRobot_P.Internal_4_4_A)*
      LabC_CompensatorOverRobot_DW.Internal_4_4_DSTATE;
  }

  /* Update for DiscreteStateSpace: '<S10>/Internal_1_1' */
  {
    LabC_CompensatorOverRobot_DW.Internal_1_1_DSTATE_l =
      LabC_CompensatorOverRobot_B.Add[0] +
      (LabC_CompensatorOverRobot_P.Internal_1_1_A_e)*
      LabC_CompensatorOverRobot_DW.Internal_1_1_DSTATE_l;
  }

  /* Update for DiscreteStateSpace: '<S10>/Internal_2_2' */
  {
    LabC_CompensatorOverRobot_DW.Internal_2_2_DSTATE_a =
      LabC_CompensatorOverRobot_B.Add[1] +
      (LabC_CompensatorOverRobot_P.Internal_2_2_A_h)*
      LabC_CompensatorOverRobot_DW.Internal_2_2_DSTATE_a;
  }

  /* Update for DiscreteStateSpace: '<S10>/Internal_3_3' */
  {
    LabC_CompensatorOverRobot_DW.Internal_3_3_DSTATE_b =
      LabC_CompensatorOverRobot_B.Add[2] +
      (LabC_CompensatorOverRobot_P.Internal_3_3_A_i)*
      LabC_CompensatorOverRobot_DW.Internal_3_3_DSTATE_b;
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++LabC_CompensatorOverRobot_M->Timing.clockTick0)) {
    ++LabC_CompensatorOverRobot_M->Timing.clockTickH0;
  }

  LabC_CompensatorOverRobot_M->Timing.t[0] =
    LabC_CompensatorOverRobot_M->Timing.clockTick0 *
    LabC_CompensatorOverRobot_M->Timing.stepSize0 +
    LabC_CompensatorOverRobot_M->Timing.clockTickH0 *
    LabC_CompensatorOverRobot_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    LabC_CompensatorOverRobot_M->Timing.clockTick1++;
    if (!LabC_CompensatorOverRobot_M->Timing.clockTick1) {
      LabC_CompensatorOverRobot_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void LabC_CompensatorOverRobot_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  LabC_CompensatorOverRobot_P.Constant_Value_n = rtInfF;

  /* initialize real-time model */
  (void) memset((void *)LabC_CompensatorOverRobot_M, 0,
                sizeof(RT_MODEL_LabC_CompensatorOver_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&LabC_CompensatorOverRobot_M->solverInfo,
                          &LabC_CompensatorOverRobot_M->Timing.simTimeStep);
    rtsiSetTPtr(&LabC_CompensatorOverRobot_M->solverInfo, &rtmGetTPtr
                (LabC_CompensatorOverRobot_M));
    rtsiSetStepSizePtr(&LabC_CompensatorOverRobot_M->solverInfo,
                       &LabC_CompensatorOverRobot_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&LabC_CompensatorOverRobot_M->solverInfo,
                          (&rtmGetErrorStatus(LabC_CompensatorOverRobot_M)));
    rtsiSetRTModelPtr(&LabC_CompensatorOverRobot_M->solverInfo,
                      LabC_CompensatorOverRobot_M);
  }

  rtsiSetSimTimeStep(&LabC_CompensatorOverRobot_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&LabC_CompensatorOverRobot_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(LabC_CompensatorOverRobot_M,
             &LabC_CompensatorOverRobot_M->Timing.tArray[0]);
  LabC_CompensatorOverRobot_M->Timing.stepSize0 = 0.01;

  /* block I/O */
  (void) memset(((void *) &LabC_CompensatorOverRobot_B), 0,
                sizeof(B_LabC_CompensatorOverRobot_T));

  /* states (dwork) */
  (void) memset((void *)&LabC_CompensatorOverRobot_DW, 0,
                sizeof(DW_LabC_CompensatorOverRobot_T));

  {
    codertarget_arduinobase_inter_T *obj;
    real_T tmp;
    uint8_T tmp_0;

    /* Start for FromWorkspace: '<S4>/FromWs' */
    {
      static real_T pTimeValues0[] = { 0.0, 60.0, 60.0, 120.0 } ;

      static real_T pDataValues0[] = { 0.0, 0.0, 1.0, 1.0 } ;

      LabC_CompensatorOverRobot_DW.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
      LabC_CompensatorOverRobot_DW.FromWs_PWORK.DataPtr = (void *) pDataValues0;
      LabC_CompensatorOverRobot_DW.FromWs_IWORK.PrevIndex = 0;
    }

    /* Start for MATLABSystem: '<S3>/Encoder' */
    LabC_CompensatorOverRobot_DW.obj_k.matlabCodegenIsDeleted = false;
    LabC_CompensatorOverRobot_DW.objisempty_d = true;
    LabC_CompensatorOverRobot_DW.obj_k.isInitialized = 1L;
    enc_init(1.0, 19.0, 18.0);
    LabC_CompensatorOverRobot_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Gyroscope' */
    LabC_CompensatorOverRobot_DW.obj_c.matlabCodegenIsDeleted = false;
    LabC_CompensatorOverRobot_DW.objisempty_j = true;
    LabC_CompensatorOverRobot_DW.obj_c.isInitialized = 1L;
    MPU6050Gyro_Init(0.0);
    LabC_CompensatorOverRobot_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Accelerometer +-2g, 16 bit signed int' */
    LabC_CompensatorOverRobot_DW.obj_d.matlabCodegenIsDeleted = false;
    LabC_CompensatorOverRobot_DW.objisempty_m = true;
    LabC_CompensatorOverRobot_DW.obj_d.isInitialized = 1L;
    MPU6050Accel_Init();
    LabC_CompensatorOverRobot_DW.obj_d.isSetupComplete = true;

    /* Start for Triggered SubSystem: '<S5>/Send serial data' */
    /* Start for MATLABSystem: '<S9>/Serial Transmit' */
    LabC_CompensatorOverRobot_DW.obj.matlabCodegenIsDeleted = false;
    LabC_CompensatorOverRobot_DW.objisempty_o = true;
    LabC_CompensatorOverRobot_DW.obj.Protocol =
      LabC_CompensatorOverRobot_P.SerialTransmit_Protocol;
    LabC_CompensatorOverRobot_DW.obj.isInitialized = 1L;
    LabC_CompensatorOverRobot_DW.obj.port = 0.0;
    LabC_CompensatorOverRobot_DW.obj.dataSizeInBytes = 4.0;
    LabC_CompensatorOverRobot_DW.obj.dataType = 6.0;
    LabC_CompensatorOverRobot_DW.obj.sendModeEnum = 0.0;
    LabC_CompensatorOverRobot_DW.obj.sendFormatEnum = 0.0;
    tmp = rt_roundd_snf(LabC_CompensatorOverRobot_DW.obj.port);
    if (tmp < 256.0) {
      if (tmp >= 0.0) {
        tmp_0 = (uint8_T)tmp;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    MW_SCI_Open(tmp_0);
    LabC_CompensatorOverRobot_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S9>/Serial Transmit' */
    /* End of Start for SubSystem: '<S5>/Send serial data' */

    /* Start for MATLABSystem: '<S42>/Digital Output1' */
    LabC_CompensatorOverRobot_DW.obj_ip.matlabCodegenIsDeleted = false;
    LabC_CompensatorOverRobot_DW.objisempty_e = true;
    LabC_CompensatorOverRobot_DW.obj_ip.isInitialized = 1L;
    digitalIOSetup(8, 1);
    LabC_CompensatorOverRobot_DW.obj_ip.isSetupComplete = true;

    /* Start for MATLABSystem: '<S42>/PWM' */
    LabC_CompensatorOverRobot_DW.obj_j.matlabCodegenIsDeleted = true;
    LabC_CompensatorOverRobot_DW.obj_j.isInitialized = 0L;
    LabC_CompensatorOverRobot_DW.obj_j.matlabCodegenIsDeleted = false;
    LabC_CompensatorOverRobot_DW.objisempty_k = true;
    LabC_CompensatorOverRobot_DW.obj_j.PinPWM = 6UL;
    obj = &LabC_CompensatorOverRobot_DW.obj_j;
    LabC_CompensatorOverRobot_DW.obj_j.isSetupComplete = false;
    LabC_CompensatorOverRobot_DW.obj_j.isInitialized = 1L;
    obj->MW_PWM_HANDLE = MW_PWM_Open(LabC_CompensatorOverRobot_DW.obj_j.PinPWM,
      0.0, 0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle
      (LabC_CompensatorOverRobot_DW.obj_j.PinPWM);
    MW_PWM_Start(LabC_CompensatorOverRobot_DW.obj_j.MW_PWM_HANDLE);
    LabC_CompensatorOverRobot_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S43>/Digital Output1' */
    LabC_CompensatorOverRobot_DW.obj_i.matlabCodegenIsDeleted = false;
    LabC_CompensatorOverRobot_DW.objisempty_l = true;
    LabC_CompensatorOverRobot_DW.obj_i.isInitialized = 1L;
    digitalIOSetup(5, 1);
    LabC_CompensatorOverRobot_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S43>/PWM' */
    LabC_CompensatorOverRobot_DW.obj_f.matlabCodegenIsDeleted = true;
    LabC_CompensatorOverRobot_DW.obj_f.isInitialized = 0L;
    LabC_CompensatorOverRobot_DW.obj_f.matlabCodegenIsDeleted = false;
    LabC_CompensatorOverRobot_DW.objisempty = true;
    LabC_CompensatorOverRobot_DW.obj_f.PinPWM = 2UL;
    obj = &LabC_CompensatorOverRobot_DW.obj_f;
    LabC_CompensatorOverRobot_DW.obj_f.isSetupComplete = false;
    LabC_CompensatorOverRobot_DW.obj_f.isInitialized = 1L;
    obj->MW_PWM_HANDLE = MW_PWM_Open(LabC_CompensatorOverRobot_DW.obj_f.PinPWM,
      0.0, 0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle
      (LabC_CompensatorOverRobot_DW.obj_f.PinPWM);
    MW_PWM_Start(LabC_CompensatorOverRobot_DW.obj_f.MW_PWM_HANDLE);
    LabC_CompensatorOverRobot_DW.obj_f.isSetupComplete = true;
  }

  LabC_CompensatorOverRob_PrevZCX.Sendserialdata_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Memory: '<S2>/last value' */
  LabC_CompensatorOverRobot_DW.lastvalue_PreviousInput =
    LabC_CompensatorOverRobot_P.lastvalue_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S6>/UD' */
  LabC_CompensatorOverRobot_DW.UD_DSTATE =
    LabC_CompensatorOverRobot_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for UnitDelay: '<S7>/UD' */
  LabC_CompensatorOverRobot_DW.UD_DSTATE_m =
    LabC_CompensatorOverRobot_P.DiscreteDerivative_ICPrevScal_g;

  /* InitializeConditions for DiscreteStateSpace: '<S8>/Internal_1_1' */
  LabC_CompensatorOverRobot_DW.Internal_1_1_DSTATE =
    LabC_CompensatorOverRobot_P.Internal_1_1_InitialCondition;

  /* InitializeConditions for DiscreteStateSpace: '<S8>/Internal_2_2' */
  LabC_CompensatorOverRobot_DW.Internal_2_2_DSTATE =
    LabC_CompensatorOverRobot_P.Internal_2_2_InitialCondition;

  /* InitializeConditions for DiscreteStateSpace: '<S8>/Internal_3_3' */
  LabC_CompensatorOverRobot_DW.Internal_3_3_DSTATE =
    LabC_CompensatorOverRobot_P.Internal_3_3_InitialCondition;

  /* InitializeConditions for DiscreteStateSpace: '<S8>/Internal_4_4' */
  LabC_CompensatorOverRobot_DW.Internal_4_4_DSTATE =
    LabC_CompensatorOverRobot_P.Internal_4_4_InitialCondition;

  /* InitializeConditions for DiscreteStateSpace: '<S10>/Internal_1_1' */
  LabC_CompensatorOverRobot_DW.Internal_1_1_DSTATE_l =
    LabC_CompensatorOverRobot_P.Internal_1_1_InitialCondition_o;

  /* InitializeConditions for DiscreteStateSpace: '<S10>/Internal_2_2' */
  LabC_CompensatorOverRobot_DW.Internal_2_2_DSTATE_a =
    LabC_CompensatorOverRobot_P.Internal_2_2_InitialCondition_o;

  /* InitializeConditions for DiscreteStateSpace: '<S10>/Internal_3_3' */
  LabC_CompensatorOverRobot_DW.Internal_3_3_DSTATE_b =
    LabC_CompensatorOverRobot_P.Internal_3_3_InitialCondition_a;
}

/* Model terminate function */
void LabC_CompensatorOverRobot_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S3>/Encoder' */
  if (!LabC_CompensatorOverRobot_DW.obj_k.matlabCodegenIsDeleted) {
    LabC_CompensatorOverRobot_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Encoder' */
  /* Terminate for MATLABSystem: '<S3>/Gyroscope' */
  if (!LabC_CompensatorOverRobot_DW.obj_c.matlabCodegenIsDeleted) {
    LabC_CompensatorOverRobot_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Gyroscope' */

  /* Terminate for MATLABSystem: '<S3>/Accelerometer +-2g, 16 bit signed int' */
  if (!LabC_CompensatorOverRobot_DW.obj_d.matlabCodegenIsDeleted) {
    LabC_CompensatorOverRobot_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Accelerometer +-2g, 16 bit signed int' */
  /* Terminate for Triggered SubSystem: '<S5>/Send serial data' */
  /* Terminate for MATLABSystem: '<S9>/Serial Transmit' */
  if (!LabC_CompensatorOverRobot_DW.obj.matlabCodegenIsDeleted) {
    LabC_CompensatorOverRobot_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S9>/Serial Transmit' */
  /* End of Terminate for SubSystem: '<S5>/Send serial data' */

  /* Terminate for MATLABSystem: '<S42>/Digital Output1' */
  if (!LabC_CompensatorOverRobot_DW.obj_ip.matlabCodegenIsDeleted) {
    LabC_CompensatorOverRobot_DW.obj_ip.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S42>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S42>/PWM' */
  obj = &LabC_CompensatorOverRobot_DW.obj_j;
  if (!LabC_CompensatorOverRobot_DW.obj_j.matlabCodegenIsDeleted) {
    LabC_CompensatorOverRobot_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((LabC_CompensatorOverRobot_DW.obj_j.isInitialized == 1L) &&
        LabC_CompensatorOverRobot_DW.obj_j.isSetupComplete) {
      obj->MW_PWM_HANDLE = MW_PWM_GetHandle
        (LabC_CompensatorOverRobot_DW.obj_j.PinPWM);
      MW_PWM_SetDutyCycle(LabC_CompensatorOverRobot_DW.obj_j.MW_PWM_HANDLE, 0.0);
      obj->MW_PWM_HANDLE = MW_PWM_GetHandle
        (LabC_CompensatorOverRobot_DW.obj_j.PinPWM);
      MW_PWM_Close(LabC_CompensatorOverRobot_DW.obj_j.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S42>/PWM' */

  /* Terminate for MATLABSystem: '<S43>/Digital Output1' */
  if (!LabC_CompensatorOverRobot_DW.obj_i.matlabCodegenIsDeleted) {
    LabC_CompensatorOverRobot_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S43>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S43>/PWM' */
  obj = &LabC_CompensatorOverRobot_DW.obj_f;
  if (!LabC_CompensatorOverRobot_DW.obj_f.matlabCodegenIsDeleted) {
    LabC_CompensatorOverRobot_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((LabC_CompensatorOverRobot_DW.obj_f.isInitialized == 1L) &&
        LabC_CompensatorOverRobot_DW.obj_f.isSetupComplete) {
      obj->MW_PWM_HANDLE = MW_PWM_GetHandle
        (LabC_CompensatorOverRobot_DW.obj_f.PinPWM);
      MW_PWM_SetDutyCycle(LabC_CompensatorOverRobot_DW.obj_f.MW_PWM_HANDLE, 0.0);
      obj->MW_PWM_HANDLE = MW_PWM_GetHandle
        (LabC_CompensatorOverRobot_DW.obj_f.PinPWM);
      MW_PWM_Close(LabC_CompensatorOverRobot_DW.obj_f.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S43>/PWM' */
}
