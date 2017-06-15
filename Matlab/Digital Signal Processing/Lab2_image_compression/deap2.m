function [] = deap2(varargin)
%display encoded alternative patternization using rectangular windows
k=importdata('deap2.mat');
k1=read_image();
% k2=importdata('dap2.mat');
if nargin==1
% figure;
imshow(k);
title('Decoded and Encoded Image using 8*8 blocks of image');
else
figure;
subplot(1,2,2)
imshow(k);
title('Encoded Image Using 8*8 blocks of image');
subplot(1,2,1)
imshow(k1);
title('Original Image');
suptitle('Comparison of Original and Decoded and Encoded Image using 8*8 blocks of image');
saveas(gcf,'Decoded_Image2.jpg');
end
end