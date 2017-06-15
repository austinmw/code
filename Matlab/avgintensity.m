function theavg = avgintensity(inputvec)
l = length(inputvec); 
intensityvec = [1:l];
for i = 1:l
  intensityvec(i) = inputvec(i).intensity;
end
theavg = sum(intensityvec) / l;
end
