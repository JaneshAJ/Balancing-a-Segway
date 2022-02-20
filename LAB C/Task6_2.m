close all;
clear all;
clc;


LoadPhysicalParameters;
LoadStateSpaceMatrices;

% TASK 6.1
% select the sampling time
 fSamplingPeriod = 0.01;
 
 c_sys=ss(A,B,C,D)
 d_sys=c2d(c_sys,fSamplingPeriod,'zoh')  
 
 
[Ad,Bd,Cd,Dd] = ssdata(d_sys)
Cd=C
Dd=D
s = zpk('s')
syms rho
 [zeros, poles, Kgain]=ss2zp(A,B,C,D)
        % zeros =
        %     0.0000
        %    -0.0080
        % poles =
        %          0
        %  -843.3995
        %    -5.6426
        %     5.6787
        % Kgain =
        %  -156.7072
%  Gp=zpk(zeros, poles, Kgain)
%   Gn= -156.71*-s*(-s+0.007976)/(-s* (-s+843.4)* (-s+5.643) *(-s-5.679))
%  s=-5.64
%   rho=evalfr(1+Gp*Gn,-5.64)
%   



%  rlocus(1+Gp*Gn)
%  
% p=[-843, -5.68, -5.64, 0]
% k=place(A,B,p)
% k =   -0.0000  -42.2110  -61.4199   -9.9280
%rlocus(1+Gp*Gn)
 

% Task 6.2


    %  s=tf('s')
C_=[1 1 5 10]
Gp=zpk((C_/(s*eye(4)-A)*B))
Gn=zpk((C_/(-s*eye(4)-A)*B))
 
G_rlocus=minreal(Gp*Gn)
rlocus(G_rlocus)
 % pole location is wanted to be in -5.68 from th root locus as the
 % imaginary part is zero
rho=evalfr(1+Gp*Gn,-0.1)
%rho =0.7758
 poles=[-843,-0.1440+1.02i,-0.1440-1.02i,-0.1]
Q=rho*(C_*C_')
R=1

K=lqr(A,B,R,Q,0)
%K= -0.1007  -42.2618  -61.5086   -9.9435 with lqr function

%K =    0.0000  -22.9832  -33.6190   -5.4047;   -0.0700  -21.8595   -2.4688   -5.1053
% R=1/rho
% C_=[1 0 0 0;0 1 0 0;0 0 5 0;0 0 0 10]
% [K] = lqr(c_sys,C_,R)
%  rlocus(G_rlocus,K)

%  nas=(-s*eye(4))-A
%  nas=det(nas)
%  bs=(Cd/(s*eye(4)-Ad')*Bd)*as
%  nbs=(Cd/(-s*eye(4)-Ad')*Bd)*as
 
% as=zpk(det(s*eye(4))-Ad)
%   
% nas=zpk(det(-s*eye(4))-Ad)
% bs=zpk((Cd/(s*eye(4)-Ad')*Bd)*as)
% nbs=zpk((Cd/(-s*eye(4)-Ad')*Bd)*as)

%  deltas=solve(as*nas+1/r*bs*nbs==0,r) % Here i would need the poles. Then I could use acker to get K to use in rlocus(*,K) as 2nd input

% rlocus(deltas)
% deltas=tf2ss(deltas)
% poles=zpk(deltas)
% solve (1+1/r*tfsys*(-tfsys)==0,r)