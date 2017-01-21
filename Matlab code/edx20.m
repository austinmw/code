function out = edx20(vec)
%median
vec = sort(vec);
if mod(length(vec),2) == 0
    evenmed = mean(vec(length(vec)/2):vec((length(vec)/2)+1))
else
    oddmed = vec((length(vec)/2) + 0.5)
end
