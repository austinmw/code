function [rval, t, minval] = searchstruct(resstruct, tol, r)

r = str2double(r);
tol = str2double(tol);
if ~isnan(tol)
    if tol == 0.1 || tol == .25 || tol == .5
       resvec = resstruct(1).Resistance;    %resistances for .1, .25, .5 percent tolerances
    elseif tol == 1
       resvec = resstruct(2).Resistance;    %resistances for 1 percent tolerance
    elseif tol == 2
       resvec = resstruct(3).Resistance;    %resistances for 2 percent tolerance
    elseif tol == 5
       resvec = resstruct(4).Resistance;    %resistances for 5 percent tolerance
    elseif tol == 10
       resvec = resstruct(5).Resistance;    %resistances for 10 percent tolerance
    end

    % Remove NaNs from resvec for searching/making multiplier vecs
    resvec = resvec(~isnan(resvec));
else
    resvec = resstruct(1:end).Resistance;
end

% Make vector of multiples
if r < 10
    resvec = resvec ./ 100;
elseif r < 100
    resvec = resvec ./ 10;
elseif r < 1000
    resvec = resvec;
elseif r < 10^4
    resvec = resvec .* 10^1;
elseif r < 10^5
    resvec = resvec .* 10^2;
elseif r < 10^6
    resvec = resvec .* 10^3;
elseif r < 10^7
    resvec = resvec .* 10^4;
elseif r < 10^8
    resvec = resvec .* 10^5;
elseif r < 10^9
    resvec = resvec .* 10^6;
elseif r < 10^10
    resvec = resvec .* 10^7;
end

[minval ,ind] = min(abs(resvec - r)); 
rval = resvec(ind);
t = tol;
end