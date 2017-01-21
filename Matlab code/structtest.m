function rval = structtest(tol,r)

resistors = xlsread('resistors.xlsx');
% Reads an excel file of resistances into a data structure
% The first column are E192 resistors with tolerances of 0.1, 0.25, and 0.5
% The second column are E96 resistors with tolerance of 1
% The third column are E48 resistors with tolerance of 2
% The fourth column are E24 resistors with tolerance of 5
% The fifth column are E12 resistors with tolerance of 10

[~, c] = size(resistors);
tols = {[.1 .25 .5], 1, 2, 5, 10};
for i = c:-1:1
    resstruct(i) = struct('Resistance', resistors(:,i), 'Tolerance', tols{i}, 'Code', num2str(resistors(:,i)));
end

%order fields of structure: Tolerance, Resistance, Code
resstruct = orderfields(resstruct, [2 1 3]);

if tol == 0.1 || tol == .25 || tol == .5
   resvec = resstruct(1).Resistance; %resistances for .1, .25, .5 percent tolerances
elseif tol == 1
   resvec = resstruct(2).Resistance;%resistances for 1 percent tolerance
elseif tol == 2
   resvec = resstruct(3).Resistance;%resistances for 2 percent tolerance
elseif tol == 5
   resvec = resstruct(4).Resistance;%resistances for 5 percent tolerance
elseif tol == 10
   resvec = resstruct(5).Resistance;%resistances for 10 percent tolerance
end


%remove NaNs from resvec for searching/making multiplier vecs
resvec=resvec(~isnan(resvec));


%make vector of multiples
if r <= 10
    resvec = resvec./100;
elseif r < 100
    resvec = resvec./10;
elseif r == 100 || r < 10^3
    resvec = resvec;
elseif r == 1000 || r < 10^4
    resvec = resvec.*10^(1);
elseif r == 10^4 || r < 10^5
    resvec = resvec.*10^(2);
elseif r == 10^5 || r < 10^6
    resvec = resvec.*10^(3);
elseif r == 10^6 || r < 10^7
    resvec = resvec.*10^(4);
elseif r == 10^7 || r < 10^8
    resvec = resvec.*10^(5);
elseif r == 10^8 || r < 10^9
    resvec = resvec.*10^(6);
elseif r == 10^9 || r < 10^10
    resvec = resvec.*10^(7);
end

[~,ind] = min(abs(resvec-r)); 
rval = resvec(ind);  
end