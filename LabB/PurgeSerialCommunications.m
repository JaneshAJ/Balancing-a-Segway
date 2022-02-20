
% NOTICE
% this will bruteforce close all serial communication deivces
% that are currently connected to your computer

% if you have any other serial communication devices connected
% to your computer than the MinSeg, you may need to re-plug them
% after running this script, in order for the other devices
% to work correctly

if exist('serialp', 'var')
    delete(serialp)
    clear serialp
end


con_list = instrfind({'Type'},{'serial'});
for i=1:length(con_list)
    fclose(con_list(i));
    delete(con_list(i));
end

clear con_list