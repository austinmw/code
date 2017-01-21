fid = fopen('ws16_1.dat');
if fid == -1
    disp('Error opening file');
end
vec = [];
while ~feof(fid)
    aline = fgetl(fid);
    x = strfind(aline, 'x');
    vec = [];
    placeholder = 1;
    for i = 1:length(x)
        vec(i) = str2num(aline(placeholder:x(i)-1));
 %       aline = aline(x(i)+1:end)
        placeholder = x(i)+1;
 
    end
    disp(vec);
    figure
    bar(vec);
end