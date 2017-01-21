%xyscript
fid = fopen('xypts.dat');
if fid == -1 
    disp('Error opening file.');
else
    xvec = []; yvec = [];
    i = 1;
    while ~feof(fid)
        i = i + 1;
        aline = fgetl(fid);
        [x,y] = strtok(aline,'y');  
        x = str2double(x(3:end));
        y = str2double(y(2:end));
        if isnan(x) ~= 1
            xvec(i) = x; yvec(i) = y;
        end
    end
    disp(xvec); disp(yvec);
end
plot(xvec,yvec,'*');
title(length(xvec));
closecheck = fclose(fid);
if closecheck == 0
    disp('Closed properly.');
else
    disp('Did not close properly.');
end