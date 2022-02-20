/*
 * LabC_CompensatorOverRobot.h
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

#ifndef RTW_HEADER_LabC_CompensatorOverRobot_h_
#define RTW_HEADER_LabC_CompensatorOverRobot_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef LabC_CompensatorOverRobot_COMMON_INCLUDES_
#define LabC_CompensatorOverRobot_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#include "MPU6050wrapper.h"
#include "encoder_arduino.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif                          /* LabC_CompensatorOverRobot_COMMON_INCLUDES_ */

#include "LabC_CompensatorOverRobot_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_zcfcn.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T dataIn[8];
  real_T Gain8[4];                     /* '<S5>/Gain8' */
  real_T FromWs;                       /* '<S4>/FromWs' */
  real_T converttometers;              /* '<S2>/convert to meters' */
  real_T lastvalue;                    /* '<S2>/last value' */
  real_T Sum1;                         /* '<S2>/Sum1' */
  real_T Sum;                          /* '<S2>/Sum' */
  real_T Diff;                         /* '<S6>/Diff' */
  real_T Diff_d;                       /* '<S7>/Diff' */
  real_T Sum1_o;                       /* '<S8>/Sum1' */
  real_T Sum2;                         /* '<S8>/Sum2' */
  real_T Sum3;                         /* '<S8>/Sum3' */
  real_T Sum4;                         /* '<S8>/Sum4' */
  real_T Sum1_g;                       /* '<S10>/Sum1' */
  real_T Sum2_a;                       /* '<S10>/Sum2' */
  real_T Sum3_h;                       /* '<S10>/Sum3' */
  real_T Add2[4];                      /* '<S5>/Add2' */
  real_T Product1;                     /* '<S1>/Product1' */
  real_T u0Hzdatasendtrigger;          /* '<S5>/10Hz data send trigger' */
  real_T Add[3];                       /* '<S5>/Add' */
  real_T Gain10;                       /* '<S5>/Gain10' */
  real_T Gain7[4];                     /* '<S5>/Gain7' */
  real_T Add3[4];                      /* '<S5>/Add3' */
  real_T Gain3;                        /* '<S1>/Gain3' */
  real_T rtb_Add1_idx_0;
  real_T rtb_Add1_idx_1;
  real_T rtb_Add1_idx_2;
  real_T Internal_3_3;                 /* '<S10>/Internal_3_3' */
  real_T Internal_3_2;                 /* '<S10>/Internal_3_2' */
  real_T Internal_3_1;                 /* '<S10>/Internal_3_1' */
} B_LabC_CompensatorOverRobot_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_o_T obj; /* '<S9>/Serial Transmit' */
  codertarget_arduinobase_inter_T obj_f;/* '<S43>/PWM' */
  codertarget_arduinobase_inter_T obj_j;/* '<S42>/PWM' */
  soMPU6050Accel_LabC_Compensat_T obj_d;
                              /* '<S3>/Accelerometer +-2g, 16 bit signed int' */
  Encoder_arduino_LabC_Compensa_T obj_k;/* '<S3>/Encoder' */
  soMPU6050Gyro_LabC_Compensato_T obj_c;/* '<S3>/Gyroscope' */
  codertarget_arduinobase_block_T obj_i;/* '<S43>/Digital Output1' */
  codertarget_arduinobase_block_T obj_ip;/* '<S42>/Digital Output1' */
  real_T UD_DSTATE;                    /* '<S6>/UD' */
  real_T UD_DSTATE_m;                  /* '<S7>/UD' */
  real_T Internal_1_1_DSTATE;          /* '<S8>/Internal_1_1' */
  real_T Internal_2_2_DSTATE;          /* '<S8>/Internal_2_2' */
  real_T Internal_3_3_DSTATE;          /* '<S8>/Internal_3_3' */
  real_T Internal_4_4_DSTATE;          /* '<S8>/Internal_4_4' */
  real_T Internal_1_1_DSTATE_l;        /* '<S10>/Internal_1_1' */
  real_T Internal_2_2_DSTATE_a;        /* '<S10>/Internal_2_2' */
  real_T Internal_3_3_DSTATE_b;        /* '<S10>/Internal_3_3' */
  real_T lastvalue_PreviousInput;      /* '<S2>/last value' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK;                      /* '<S4>/FromWs' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<S1>/To Workspace' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<S1>/To Workspace1' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                /* '<S1>/To Workspace2' */

  struct {
    void *LoggedData;
  } ToWorkspace3_PWORK;                /* '<S1>/To Workspace3' */

  struct {
    int_T PrevIndex;
  } FromWs_IWORK;                      /* '<S4>/FromWs' */

  boolean_T objisempty;                /* '<S43>/PWM' */
  boolean_T objisempty_l;              /* '<S43>/Digital Output1' */
  boolean_T objisempty_k;              /* '<S42>/PWM' */
  boolean_T objisempty_e;              /* '<S42>/Digital Output1' */
  boolean_T objisempty_j;              /* '<S3>/Gyroscope' */
  boolean_T objisempty_d;              /* '<S3>/Encoder' */
  boolean_T objisempty_m;     /* '<S3>/Accelerometer +-2g, 16 bit signed int' */
  boolean_T objisempty_o;              /* '<S9>/Serial Transmit' */
} DW_LabC_CompensatorOverRobot_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Sendserialdata_Trig_ZCE;  /* '<S5>/Send serial data' */
} PrevZCX_LabC_CompensatorOverR_T;

