%% Task 6.3
close all;
clear all;
clc;

LoadPhysicalParameters;
LoadStateSpaceMatrices;

% select the sampling time
% fSamplingFreq = 14; % Min for stability is 5 Hz
fSamplingPeriod = 0.067;
fSamplingFreq = 1/fSamplingPeriod;

c_sys=ss(A,B,C,D)
d_sys=c2d(c_sys,fSamplingPeriod,'zoh')  
[Ad,Bd,Cd,Dd] = ssdata(d_sys) 

%% Set C_
C_ = [5, 1, 10, 2]

%% Set Q,R,N Values
rho = 0.7758
W = C_' * C_
Q = rho * W
R = 1
N = 0

%% Calculate Gains : K
[Kd,S,e] = dlqr(Ad,Bd,Q,R,N) 

% New Ad_cl
Ad_cl= Ad-Bd*Kd

%% Make Observer poles faster than the controller poles
controller_poles_d = eig(Ad_cl); 

% This is chi
obs_speed_d = 6;

afPoles_full_d = controller_poles_d.^obs_speed_d
afPoles_reduced_d = controller_poles_d(1:3,1)


%% Full Order Observer
Cd = [1,0,0,0 ; 0,0,1,0];
Ld = (place(Ad',Cd',afPoles_full_d))'

%% Reduced Order Observer

p = 1 % Number of accurate measurements
n = 4 % Order of the system

Ad = Ad
Cd = [1,0,0,0 ; 0,0,1,0];
Cacc = [1,0,0,0]
Dd = 0
Cinacc = [ 0,0,1,0  ]

poles = afPoles_reduced_d
[Md1,Md2,Md3,Md4,Md5,Md6,Md7,Ld_red] = CalcReducedObserver(Ad,Bd,Cd,Dd,Cacc,Cinacc,poles)
% V = [0,1,0,0 ; 0,0,1,0 ; 0,0,0,1]
% 
% T = inv([Cacc ; V])
% 
% A_ = inv(T) * Ad * T
% B_ = inv(T) * Bd
% Cacc_ = [eye(p) , zeros(p,n-p)]
% Cinacc_ =  Cinacc * T
% 
% Ayy_ = A_(1:p,1:p)
% AyX_ = A_(1:p,p+1:n)
% AXy_ = A_(p+1:n,1:p)
% AXX_ = A_(p+1:n,p+1:n)
% 
% By_ = Bd(1:p,:)
% BX_ = Bd(p+1:n,:)
% 
% Cy_ = Cinacc_(:,1:p)
% CX_ = Cinacc_(:,p+1:n)
% 
% AA = AXX_
% CC = [AyX_;CX_]
% BB = [AXy_,BX_]
% DD = zeros(2,1)
% 
% eig(AA)
% 
% % sys_L = ss(AA,BB,CC,DD)
% 
% 
% % L = ( place( AA', CC', [0 -854 -5.6]))'
% L_red = ( place( AA', CC', afPoles_reduced_d))'
% 
% Lacc = L_red(:,1)
% % Linacc = L(:,p+1:n)
% Linacc = L_red(:,2)
% 
% Md1 = AXX_ - Lacc*AyX_ - Linacc*CX_ 
% Md2 = BX_ - Lacc*By_
% Md3 = AXy_ - Lacc*Ayy_ - Linacc*Cy_
% Md4 = Linacc
% Md5 = Lacc
% Md6 = T(:, 1:p)
% Md7 = T(:, p+1:n)


%% Run Simulation
system_name = 'LabB_ObserverAndControllerOverSimulator_Discrete';
open_system([system_name '.slx'])
saveas(get_param(system_name,'Handle'),[system_name '_diagram.eps']);
sim(system_name)
save_system([system_name '.slx'])
% close_system(SYSTEM_NAME)

%% Plot
afFigurePosition = [1 1 10 6];

OUTPUT_PATH = 'output/T6_5/';
RUN_NAME = [OUTPUT_PATH 'T6_5'];

% x_w
plot_name = 'x_w';
plot_filepath = [RUN_NAME '_' plot_name];
x_values = x_w.time;
y_values = x_w.signals.values;
plot_title = plot_name;
x_unit = 'time';
y_unit = 'meters';
plot_data( x_values, y_values, plot_filepath, plot_title, x_unit, y_unit, afFigurePosition)
legend('Measured','Full Observer', 'Partial Observer')
grid on

% theta_b
figure(2)
plot_name = 'theta_b';
plot_filepath = [RUN_NAME '_' plot_name];
x_values = theta_b.time;
y_values = theta_b.signals.values;
plot_title = '\theta_b';
x_unit = 'time';
y_unit = 'rad';
plot_data( x_values, y_values, plot_filepath, plot_title, x_unit, y_unit, afFigurePosition)
legend('Measured','Full Observer', 'Partial Observer')
grid on