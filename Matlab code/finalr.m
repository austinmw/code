%finalr
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
disp(closestValue);

%%%%%%%%%%%%%

%Script for determining resistor band colors based on tolerance and value

format long g
% resistor value and length, & enter tolerance
t = tol;
r = num2str(closestValue);

if isstrprop(r(end), 'digit')
    l = length(r);
    
    % decimal check / decimal position
    deccheck = strfind(r,'.');
    dec = isempty(deccheck);
    if dec ~= 1
        decpos = deccheck(1);
    end
    
    % Length 1
    if l == 1
        band(1) = str2num(r);
        band(2) = 0;
        band(3) = 0.1;
        band(4) = 5555;
        
    % Length 2, no decimal
    elseif l == 2 && dec == 1
        band(1) = str2num(r(1));
        if str2num(r(2)) ~= 0
            band(2) = str2num(r(2));
            band(3) = 0;
            band(4) = 5555;
        elseif str2num(r(2)) == 0
            band(2) = 0;
            band(3) = 1;
            band(4) = 5555;
        end
        
    % Length 3, no decimal
    elseif l == 3 && dec == 1
        band(1) = str2num(r(1));
        band(2) = str2num(r(2));
        if str2num(r(3)) ~= 0
            band(3) = str2num(r(3));
            band(4) = 1;
        else
            band(3) = 10;
            band(4) = 5555;
        end        
        
    % Length 3, decimal
    elseif l == 3 && dec == 0
        band(1) = str2num(r(1));
        band(2) = str2num(r(3));
        band(3) = 0.1;
        band(4) = 5555;
        
    % Length 4, no decimal
    elseif l == 4 && dec == 1
        band(1) = str2num(r(1));
        band(2) = str2num(r(2));
        if str2num(r(3)) == 0
            band(3) = 100;
            band(4) = 5555;
        else
            band(3) = str2num(r(3));
            band(4) = 10;
        end
        
    % Length 4, decimal
    elseif l == 4 && dec == 0
        if decpos == 2
            band(1) = str2num(r(1));
            band(2) = str2num(r(3));
            band(3) = str2num(r(4));
            band(4) = 0.01;
        elseif decpos == 3
            band(1) = str2num(r(1));
            band(2) = str2num(r(2));
            band(3) = str2num(r(4));
            band(4) = 0.1;
        end
        
    % Length > 4, no decimal
    elseif l > 4 && dec == 1
        band(1) = str2num(r(1));
        band(2) = str2num(r(2));
        if str2num(r(3:end)) == 0
            z = length(r(3:end));
            band(3) = 10 ^ z;
            band(4) = 5555;
        else
            band(3) = str2num(r(3));
            z = length(r(4:end));
            band(4) = 10 ^ z;
        end
    end
    
    format short
    colors = {'black','brown','red','orange','yellow','green','blue',...
        'violet','gray','white','gold','silver'};
     %colors = {1,2,3,4,5,6,7,...
     %   8,9,10,11,12};
    multipliers = [10^0,10^1,10^2,10^3,10^4,10^5,10^6,10^7,10^8,10^9,...
        0.1,0.01];
    numbers = [0:9, 0.1, 0.01];  
    
    % Error check for resistor value >= 1
    if str2num(r(1)) == 0
        disp('No resistor values below 1');
    % Determine colors based on band values    
    else
        resistorcolors = {};
        resistorcolors{1} = colors{find(numbers == band(1))};
        resistorcolors{2} = colors{find(numbers == band(2))};
        if band(4) ~= 5555
            resistorcolors{3} = colors{find(numbers == band(3))};
            resistorcolors{4} = colors{find(multipliers == band(4))};
        elseif band(4) == 5555
            resistorcolors{3} = colors{find(multipliers == band(3))};
            %resistorcolors{4} = 'empty';
            resistorcolors{4} = 0;
        end
        tolerances = [0.1,0.25,0.5,1,2,5,10];
        tolcolors = {'violet','blue','green','brown','red','gold',...
            'silver'};
        %tolcolors = {8,7,6,2,3,11,...
        %    12};
        resistorcolors{5} = tolcolors{find(tolerances == t)};
        disp(resistorcolors);
    end
    
% If last index of resistor value was not a number e.g. 500k
else
    disp('This does not work for SI abbreviations yet, enter full value');
end

