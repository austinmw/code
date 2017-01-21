% create vectors x, y, and z with random real numbers:
x = 100.*rand(5,1);
y = 100.*rand(5,1);
z = 100.*rand(5,1);

% create the file three-d.dat using fprintf:
fid = fopen('three-d.dat','w');
for i = 1:length(x)
fprintf(fid, '%f %f %f\n', x(i),  y(i), z(i));
end
fclose(fid);
type('three-d.dat');