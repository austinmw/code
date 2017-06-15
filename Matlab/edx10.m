
dd = input('Please enter a coordinate in decimal degree form: ');
while dd ~= double(dd)
    dd = input('Please enter a coordinate in decimal degree form: ');
end
[d m s] = ddtodms(dd);
fprintf('DD %.2f° is equal to %d°%d''%d'''' DMS.\n', dd, d, m, s);
