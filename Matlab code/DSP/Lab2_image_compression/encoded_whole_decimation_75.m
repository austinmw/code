function [] = encoded_whole_decimation_75()
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
I= read_image();
I1=double(I);
I3=imresize(I1,0.25);
I4=imresize(I3,4);
r1=uint8(I4);
save('whole_image_decimation.mat','r1');
% save('Encoded_Image2.jpg','r1');
end

