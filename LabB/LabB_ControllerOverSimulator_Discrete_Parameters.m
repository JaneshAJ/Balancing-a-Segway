close all;
clear all;
clc;


LabB_ControllerOverSimulator_Continuous_Parameters;

% select the sampling time
fSamplingPeriod = 0.005;

c_sys=ss(A,B,C,D)
d_sys=c2d(c_sys,fSamplingPeriod,'zoh')  
[Ad,Bd,Cd,Dd] = ssdata(d_sys) 
eig(Ad)

P = [-843.4002,-5.6422,-4,-1.5]

Pd = exp(P*fSamplingPeriod)

Kd = place(Ad, Bd, Pd)
