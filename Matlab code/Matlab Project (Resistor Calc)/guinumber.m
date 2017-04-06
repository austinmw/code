function guinumber(f, panelhands, resstruct)
l = length(panelhands);
for i = 1:l
    guitolerance(f, panelhands(i), resstruct);  % Create the gui
end
end

