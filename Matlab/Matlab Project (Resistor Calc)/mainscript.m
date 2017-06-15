%option = resistanceMenu;
%runoption(option)

resstruct = resistorstruct;
r = howmanyresistors;   % Get number of resistors from menu
[fhand, panelh] = panel(r);      % Create panel(s) and get handles
guinumber(fhand, panelh, resstruct);

