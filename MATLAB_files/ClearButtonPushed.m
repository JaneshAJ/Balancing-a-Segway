
function ClearButtonPushed(~,~, line_list, num_lines)
% Clear Button Callback function for real time plotting of MinSeg data
    for i=1:num_lines
      line_handle = line_list(i);
      clearpoints(line_handle);
    end
    tic;
end
