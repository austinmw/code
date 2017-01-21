% Generate a random vector "vec":
vec = randi([-20,20],1,20);

% Perform the action of the diff function without using it:
mydiff = vec(2:end) - vec(1:end-1);
