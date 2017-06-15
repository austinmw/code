% Generate a random vector "vec":
vec = [0 1 1 2 3 5 8 13 21 34 55 89 144];

% Perform the action of the diff function without using it:
for i = 1:length(vec)-1
    vec(i) = vec(i) - vec(i+1);
end
mydiff = vec;
