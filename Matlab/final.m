%DATA IMPORT, SEPARATE, SORT

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

% closest value sort where 'resistorsE12' is chosen by Tolerance
% and pick is chosen by textedit box
desired = input('Enter val: ');
tol = input('Enter tolerance: ');
if tol == 10
    resistortol = resistorsE12;
elseif tol == 5
    resistortol = resistorsE24;
elseif tol == 2
    resistortol = resistorsE48;
elseif tol == 1
    resistortol = resistorsE96;
elseif tol == .1 || tol == .25 || tol == .5
    resistortol = resistorsE192;
else
    disp('Invalid tolerance');
end
[c i] = min(abs(resistortol-desired));
closestValue = resistortol(i);
closestValue






