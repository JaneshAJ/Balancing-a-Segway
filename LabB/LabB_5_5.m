%% Task 5.4

%% Load Parameters
LabB_ObserverOverSimulator_Discrete_Parameters;

%% Run Simulation
system_name = 'LabB_ObserverAndControllerOverSimulator_Discrete';
open_system([system_name '.slx'])
saveas(get_param(system_name,'Handle'),[system_name '_diagram.eps']);
sim(system_name)
save_system([system_name '.slx'])
% close_system(SYSTEM_NAME)

%% Plot
afFigurePosition = [1 1 10 6];

OUTPUT_PATH = 'output/';
RUN_NAME = [OUTPUT_PATH 'T5_5'];

% x_w
plot_name = 'x_w';
plot_filepath = [RUN_NAME '_' plot_name];
x_values = x_w.time;
y_values = x_w.signals.values;
plot_title = plot_name;
x_unit = 'time';
y_unit = 'meters';
plot_data( x_values, y_values, plot_filepath, plot_title, x_unit, y_unit, afFigurePosition)

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

%% Maximum Error


% theta_b
theta_b_ = theta_b.signals.values(:,1);
theta_b_hat_full = theta_b.signals.values(:,2);
theta_b_hat_partial = theta_b.signals.values(:,3);


theta_b_error_full = max(abs(theta_b_ - theta_b_hat_full))
theta_b_error_partial = max(abs(theta_b_ - theta_b_hat_partial))


% theta_b
x_w_ = x_w.signals.values(:,1);
x_w_hat_full = x_w.signals.values(:,2);
x_w_hat_partial = x_w.signals.values(:,3);


x_w_error_full = max(abs(x_w_ - x_w_hat_full))
x_w_error_partial = max(abs(x_w_ - x_w_hat_partial))


