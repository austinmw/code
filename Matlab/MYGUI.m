function MYGUI
f = figure('Visible','off','color','white','Position', ...
    [200, 200, 400, 400]);
set(f, 'Name', 'NAME GUI');
movegui(f,'center');

hedittxt = uicontrol('Style','edit','Position',[100,250,200,50], ...
    'Callback', @callbackfn);
set(f', 'Visible', 'on');

function callbackfn(hObject, eventdata)
set(hedittxt, 'Visible', 'off');
printstr = get(hedittxt, 'String');
pstr = uicontrol('Style', 'text', 'BackgroundColor', 'white', ...
    'Position', [100, 200, 200, 50], 'String', printstr, ...
    'ForegroundColor', 'Black', 'FontSize', 30);
set(pstr, 'Visible', 'on')
pstr = uicontrol('Style', 'text', 'BackgroundColor', 'white', ...
    'Position', [100, 100, 200, 50], 'String', printstr, ...
    'ForegroundColor', 'Black', 'FontSize', 30);
set(pstr, 'Visible', 'on')
end
end
