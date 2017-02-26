function [I,J] = read_image()
%read the 512*512*uint8 image and set it as I.
try
fileID = fopen('filename.txt','r');
f1=(textscan(fileID,'%s'));
f2=char(f1{1,1});
fclose(fileID);
I=imread(f2);
J=I;
[m,n,o]=size(I);
if o>1
   I=rgb2gray(I); 
end
if ((m~=512)||(n~=512))
    I=imresize(I,[512 512]);
end

catch
I=imread('building.jpg');
J=I;
[m,n,o]=size(I);
if o>1
   I=rgb2gray(I); 
end
if ((m~=512)||(n~=512))
    I=imresize(I,[512 512]);
end
end
end

