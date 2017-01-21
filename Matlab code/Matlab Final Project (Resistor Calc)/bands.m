function outvec = bands(res)
% Returns resistor band colors as a indicies into colormap

r = num2str(res);

if isstrprop(r(end), 'digit') && str2double(r(1)) ~= 0
    len = length(r);
    rstr = strrep(r, '.', '');
    len2 = length(rstr);
    if len2 >= 1     % Store the first digits up to 3 as strings to reduce str2num commands
        r1 = str2double(rstr(1));
        if len2 >= 2
            r2 = str2double(rstr(2));
            if len2 >= 3
                r3 = str2double(rstr(3));
            end
        end
    end
    band = zeros(1,4)-1;    % Preallocate band vector with -1

    % Decimal check / decimal position
    decind = strfind(r, '.');
    if isempty(decind)     % No decimal
        if len == 1     % Length 1, no decimal
            band = [r1 0 10];
        elseif len == 2     % Length 2, no decimal
            band(1) = r1;
            band(2) = r2;
            band(3) = 0;
        elseif len == 3     % Length 3, no decimal
            band(1) = r1;
            band(2) = r2;
            if r3 ~= 0
                band(3) = r3;
                band(4) = 0;
            else
                band(3) = 1;
            end
        elseif len == 4     % Length 4, no decimal
            band(1) = r1;
            band(2) = r2;
            if r3 == 0
                band(3) = 1;
            else
                band(3) = r3;
                band(4) = 1;
            end
        elseif len > 4      % Length > 4, no decimal
            band(1) = r1;
            band(2) = r2;
            if r3 == 0
                z = length(r(3:end));
                band(3) = z;
            else
                band(3) = r3;
                z = length(r(4:end));
                band(4) = z;
            end
        end
    else
        if len == 3     % Length 3, decimal
            band(1) = r1;
            band(2) = r2;
            band(3) = 10;   % 10 is gold
        elseif len == 4     % Length 4, decimal
            if decind == 2
                band(1) = r1;
                band(2) = r2;
                band(3) = r3;
                band(4) = 11;   % 11 is silver
            elseif decind == 3
                band(1) = r1;
                band(2) = r2;
                band(3) = r3;
                band(4) = 10;   % 10 is gold
            end
        end
    end
else    % If last index of resistor value was not a number e.g. 500k
    band = [];
end
band = band(band >= 0);     % Only the preallocated elements that were replaced
%band(1:end-1) = band(1:end-1)+1;
outvec = band;
end