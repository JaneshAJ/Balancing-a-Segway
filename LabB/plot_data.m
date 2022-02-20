function plot_data( x_values, y_values, plot_filepath, plot_title, x_unit, y_unit, afFigurePosition)
    plot(x_values, y_values);
    title(plot_title);
    xlabel(x_unit);
    ylabel(y_unit);
    set(gcf,'Units','centimeters');
    set(gcf,'Position',afFigurePosition);
    set(gcf,'PaperPositionMode','auto');
    print('-depsc2','-r300',[plot_filepath '.eps']);
    saveas(gcf,[plot_filepath '.png'])
end