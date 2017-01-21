% create a 3 by 6 matrix of random integers and write it to "randfile.dat"
mat1 = randi([50 100],3,6);
save randfile.dat mat1 -ascii
  
% append a 2 by 6 matrix of random integers to "randfile.dat"
mat2 = randi([50 100],2,6);
save randfile.dat mat1 -append -ascii

% load "randfile.dat" to check that it's right!
load randfile.dat
