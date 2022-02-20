%% NOTICE
% you should not edit this file, only run it
% if there is a problem, it is most likely due to either:
% A - wrong plotting script, make sure to use the one for the current lab
% B - wrong serial communication port in SerialSettings.m
% C - the serial port is in use for one reason or the other

% check A and B, and if it is C, run PurgeSerialCommunications.m

close all;

%% Settings

SerialSettings;

BAUD_RATE = 9600;
N_VARIABLES = 7;

message_length = N_VARIABLES+1;


%% Init
               
% setup a figure with animated lines for animation plots
cmap = jet(N_VARIABLES);
subplot(311);
line_list = [animatedline('color',cmap(1,:))];

for i=2:N_VARIABLES
    if i == 4
        subplot(312);
    elseif i == 7
        subplot(313);
    end
    
    line_list(i) = animatedline('color',cmap(mod(2*(i-1),N_VARIABLES)+1,:));
    
    % set set plot options
    if i == 3
        legend('measured', 'reduced', 'full', 'location', 'northwest')
        grid on
        title('Wheel position estimates')
        xlabel('Time (s)')
        ylabel('Position (m)')
        
    elseif i == 6
        legend('measured', 'reduced', 'full', 'location', 'northwest')
        grid on
        title('Body angle estimates')
        xlabel('Time (s)')
        ylabel('Position (m)')
        
    elseif i == 7
        grid on
        title('Controller output')
        xlabel('Time (s)')
        ylabel('Voltage (V)')
    end
        
end

% set super group title
sgtitle('Lab B - Observer And Controller Over Robot')

% open the serial communication
serialp = serialport(SERIAL_PORT, BAUD_RATE);

% start matlab time
tic;

% hook the serial communication callback function
DataCallback = ...
    @(source, event) SerialCallback(source, event, message_length, line_list);

% wait for 2 messages in case of missalignment of data
configureCallback(serialp, "byte", 2*message_length,...
    @(source, event) DataCallback(source, event));

% get handle to current figure
f_handle = gcf;

% UI control buttons with callback hooks

clear_button = uicontrol('Position', [10, 10, 60, 20]);
clear_button.String = "Clear";
clear_button.Callback = @(src, event)...
    ClearButtonPushed(src, event, line_list, N_VARIABLES);

stop_button = uicontrol('Position', [80, 10, 60, 20]);
stop_button.String = "STOP";
stop_button.Callback = @(src, event) StopButtonPushed(src, event, serialp);


%% Clean up
% wait for figure to be closed, then end serial communication
waitfor(f_handle)
configureCallback(serialp, "off")
delete(serialp)


    
    
