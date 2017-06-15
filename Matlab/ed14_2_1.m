function out = ed14_2_1
load blah.dat
[r c] = size(blah);
code = blah(:,1); rainfall = blah(:,2); hours = blah(:,3);
intensity = rainfall ./ hours;
for i = r:-1:1
stormdata(i) = struct('Code',code(i),'Rainfall',rainfall(i), ...
    'Hours',hours(i),'Intensity',intensity(i));
end
disp(stormdata);

function out = 
r = length(in);
intensevec = [1:r];
for i = 1:r
intensevec(i) = stormdata(i).Intensity;
end
out = sum(intensevec) / r;

%function out = avgintensity(in)




