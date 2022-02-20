%% Task 6.3
close all;
clear all;
clc;

LoadPhysicalParameters;
LoadStateSpaceMatrices;

% select the sampling time
fSamplingFreq = 5 % Min for stability is 5 Hz
fSamplingPeriod = (1/fSamplingFreq);

c_sys=ss(A,B,C,D)
d_sys=c2d(c_sys,fSamplingPeriod,'zoh')  
[Ad,Bd,Cd,Dd] = ssdata(d_sys) 

%% Set C_
C_ = [5, 1, 10, 2]

%% Set Q,R,N Values
rho = 0.7758 % Chosen value rho = 0.7758
W = C_' * C_
Q = rho * W
R = 1
N = 0

%% Calculate Gains : K
[Kd,S,e] = dlqr(Ad,Bd,Q,R,N) 


%% Run System Simulation
system_name = 'LabB_ControllerOverSimulator_Discrete';
open_system([system_name '.slx'])
saveas(get_param(system_name,'Handle'),[system_name '_diagram.eps']);
sim(system_name)
save_system([system_name '.slx'])
% close_system(SYSTEM_NAME)

%% Plot
afFigurePosition = [1 1 10 6];

OUTPUT_PATH = 'output/';
RUN_NAME = [OUTPUT_PATH 'T6_3'];

% v_m : Motor Voltage
plot_name = 'v_m';
plot_filepath = [RUN_NAME '_' plot_name];
x_values = u.time;
y_values = u.signals.values;
plot_title = plot_name;
x_unit = 'time';
y_unit = 'volts';
plot_data( x_values, y_values, plot_filepath, plot_title, x_unit, y_unit, afFigurePosition)

% theta_b
figure(2)
plot_name = 'theta_b';
plot_filepath = [RUN_NAME '_' plot_name];
x_values = x.time;
y_values = x.signals.values(:,3);
plot_title = plot_name;
x_unit = 'time';
y_unit = 'rad';
plot_data( x_values, y_values, plot_filepath, plot_title, x_unit, y_unit, afFigurePosition)
