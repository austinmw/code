function rectareagui
f = figure('Visible','off','color','white','Position', ...
    [200, 200, 400, 400]);
set(f, 'Name', 'Rectangle Area Calculator');
movegui(f,'center');

lengthbox = uicontrol('Style','edit','Position',[50,300,125,50]);
widthbox = uicontrol('Style','edit','Position',[225,300,125,50]);

calcbutton = uicontrol('Style','pushbutton','String', 'Calculate Area', ...
    'Position',[100,200,200,75], 'Callback', @callbackfn);

set(f, 'Visible', 'on');

function callbackfn(h0bject, eventdata)
length = get(lengthbox, 'String');
width = get(widthbox, 'String');
area = str2num(length) * str2num(width);
areatxt = uicontrol('Style','text', 'BackgroundColor', 'white', ...
    'Position', [100, 100, 200, 50], 'String', num2str(area), 'ForegroundColor', ...
    'Black', 'FontSize', 30);
set(areatxt, 'Visible', 'On');
end
end


