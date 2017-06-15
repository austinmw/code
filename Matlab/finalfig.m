function finalgui

f = figure('Visible', 'off', 'color', 'white', 'Units', 'Normalized', ...
    'Position', [.04 .2 .30 .8]);

minval = 1;
maxval = 3;
slider = uicontrol('Style','slider', 'Position', ...
    [160 640 90 15], 'Min', minval, 'Max', maxval, ...
    'Callback', @callbackfn);
mintxt = uicontrol('Style','text','BackgroundColor','white', ...
    'Position', [145 640 10 15], 'String', num2str(minval));
maxtxt = uicontrol('Style','text','BackgroundColor','white', ...
    'Position', [255 640 10 15], 'String', num2str(maxval));
valtxt = uicontrol('Style','text','BackgroundColor','white', ...
    'Position', [180 655 10 15], 'Visible', 'off');


set(f, 'Name', 'Standard Resistor Value Calculator');
set([slider,mintxt,maxtxt,valtxt],'Units','Normalized');
set(f, 'Visible', 'on');


    function callbackfn(hObject,eventdata)
       num = get(slider, 'Value');
       set(valtxt, 'Visible', 'on', 'String', num2str(num));       
    end

end

