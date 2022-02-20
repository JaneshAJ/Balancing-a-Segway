clear all;
clc;

% DO NOT MODIFY THIS!
LoadRobotParameters

% deletes auto generated files
% you can remove this if you want
prep

% you should modify this to match your design!
% note: 0.005 is the fastest sampling time with the
% default mpu5060 library settings that your sensors can output
fSamplingPeriod			= 0.05; 

% set the discrete feedback gain here
K = [-1 -1 -1 -1];

% set the compensator gains
% set all to 0 to disable reference tracking
Nud = 0;
Nxd = 0;

