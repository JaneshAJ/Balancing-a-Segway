close all;
clear all;
clc;

LoadPhysicalParameters;
LoadStateSpaceMatrices;

% E = eig(A)
% sys= ss(A, B, C, D);
% isstable(sys)
% zpk(sys)
% tf(sys)
% step(sys)

% %% Desired Poles
P = [-843.4002,-5.6422,-4,-1.5];
% 
% %% Calculate Gains : K
K = place(A, B, P);
%% 6_2
% poles=[-843,-5.68,-0.5,0]
% poles=[-843,-0.1440+1.02i,-0.1440-1.02i,-0.1]
% K=place(A,B,poles)
% K=[-0.1007  -42.2618  -61.5086   -9.9435]

% Acl= A-B*K;
% syscl= ss(Acl, B, C, D);
% isstable(syscl)
% zpk(syscl)
% tf(syscl)
% step(syscl)
% stepinfo(syscl)
