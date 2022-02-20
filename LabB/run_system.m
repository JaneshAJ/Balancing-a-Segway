function run_simulation(system_name)
    open_system([system_name '.slx'])
    saveas(get_param(system_name,'Handle'),[system_name '_diagram.eps']);
    sim(system_name)
    save_system([system_name '.slx'])
    % close_system(SYSTEM_NAME)
end