/* Parameters (default storage) */
struct P_LabC_CompensatorOverRobot_T_ {
  real_T Ad[16];                       /* Variable: Ad
                                        * Referenced by: '<S5>/Gain7'
                                        */
  real_T Bd[4];                        /* Variable: Bd
                                        * Referenced by: '<S5>/Gain8'
                                        */
  real_T Cd[4];                        /* Variable: Cd
                                        * Referenced by: '<S5>/Gain10'
                                        */
  real_T Kd[4];                        /* Variable: Kd
                                        * Referenced by: '<S1>/controller'
                                        */
  real_T Ld[8];                        /* Variable: Ld
                                        * Referenced by: '<S5>/Gain9'
                                        */
  real_T Md1[9];                       /* Variable: Md1
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Md2[3];                       /* Variable: Md2
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T Md3[3];                       /* Variable: Md3
                                        * Referenced by: '<S5>/Gain2'
                                        */
  real_T Md4[3];                       /* Variable: Md4
                                        * Referenced by: '<S5>/Gain3'
                                        */
  real_T Md5[3];                       /* Variable: Md5
                                        * Referenced by: '<S5>/Gain4'
                                        */
  real_T Md6[4];                       /* Variable: Md6
                                        * Referenced by: '<S5>/Gain5'
                                        */
  real_T Md7[12];                      /* Variable: Md7
                                        * Referenced by: '<S5>/Gain6'
                                        */
  real_T Nud;                          /* Variable: Nud
                                        * Referenced by: '<S1>/Gain4'
                                        */
  real_T Nxd;                          /* Variable: Nxd
                                        * Referenced by: '<S1>/Gain3'
                                        */
  real_T acc_LSB_per_g;                /* Variable: acc_LSB_per_g
                                        * Referenced by:
                                        *   '<S49>/Constant'
                                        *   '<S50>/Constant'
                                        */
  real_T acc_z_offset;                 /* Variable: acc_z_offset
                                        * Referenced by: '<S45>/Constant'
                                        */
  real_T equ_offset;                   /* Variable: equ_offset
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T fSamplingPeriod;              /* Variable: fSamplingPeriod
                                        * Referenced by: '<S2>/integrate, sign from geometry'
                                        */
  real_T fWheelRadius;                 /* Variable: fWheelRadius
                                        * Referenced by: '<S2>/convert to meters'
                                        */
  real_T gyro_LSB_per_deg;             /* Variable: gyro_LSB_per_deg
                                        * Referenced by: '<S48>/Scaling factor from datasheet'
                                        */
  real_T iNumberOfEncoderSteps;        /* Variable: iNumberOfEncoderSteps
                                        * Referenced by: '<S2>/convert to  radians'
                                        */
  real32_T acc_y_offset;               /* Variable: acc_y_offset
                                        * Referenced by: '<S45>/Constant1'
                                        */
  real32_T gyro_x_offset;              /* Variable: gyro_x_offset
                                        * Referenced by: '<S44>/Constant'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S6>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScal_g;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_g
                               * Referenced by: '<S7>/UD'
                               */
  real32_T M1V4LeftMotorDriverPWM6D8FST_Vs;
                              /* Mask Parameter: M1V4LeftMotorDriverPWM6D8FST_Vs
                               * Referenced by: '<S42>/Saturation -Vsupply to Vsupply'
                               */
  real32_T M1V4MiddleMotorDriverPWM2D5FST_;
                              /* Mask Parameter: M1V4MiddleMotorDriverPWM2D5FST_
                               * Referenced by: '<S43>/Saturation -Vsupply to Vsupply'
                               */
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<S9>/Serial Transmit'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S46>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S47>/Constant'
                                        */
  real_T lastvalue_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S2>/last value'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S41>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.98
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T u81_Gain;                     /* Expression: -9.81
                                        * Referenced by: '<S50>/+ - 9.81'
                                        */
  real_T u81_Gain_m;                   /* Expression: 9.81
                                        * Referenced by: '<S49>/+9.81'
                                        */
  real_T Gain_Gain_g;                  /* Expression: -1
                                        * Referenced by: '<S40>/Gain'
                                        */
  real_T Gain1_Gain_a;                 /* Expression: 0.02
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S6>/TSamp'
                                        */
  real_T TSamp_WtEt_p;                 /* Computed Parameter: TSamp_WtEt_p
                                        * Referenced by: '<S7>/TSamp'
                                        */
  real_T Internal_1_1_A;               /* Computed Parameter: Internal_1_1_A
                                        * Referenced by: '<S8>/Internal_1_1'
                                        */
  real_T Internal_1_1_C;               /* Computed Parameter: Internal_1_1_C
                                        * Referenced by: '<S8>/Internal_1_1'
                                        */
  real_T Internal_1_1_InitialCondition;/* Expression: 0
                                        * Referenced by: '<S8>/Internal_1_1'
                                        */
  real_T Internal_1_2_InitialCondition;/* Expression: 0
                                        * Referenced by: '<S8>/Internal_1_2'
                                        */
  real_T Internal_1_3_InitialCondition;/* Expression: 0
                                        * Referenced by: '<S8>/Internal_1_3'
                                        */
  real_T Internal_1_4_InitialCondition;/* Expression: 0
                                        * Referenced by: '<S8>/Internal_1_4'
                                        */
  real_T Internal_2_1_InitialCondition;/* Expression: 0
                                        * Referenced by: '<S8>/Internal_2_1'
                                        */
  real_T Internal_2_2_A;               /* Computed Parameter: Internal_2_2_A
                                        * Referenced by: '<S8>/Internal_2_2'
                                        */
  real_T Internal_2_2_C;               /* Computed Parameter: Internal_2_2_C
                                        * Referenced by: '<S8>/Internal_2_2'
                                        */
  real_T Internal_2_2_InitialCondition;/* Expression: 0
                                        * Referenced by: '<S8>/Internal_2_2'
                                        */
  real_T Internal_2_3_InitialCondition;/* Expression: 0
                                        * Referenced by: '<S8>/Internal_2_3'
                                        */
  real_T Internal_2_4_InitialCondition;/* Expression: 0
                                        * Referenced by: '<S8>/Internal_2_4'
                                        */
  real_T Internal_3_1_InitialCondition;/* Expression: 0
                                        * Referenced by: '<S8>/Internal_3_1'
                                        */
  real_T Internal_3_2_InitialCondition;/* Expression: 0
                                        * Referenced by: '<S8>/Internal_3_2'
                                        */
  real_T Internal_3_3_A;               /* Computed Parameter: Internal_3_3_A
                                        * Referenced by: '<S8>/Internal_3_3'
                                        */
  real_T Internal_3_3_C;               /* Computed Parameter: Internal_3_3_C
                                        * Referenced by: '<S8>/Internal_3_3'
                                        */
  real_T Internal_3_3_InitialCondition;/* Expression: 0
                                        * Referenced by: '<S8>/Internal_3_3'
                                        */
  real_T Internal_3_4_InitialCondition;/* Expression: 0
                                        * Referenced by: '<S8>/Internal_3_4'
                                        */
  real_T Internal_4_1_InitialCondition;/* Expression: 0
                                        * Referenced by: '<S8>/Internal_4_1'
                                        */
  real_T Internal_4_2_InitialCondition;/* Expression: 0
                                        * Referenced by: '<S8>/Internal_4_2'
                                        */
  real_T Internal_4_3_InitialCondition;/* Expression: 0
                                        * Referenced by: '<S8>/Internal_4_3'
                                        */
  real_T Internal_4_4_A;               /* Computed Parameter: Internal_4_4_A
                                        * Referenced by: '<S8>/Internal_4_4'
                                        */
  real_T Internal_4_4_C;               /* Computed Parameter: Internal_4_4_C
                                        * Referenced by: '<S8>/Internal_4_4'
                                        */
  real_T Internal_4_4_InitialCondition;/* Expression: 0
                                        * Referenced by: '<S8>/Internal_4_4'
                                        */
  real_T Internal_1_1_A_e;             /* Computed Parameter: Internal_1_1_A_e
                                        * Referenced by: '<S10>/Internal_1_1'
                                        */
  real_T Internal_1_1_C_a;             /* Computed Parameter: Internal_1_1_C_a
                                        * Referenced by: '<S10>/Internal_1_1'
                                        */
  real_T Internal_1_1_InitialCondition_o;/* Expression: 0
                                          * Referenced by: '<S10>/Internal_1_1'
                                          */
  real_T Internal_1_2_InitialCondition_h;/* Expression: 0
                                          * Referenced by: '<S10>/Internal_1_2'
                                          */
  real_T Internal_1_3_InitialCondition_n;/* Expression: 0
                                          * Referenced by: '<S10>/Internal_1_3'
                                          */
  real_T Internal_2_1_InitialCondition_j;/* Expression: 0
                                          * Referenced by: '<S10>/Internal_2_1'
                                          */
  real_T Internal_2_2_A_h;             /* Computed Parameter: Internal_2_2_A_h
                                        * Referenced by: '<S10>/Internal_2_2'
                                        */
  real_T Internal_2_2_C_o;             /* Computed Parameter: Internal_2_2_C_o
                                        * Referenced by: '<S10>/Internal_2_2'
                                        */
  real_T Internal_2_2_InitialCondition_o;/* Expression: 0
                                          * Referenced by: '<S10>/Internal_2_2'
                                          */
  real_T Internal_2_3_InitialCondition_e;/* Expression: 0
                                          * Referenced by: '<S10>/Internal_2_3'
                                          */
  real_T Internal_3_1_InitialCondition_c;/* Expression: 0
                                          * Referenced by: '<S10>/Internal_3_1'
                                          */
  real_T Internal_3_2_InitialCondition_i;/* Expression: 0
                                          * Referenced by: '<S10>/Internal_3_2'
                                          */
  real_T Internal_3_3_A_i;             /* Computed Parameter: Internal_3_3_A_i
                                        * Referenced by: '<S10>/Internal_3_3'
                                        */
  real_T Internal_3_3_C_f;             /* Computed Parameter: Internal_3_3_C_f
                                        * Referenced by: '<S10>/Internal_3_3'
                                        */
  real_T Internal_3_3_InitialCondition_a;/* Expression: 0
                                          * Referenced by: '<S10>/Internal_3_3'
                                          */
  real_T u0Hzdatasendtrigger_Amplitude;/* Expression: 1
                                        * Referenced by: '<S5>/10Hz data send trigger'
                                        */
  real_T u0Hzdatasendtrigger_Frequency;/* Expression: 10
                                        * Referenced by: '<S5>/10Hz data send trigger'
                                        */
  real32_T Constant_Value_n;           /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S9>/Constant'
                                        */
  real32_T SaturationVsupplytoVsupply_Lowe;
                          /* Computed Parameter: SaturationVsupplytoVsupply_Lowe
                           * Referenced by: '<S42>/Saturation -Vsupply to Vsupply'
                           */
  real32_T conversiontodutycycleconverttou;
                          /* Computed Parameter: conversiontodutycycleconverttou
                           * Referenced by: '<S42>/conversion to dutycycle (convert to uint8, overflow will provide reverse polairty magnitued)'
                           */
  real32_T SaturationVsupplytoVsupply_Lo_l;
                          /* Computed Parameter: SaturationVsupplytoVsupply_Lo_l
                           * Referenced by: '<S43>/Saturation -Vsupply to Vsupply'
                           */
  real32_T conversiontodutycycleconvertt_c;
                          /* Computed Parameter: conversiontodutycycleconvertt_c
                           * Referenced by: '<S43>/conversion to dutycycle (convert to uint8, overflow will provide reverse polairty magnitued)'
                           */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<S5>/Manual Switch'
                               */
  uint8_T ManualSwitch1_CurrentSetting;
                             /* Computed Parameter: ManualSwitch1_CurrentSetting
                              * Referenced by: '<S5>/Manual Switch1'
                              */
};

