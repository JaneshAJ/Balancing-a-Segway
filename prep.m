% you can run this file by simply typing the following to the command line:
% prep

% without the comment mark of course
% alternatively you can rename this file and use whatever you want


% DO NOT MODIFY THIS CODE UNLESS YOU KNOW WHAT YOU ARE DOING
% these commands do not ask for permissions and their effects
% are permanent and cannot be reversed

delete *.eep
delete *.elf
delete *.hex
delete *.slxc

try
    rmdir slprj s
catch ME
    if (strcmp(ME.identifier,'MATLAB:RMDIR:NotADirectory'))
        % all good
    else
        rethrow(ME)
    end
end

try
    rmdir *_ert_rtw s
catch ME
    if (strcmp(ME.identifier,'MATLAB:RMDIR:NotADirectory'))
        % all good
    else
        rethrow(ME)
    end
end