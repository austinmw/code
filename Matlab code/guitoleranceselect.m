function guitoleranceselect


% Import data
format long g
resistors = xlsread('resistors.xlsx');

% Breaking down matrix into vectors and removing NaNs
resistorsE192 = resistors(:,1);
resistorsE192 = cat(1,resistorsE192,resistorsE192*10^-2,...
    resistorsE192*10^-1,resistorsE192*10,resistorsE192*10^2, ...
    resistorsE192*10^3,resistorsE192*10^4);

resistorsE96 = resistors(:,2);
resistorsE96 = resistorsE96(~isnan(resistorsE96));
resistorsE96 = cat(1,resistorsE96,resistorsE96*10^-2, ...
    resistorsE96*10^-1,resistorsE96*10,resistorsE96*10^2, ...
    resistorsE96*10^3,resistorsE96*10^4);

resistorsE48 = resistors(:,3);
resistorsE48 = resistorsE48(~isnan(resistorsE48));
resistorsE48 = cat(1,resistorsE48,resistorsE48*10^-2, ...
    resistorsE48*10^-1,resistorsE48*10,resistorsE48*10^2, ...
    resistorsE48*10^3,resistorsE48*10^4);

resistorsE24 = resistors(:,4);
resistorsE24 = resistorsE24(~isnan(resistorsE24));
resistorsE24 = cat(1,resistorsE24,resistorsE24*10^-2, ...
    resistorsE24*10^-1,resistorsE24*10,resistorsE24*10^2, ...
    resistorsE24*10^3,resistorsE24*10^4);

resistorsE12 = resistors(:,5);
resistorsE12 = resistorsE12(~isnan(resistorsE12));
resistorsE12 = cat(1,resistorsE12,resistorsE12*10^-2, ...
    resistorsE12*10^-1,resistorsE12*10,resistorsE12*10^2, ...
    resistorsE12*10^3,resistorsE12*10^4);


% Sorting data
resistorsE192 = sort(resistorsE192);
resistorsE96 = sort(resistorsE96);
resistorsE48 = sort(resistorsE48);
resistorsE24 = sort(resistorsE24);
resistorsE12 = sort(resistorsE12);

%guitolerance select has 7 radio buttons to select desired tolerance

%create GUI, visibility off while initialized
f = figure('Visible', 'off', 'color', 'white', ...
    'Position', [500 500 500 500]);

%button group
tolerances = uibuttongroup('Parent', f, 'Units', 'Normalized', ...
    'Position', [.05 .5 .9 .5],'SelectionChangeFcn', @selectedtol);

%add 7 radio buttons to group
opt01 = uicontrol(tolerances, 'Style', 'radiobutton', 'String', '0.10',...
    'Units', 'Normalized', 'Position',[.05 .7 .2 .16]);
opt025 = uicontrol(tolerances, 'Style', 'radiobutton', 'String', ...
    '0.25', 'Units', 'Normalized', 'Position',[.05 .54 .2 .16]);
opt05 = uicontrol(tolerances, 'Style', 'radiobutton', 'String',...
    '0.50', 'Units', 'Normalized', 'Position',[.05 .38 .2 .16]);
opt1 = uicontrol(tolerances, 'Style', 'radiobutton', 'String', ...
    '1', 'Units', 'Normalized', 'Position',[.05 .22 .2 .16]);
opt2 = uicontrol(tolerances, 'Style', 'radiobutton', 'String', ...
    '2', 'Units', 'Normalized', 'Position',[.25 .65 .2 .16]);
opt5 = uicontrol(tolerances, 'Style', 'radiobutton', 'String', ...
    '5', 'Units', 'Normalized', 'Position',[.25 .49 .2 .16]);
opt10 = uicontrol(tolerances, 'Style', 'radiobutton', 'String', ...
    '10', 'Units', 'Normalized', 'Position',[.25 .33 .2 .16]);

valprint = uicontrol('Style','text','BackgroundColor','white', ...
    'Units', 'Normalized', 'Position', [.2 .2 .4 .4], 'Visible', ...
    'off');


%static titles
toltitle = uicontrol('Style', 'text', 'Units', 'Normalized', ...
    'Position',[.1 .95 .1 .02], 'String', 'Tolerance:','Visible', 'on');
restitle = uicontrol('Style', 'text', 'Units', 'Normalized', ...
    'Position',[.65 .65 .2 .2], 'String', 'Desired Resistance:', ...
    'Visible', 'on');

%edit text to enter desired resistance
desiredr = uicontrol('Style', 'edit', 'Units', 'Normalized', ...
    'Position',[.65 .7 .2 .1]);

set(f,'Visible', 'on')

hbutton = uicontrol('Style','pushbutton', 'String', 'Push', 'Units', ...
    'Normalized', 'Position', [.2 .2 .4 .2], 'Callback', @callbackfn);

    function callbackfn(hObject, eventdata);
        printstr = get(desiredr, 'String');
        hstr = uicontrol('Style', 'text', 'BackgroundColor', 'white', ...
            'Units', 'Normalized', 'Position', [.2 .2 .4 .2], 'String',...
            printstr, 'ForegroundColor', 'Red', 'FontSize', 30);
        set(hstr, 'Visible', 'on');
    end


function selectedtol(hObject, eventdata)
tol = get(tolerances, 'SelectedObject');
r=get(desiredr, 'String');
disp(r);
if tol == opt01 || tol == opt025 || tol == opt05
    resistors = resistorsE192;
elseif tol == opt1
   resistors = resistorsE96;
elseif tol == opt2
   resistors = resistorsE48;
elseif tol == opt5
    resistors = resistorsE24;
elseif tol == opt10
    resistors = resistorsE12;
end
[c,i] = min(abs(resistors-r));
rval = resistors(i);
num = get(desiredr, 'String');
set(valprint, 'Visible', 'on', 'String', num);


end

end
