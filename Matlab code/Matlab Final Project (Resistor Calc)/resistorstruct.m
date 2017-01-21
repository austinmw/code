function rstruct = resistorstruct
% Reads an excel file of resistances into a data structure
% The first column are E192 resistors with tolerances of 0.1, 0.25, and 0.5
% The second column are E96 resistors with tolerance of 1
% The third column are E48 resistors with tolerance of 2
% The fourth column are E24 resistors with tolerance of 5
% The fifth column are E12 resistors with tolerance of 10

resistors = xlsread('resistors.xlsx');
[~, c] = size(resistors);
tols = {[.1 .25 .5], 1, 2, 5, 10};
for i = c:-1:1
    resstruct(i) = struct('Resistance', resistors(:,i), 'Tolerance', tols{i}, 'Code', num2str(resistors(:,i)));
end

% Order fields of structure: Tolerance, Resistance, Code
rstruct = orderfields(resstruct, [2 1 3]);
end