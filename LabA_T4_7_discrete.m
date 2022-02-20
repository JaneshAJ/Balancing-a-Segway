close all; 
clear; 
clc;

LoadPhysicalParameters;
LoadStateSpaceMatrices;
fSamplingPeriod = 0.02;
Ad = A;
Bd = B;
Cd = C;
Dd = D;

[afLinearizedBotZeros, afLinearizedBotPoles, fLinearizedBotGain] = ss2zp(Ad, Bd, Cd, Dd, 2);
ComputePIDGains;

% Task 4.5 Conditions
B_for_poking = Bd
C_for_full_observability = eye(4)
D_for_full_observability_and_poking = zeros([4 2])


open_system('LabA_LinearizedBotVsSimulator_Discrete.slx')
saveas(get_param('LabA_LinearizedBotVsSimulator_Discrete','Handle'),'LabA_LinearizedBotVsSimulator_Discrete.eps');
sim('LabA_LinearizedBotVsSimulator_Discrete')
save_system('LabA_LinearizedBotVsSimulator_Discrete.slx')
% close_system('LabA_LinearizedBotVsSimulator_Discrete')

afFigurePosition = [1 1 10 6];


run_name = 'T4_7_disc';

% Plotting
figure(1)
plot(x_w.time, x_w.signals.values);
title('x_w');
xlabel('time');
ylabel('meters');
set(gcf,'Units','centimeters');
set(gcf,'Position',afFigurePosition);
set(gcf,'PaperPositionMode','auto');
print('-depsc2','-r300','LabA_LinearizedBot_Simulink_x_w.eps');
saveas(gcf,[run_name '_x_w.png'])


figure(2)
plot(theta_b.time, theta_b.signals.values * 180/pi);
title('\theta_b');
xlabel('time');
ylabel('degrees');
set(gcf,'Units','centimeters');
set(gcf,'Position',afFigurePosition);
set(gcf,'PaperPositionMode','auto');
print('-depsc2','-r300','LabA_LinearizedBot_Simulink_theta_b.eps');
saveas(gcf,[run_name '_theta_b.png'])

figure(3)
plot(d.time, d.signals.values);
title('d');
xlabel('time');
ylabel('meters');
set(gcf,'Units','centimeters');
set(gcf,'Position',afFigurePosition);
set(gcf,'PaperPositionMode','auto');
print('-depsc2','-r300','LabA_LinearizedBot_Simulink_d.eps');
saveas(gcf,[run_name '_d.png'])


figure(4)
plot(v_m.time, v_m.signals.values);
title('v_m');
xlabel('time');
ylabel('meters');
set(gcf,'Units','centimeters');
set(gcf,'Position',afFigurePosition);
set(gcf,'PaperPositionMode','auto');
print('-depsc2','-r300','LabA_LinearizedBot_Simulink_v_m.eps');
saveas(gcf,[run_name '_v_m.png'])