/* Real-time Model Data Structure */
struct tag_RTM_LabC_CompensatorOverR_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

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
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_LabC_CompensatorOverRobot_T LabC_CompensatorOverRobot_P;

/* Block signals (default storage) */
extern B_LabC_CompensatorOverRobot_T LabC_CompensatorOverRobot_B;

/* Block states (default storage) */
extern DW_LabC_CompensatorOverRobot_T LabC_CompensatorOverRobot_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_LabC_CompensatorOverR_T LabC_CompensatorOverRob_PrevZCX;

/* Model entry point functions */
extern void LabC_CompensatorOverRobot_initialize(void);
extern void LabC_CompensatorOverRobot_step(void);
extern void LabC_CompensatorOverRobot_terminate(void);

/* Real-time Model object */
extern RT_MODEL_LabC_CompensatorOver_T *const LabC_CompensatorOverRobot_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S6>/Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Cast To Single4' : Eliminate redundant data type conversion
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
 * '<Root>' : 'LabC_CompensatorOverRobot'
 * '<S1>'   : 'LabC_CompensatorOverRobot/controller'
 * '<S2>'   : 'LabC_CompensatorOverRobot/measurement filter'
 * '<S3>'   : 'LabC_CompensatorOverRobot/plant'
 * '<S4>'   : 'LabC_CompensatorOverRobot/reference'
 * '<S5>'   : 'LabC_CompensatorOverRobot/controller/observer'
 * '<S6>'   : 'LabC_CompensatorOverRobot/controller/observer/Discrete Derivative'
 * '<S7>'   : 'LabC_CompensatorOverRobot/controller/observer/Discrete Derivative '
 * '<S8>'   : 'LabC_CompensatorOverRobot/controller/observer/LTI System'
 * '<S9>'   : 'LabC_CompensatorOverRobot/controller/observer/Send serial data'
 * '<S10>'  : 'LabC_CompensatorOverRobot/controller/observer/integrator'
 * '<S11>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_1_1'
 * '<S12>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_1_2'
 * '<S13>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_1_3'
 * '<S14>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_1_4'
 * '<S15>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_2_1'
 * '<S16>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_2_2'
 * '<S17>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_2_3'
 * '<S18>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_2_4'
 * '<S19>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_3_1'
 * '<S20>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_3_2'
 * '<S21>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_3_3'
 * '<S22>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_3_4'
 * '<S23>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_4_1'
 * '<S24>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_4_2'
 * '<S25>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_4_3'
 * '<S26>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/IO Delay_4_4'
 * '<S27>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/Input Delay'
 * '<S28>'  : 'LabC_CompensatorOverRobot/controller/observer/LTI System/Output Delay'
 * '<S29>'  : 'LabC_CompensatorOverRobot/controller/observer/integrator/IO Delay_1_1'
 * '<S30>'  : 'LabC_CompensatorOverRobot/controller/observer/integrator/IO Delay_1_2'
 * '<S31>'  : 'LabC_CompensatorOverRobot/controller/observer/integrator/IO Delay_1_3'
 * '<S32>'  : 'LabC_CompensatorOverRobot/controller/observer/integrator/IO Delay_2_1'
 * '<S33>'  : 'LabC_CompensatorOverRobot/controller/observer/integrator/IO Delay_2_2'
 * '<S34>'  : 'LabC_CompensatorOverRobot/controller/observer/integrator/IO Delay_2_3'
 * '<S35>'  : 'LabC_CompensatorOverRobot/controller/observer/integrator/IO Delay_3_1'
 * '<S36>'  : 'LabC_CompensatorOverRobot/controller/observer/integrator/IO Delay_3_2'
 * '<S37>'  : 'LabC_CompensatorOverRobot/controller/observer/integrator/IO Delay_3_3'
 * '<S38>'  : 'LabC_CompensatorOverRobot/controller/observer/integrator/Input Delay'
 * '<S39>'  : 'LabC_CompensatorOverRobot/controller/observer/integrator/Output Delay'
 * '<S40>'  : 'LabC_CompensatorOverRobot/measurement filter/acc estimation'
 * '<S41>'  : 'LabC_CompensatorOverRobot/plant/Degrees to Radians'
 * '<S42>'  : 'LabC_CompensatorOverRobot/plant/M1V4 Left Motor Driver PWM6, D8 FST'
 * '<S43>'  : 'LabC_CompensatorOverRobot/plant/M1V4 Middle Motor Driver PWM2, D5 FST'
 * '<S44>'  : 'LabC_CompensatorOverRobot/plant/convert gyro to deg//s'
 * '<S45>'  : 'LabC_CompensatorOverRobot/plant/convert to SI'
 * '<S46>'  : 'LabC_CompensatorOverRobot/plant/M1V4 Left Motor Driver PWM6, D8 FST/Compare To Zero'
 * '<S47>'  : 'LabC_CompensatorOverRobot/plant/M1V4 Middle Motor Driver PWM2, D5 FST/Compare To Zero'
 * '<S48>'  : 'LabC_CompensatorOverRobot/plant/convert gyro to deg//s/convert to deg//s'
 * '<S49>'  : 'LabC_CompensatorOverRobot/plant/convert to SI/convert to SI1'
 * '<S50>'  : 'LabC_CompensatorOverRobot/plant/convert to SI/convert to SI2'
 */
#endif                             /* RTW_HEADER_LabC_CompensatorOverRobot_h_ */
