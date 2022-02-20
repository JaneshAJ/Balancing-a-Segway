close all;
clear all;
clc;


LoadPhysicalParameters;
LoadStateSpaceMatrices;

%% TASK 6.1
% select the sampling time
 fSamplingPeriod = 0.01;
 
 c_sys=ss(A,B,C,D)
 d_sys=c2d(c_sys,fSamplingPeriod,'zoh')  
[Ad,Bd,Cd,Dd] = ssdata(d_sys) 

%% Task 6.2

% syms  r
% s=tf('s')
% 
% Gp=zpk((C/(s*eye(4)-A)*B))
% Gn=zpk((C/(-s*eye(4)-A)*B))
% G_rlocus=minreal(Gp*Gn)
% rlocus(G_rlocus)


s = zpk('s')
syms rho
C_=[1 1 5 10]
Gp=zpk((C_/(s*eye(4)-A)*B))
Gn=zpk((C_/(-s*eye(4)-A)*B))
 
G_rlocus=minreal(Gp*Gn)
rlocus(G_rlocus)
 % pole location is wanted to be in -0.1 from th root locus as the
 % imaginary part is zero

rho=evalfr(1+Gp*Gn,-0.1)
%rho =0.7758

 % poles=[-843,-0.1440+1.02i,-0.1440-1.02i,-0.1] This ws used for another
 % test to calculate the K
Q=rho*(C_*C_')
R=1

K=lqr(A,B,R,Q,0)
%K= -0.1007  -42.2618  -61.5086   -9.9435 with lqr function

%% Set Q,R,N Values
% rho = 1
% W = C_' * C_
% Q = rho * W
% R = 1
% N = 0

