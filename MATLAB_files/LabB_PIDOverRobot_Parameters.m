clear all;
close all;
clc;

% DO NOT MODIFY THIS!
LoadRobotParameters

% if you want, modify this
fSamplingPeriod			= 0.005; % note: 0.005 is the fastest sampling time with the default mpu5060 library settings

% load the PID values (put your values here)
kP = -250;
kI = -2;
kD = 0;
