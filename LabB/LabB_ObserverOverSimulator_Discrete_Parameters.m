

close all;
clear all;
clc;


LabB_ControllerOverSimulator_Discrete_Parameters;

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

p = 1 % Number of accurate measurements
n = 4 % Order of the system

Ad = Acl
Cd = [1,0,0,0 ; 0,0,1,0];
Cacc = [1,0,0,0]
Dd = 0
Cinacc = [ 0,0,1,0  ]
V = [0,1,0,0 ; 0,0,1,0 ; 0,0,0,1]

T = inv([Cacc ; V])
% T = [1,0,0,0 ; 0,0,1,0 ; 0,1,0,0 ; 0,0,0,1]
% T = [Cacc ; Cinacc]
% T = eye(n)

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

eig(AA)

% sys_L = ss(AA,BB,CC,DD)


% L = ( place( AA', CC', [0 -854 -5.6]))'
L_red = ( place( AA', CC', afPoles_reduced_d))'

Lacc = L_red(:,1)
% Linacc = L(:,p+1:n)
Linacc = L_red(:,2)

Md1 = AXX_ - Lacc*AyX_ - Linacc*CX_ 
Md2 = BX_ - Lacc*By_
Md3 = AXy_ - Lacc*Ayy_ - Linacc*Cy_
Md4 = Linacc
Md5 = Lacc
Md6 = T(:, 1:p)
Md7 = T(:, p+1:n)





% PID values from PID tuner app


% kP= -9492;
% kI= 114.8;
% kD= 28.69;
% kP= -250;
% kI= -2;
% kD=0;

%These vaulues addded by MR 18.12.2020
kP= -558.3481
kI= -13776.6318
kD= -0.87072