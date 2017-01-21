function out = piAccuracy
out = input('Please input decimal places of accuracy desired: ');
    while out > 7 || out < 1 || int32(out) ~= out
        out = input('Please enter a positive integer below 8: ');
    end
end
