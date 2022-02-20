%% Finding out the COM port for your computer

% for Windows you can directly open Device Manager and look for
% the com ports and use 'COMX' where X is the correct port number
% for the MinSeg

% for unix (or windows if you prefer) you can use the following
% command depending on your version in the command window

% serialportlist('available')

% and if the paths are too long to identify conveniently, type in
% or uncomment temporary the following

% a = serialportlist('available');
% for i=1:length(a)
% disp(a(i))
% end

% for mac, my connection was called /dev/cu.usbmodem14201
% this number changed with OS update so it might not be the same for you
% I expect linux to have somthing similar

% it helps if you do not have any other usb serial devices
% connected as then you know it must be the only one with
% usb in the name

% write the name of the port that is connected to your MinSeg
% to the following variable

%% SET YOUR COM PORT HERE

SERIAL_PORT = 'COM4';
