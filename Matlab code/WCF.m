function WCF
f = figure('Visible','off','color','white','Position', ...
    [200, 200, 400, 400]);
set(f, 'Name', 'Wind Chill Calculator');
movegui(f,'center');
tempmin = -10; tempmax = 110;
windmin = 0; windmax = 150;

tempslider = uicontrol('Style','slider','Min',tempmin,'Max',tempmax, ...
    'Callback', @callbackfn, 'Position', [50, 350, 300, 50]);
windslider = uicontrol('Style','slider','Min',windmin,'Max',windmax, ...
    'Callback', @callbackfn, 'Position', [50, 200, 300, 50]);
tmintxt = uicontrol('Style','text','BackgroundColor', 'white', ...
    'Position', [10 350 30 25], 'String', num2str(tempmin));
wmintxt = uicontrol('Style','text','BackgroundColor', 'white', ...
    'Position', [10 200 30 25], 'String', num2str(windmin));
tmaxtxt = uicontrol('Style','text','BackgroundColor', 'white', ...
    'Position', [365 350 30 25], 'String', num2str(tempmax));
wmaxtxt = uicontrol('Style','text','BackgroundColor', 'white', ...
    'Position', [365 200 30 25], 'String', num2str(windmax));
temp = get(tempslider, 'Value');
wind = get(windslider, 'Value');
tvaltxt = uicontrol('Style','text','BackgroundColor', 'white', ...
    'Position', [150 350 100 30], 'String', num2str(temp));
wvaltxt = uicontrol('Style','text','BackgroundColor', 'white', ...
    'Position', [150 250 100 30], 'String', num2str(wind));

set(f, 'Visible', 'on');

function callbackfn(hObject, eventdata);
wcf = temp * wind;
wcftxt = uicontrol('Style','text','BackgroundColor','white', ...
    'Position', [150 100 100 50], 'String', num2str(wcf));
end
end

