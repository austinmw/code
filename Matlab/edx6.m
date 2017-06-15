function var = edx6(num)
ans = menu('Choose a function','ceil','round','sign');
if ans == 1
    var = ceil(num);
elseif ans == 2
    var = round(num);
elseif ans == 3
    var = sign(num);
end

      