close all;
clear all;
clc;

%% Load Controller Gain Parameters(K)
LabB_ControllerOverSimulator_Continuous_Parameters;

% State Space : Closed Loop System using gains
Acl = A-B*K;

A = Acl;
C = [1,0,0,0 ; 0,0,1,0];

controller_poles = sort(eig(A));
controller_poles = sort(controller_poles,'descend');

% Make Observer poles faster than the controller poles
obs_speed = 20;

afPoles_full = controller_poles*obs_speed;
afPoles_reduced = controller_poles(1:3,1)*obs_speed;

%% Full Order Observer

L = (place(A',C',afPoles_full))';

%% Reduced Order Observer

p = 1; % Number of accurate measurements
n = 4; % Order of the system

A = Acl;
C = [1,0,0,0 ; 0,0,1,0];
Cacc = [1,0,0,0];
D = 0;
Cinacc = [ 0,0,1,0  ];
V = [0,1,0,0 ; 0,0,1,0 ; 0,0,0,1];

T = inv([Cacc ; V]);

A_ = inv(T) * A * T;
B_ = inv(T) * B;
Cacc_ = [eye(p) , zeros(p,n-p)];
Cinacc_ =  Cinacc * T;

Ayy_ = A_(1:p,1:p);
AyX_ = A_(1:p,p+1:n);
AXy_ = A_(p+1:n,1:p);
AXX_ = A_(p+1:n,p+1:n);

By_ = B(1:p,:);
BX_ = B(p+1:n,:);

Cy_ = Cinacc_(:,1:p);
CX_ = Cinacc_(:,p+1:n);

AA = AXX_;
CC = [AyX_;CX_];
% BB = [AXy_,BX_]
% DD = zeros(2,1)

% eig(AA)

% sys_L = ss(AA,BB,CC,DD)


% L = ( place( AA', CC', [0 -854 -5.6]))'
L_red = ( place( AA', CC', afPoles_reduced))';

Lacc = L_red(:,1);
% Linacc = L(:,p+1:n)
Linacc = L_red(:,2);

M1 = AXX_ - Lacc*AyX_ - Linacc*CX_ ;
M2 = BX_ - Lacc*By_;
M3 = AXy_ - Lacc*Ayy_ - Linacc*Cy_;
M4 = Linacc;
M5 = Lacc;
M6 = T(:, 1:p);
M7 = T(:, p+1:n);

%% PID Parameters
% kP= -50;
% kI= 0;
% kD= 0;

% kP= -250;
% kI= -2;
% kD= 0;


% These values added 18.12.2020 by MR
kP= -558.3481
kI= -13776.6318
kD= -0.87072
%Either compute or load the following variables in this script:
% A = [];
% B = [];
% C = [];
% D = [];
% 
% kP = ;
% kI = ;
% kD = ;
% 
% M1 = ;
% M2 = ;
% M3 = ;
% M4 = ;
% M5 = ;
% M6 = ;
% M7 = ;
% 
% L = ;


