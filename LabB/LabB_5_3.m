%% Task 5.3

%% Load Parameters
LabB_ControllerOverSimulator_Continuous_Parameters;

%% Run System Simulation
system_name = 'LabB_ControllerOverSimulator_Continuous';
open_system([system_name '.slx'])
saveas(get_param(system_name,'Handle'),[system_name '_diagram.eps']);
sim(system_name)
save_system([system_name '.slx'])
% close_system(SYSTEM_NAME)

%% Plot
afFigurePosition = [1 1 10 6];

OUTPUT_PATH = 'output/';
RUN_NAME = [OUTPUT_PATH 'T5_3'];

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
