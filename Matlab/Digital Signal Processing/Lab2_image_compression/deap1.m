function [] = deap1(varargin)
% function to display encoded alternative patternization using full dct
k1=read_image();
k=importdata('whole_image_dct.mat');
if nargin==1
% figure;
imshow(k);
title('Decoded and Encoded Image using DCT on Entire Image');
else
figure;
subplot(1,2,2)
imshow(k);
title('Encoded Image using DCT on Entire Image');
subplot(1,2,1)
imshow(k1);
title('Original Image');
suptitle('Comparison of Original and Decoded and Encoded Image using DCT on Entire Image');
saveas(gcf,'Decoded_Image1.jpg');
end
end

