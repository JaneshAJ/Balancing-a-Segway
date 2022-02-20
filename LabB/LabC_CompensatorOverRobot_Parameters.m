% IMPORTANT
% copy here everything from
% LabB_ObserverAndControllerOverRobot_Parameters.m
% DO NOT LOAD
% you will need to return this file!

% define these variables

close all;
clear all;
clc;

%% From LoadPhysicalParameters;
syms g b_f m_b l_b I_b m_w l_w I_w R_m L_m b_m K_e K_t

PARAMS = [g, b_f, m_b, l_b, I_b, m_w, l_w, I_w, R_m, L_m, b_m, K_e, K_t];
VALUES = [9.8, 0, 0.463, 0.113, 0.00767, 0.026, 0.021, 0.00000573, 4.4, 0, 0, 0.444, 0.47]; 

%% From LoadStateSpaceMatrices;
A_param = sym('A_%d%d', [4 4]);
B_param = sym('B_%d%d', [4 1]);
C_param = sym('C_%d%d', [1 4]);
D_param = sym('D_%d%d', [1 1]);

Alpha = sym('alpha_%d%d', [4 4]);
Beta = sym('beta_%d%d', [4 1]);
Gamma = sym('gamma_%d%d', [4 4]);

Alpha(:,:) = 0;
Alpha(1,2) = 1;
Alpha(2,2) = ((2*K_e*K_t)/(R_m*l_w)) + (b_f/l_w);
Alpha(2,3) = m_b*l_b*g;
Alpha(2,4) = -((2*K_e*K_t)/R_m) - b_f;
Alpha(3,4) = 1;
Alpha(4,2) = -((2*K_e*K_t)/(R_m*l_w)) - (b_f/l_w);
Alpha(4,4) = ((2*K_e*K_t)/R_m) + b_f;

Beta(:,:) = 0;
Beta(2,1) = -2*K_t/R_m;
Beta(4,1) = 2*K_t/R_m;

Gamma(:,:) = 0;
Gamma(1,1) = 1;
Gamma(2,2) = m_b*l_b;
Gamma(2,4) = I_b + m_b*l_b^2;
Gamma(3,3) = 1;
Gamma(4,2) = (I_w/l_w) + l_w*m_b + l_w*m_w;
Gamma(4,4) = m_b * l_b * l_w;

A_param = Gamma\Alpha; %inv(Gamma)*Alpha
B_param = Gamma\Beta; %inv(Gamma)*Beta
C_param = [0, 0, 1, 0 ];
D_param = [0];

% to calculate with full acuracy
A = double(subs(A_param,PARAMS,VALUES));
B = double(subs(B_param,PARAMS,VALUES));
C = double(subs(C_param,PARAMS,VALUES));
D = double(subs(D_param,PARAMS,VALUES));

%% From LabB_ControllerOverSimulator_Continuous_Parameters;

% %% Desired Poles
P = [-843.4002,-5.6422,-4,-1.5];
% 
% %% Calculate Gains : K
K = place(A, B, P);


%% From LabB_ControllerOverSimulator_Discrete_Parameters;


% select the sampling time
 fSamplingPeriod = 0.01;
 
c_sys=ss(A,B,C,D)
d_sys=c2d(c_sys,fSamplingPeriod,'zoh')  
[Ad,Bd,Cd,Dd] = ssdata(d_sys) 
% eig(Ad)


Pd = exp(P*fSamplingPeriod)

Kd = place(Ad, Bd, Pd)



%% From LabB_ObserverOverSimulator_Discrete_Parameters

 Acl = Ad-Bd*Kd

Ad = Acl;
Cd = [1,0,0,0 ; 0,0,1,0];

controller_poles_d = eig(Ad)

% Make Observer poles faster than the controller poles
obs_speed_d = 20;


afPoles_full_d = controller_poles_d*obs_speed_d

afPoles_reduced_d = controller_poles_d(1:3,1)


%% Full Order Observer

Ld = (place(Ad',Cd',afPoles_full_d))'



%% Reduced Order Observer
Cd = [1,0,0,0 ; 0,0,1,0];

p = 1 % Number of accurate measurements
n = 4 % Order of the system

Ad = Acl
Cd = [1,0,0,0 ; 0,0,1,0];
Cacc = [1,0,0,0]
Cinacc = [ 0,0,1,0  ]
Dd = 0
V = [0,1,0,0 ; 0,0,1,0 ; 0,0,0,1]



T = inv([Cacc ; V])

A_ = inv(T) * Ad * T
B_ = inv(T) * Bd
Cacc_ = [eye(p) , zeros(p,n-p)]
Cinacc_ =  Cinacc * T

Ayy_ = A_(1:p,1:p)
AyX_ = A_(1:p,p+1:n)
AXy_ = A_(p+1:n,1:p)
AXX_ = A_(p+1:n,p+1:n)

By_ = Bd(1:p,:)
BX_ = Bd(p+1:n,:)

Cy_ = Cinacc_(:,1:p)
CX_ = Cinacc_(:,p+1:n)

AA = AXX_
CC = [AyX_;CX_]
BB = [AXy_,BX_]
DD = zeros(2,1)

L_red = ( place( AA', CC', afPoles_reduced_d))'

Lacc = L_red(:,1)
Linacc = L_red(:,2)

Md1 = AXX_ - Lacc*AyX_ - Linacc*CX_ 
Md2 = BX_ - Lacc*By_
Md3 = AXy_ - Lacc*Ayy_ - Linacc*Cy_
Md4 = Linacc
Md5 = Lacc
Md6 = T(:, 1:p)
Md7 = T(:, p+1:n)



%% From LabB_ObserverAndControllerOverRobot_Parameters.m
p = P;
p_d = afPoles_full_d;
p_reduced = afPoles_reduced_d;

%% Task 6.6 : Design a module for managing external references
syms z N;
Nud = N;
Nxd = 0;
DC_GAIN = 1;
Cd = [1,0,0,0];

%% Calculate new A,B,C,D

% Ad_tilde = [Ad-Bd*Kd , Bd*Kd ; zeros(4) , Ad - Ld*Cd];
% Bd_tilde = [-Bd*(Kd*Nxd + Nud) ; zeros(4)];
% Cd_tilde = [Cd , zeros(1,4)];
% Dd_tilde = zeros(8);
Ad_tilde = Ad-Bd*Kd;
Bd_tilde = -Bd*(Kd*Nxd + Nud);
Cd_tilde = Cd;
Dd_tilde = zeros(1);
I = eye(4);
%% Steady State Value of y[k]
% Hd_tilde = Cd_tilde * inv(z*eye(8) - Ad_tilde) * Bd_tilde;
Yd_tilde = Cd_tilde * inv(z*I - Ad_tilde) * Bd_tilde * z ;

%% Calculate DC Gain
lim = limit(Yd_tilde,z,1)
% lim = limit((Cd*inv(z*eye(4)-(Ad-Bd*Kd))*Bd)*N*z,z,1)

N_val = double(solve(lim == DC_GAIN, N))

%% Calculate Bd Matrix
Bd_tilde = double(subs(Bd_tilde, N, N_val ));
Nud = N_val;

%% Step Response of new system
% step(ss(Ad-Bd*Kd,(Nxd)*Bd,Cd,Dd, fSamplingPeriod))
sys_fb = ss(Ad_tilde,Bd_tilde,Cd_tilde,Dd_tilde, fSamplingPeriod)
step(sys_fb)

%% Load Robot Parameters
LoadRobotParameters;