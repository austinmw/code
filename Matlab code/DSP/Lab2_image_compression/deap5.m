function [] = deap5(varargin)
%display encoded alternative patternization using dct on rectangular windows
k=importdata('rect_windowed_image_dct.mat');
k1=read_image;
if nargin==1
% figure;
imshow(k);
title('Decoded and Encoded Image using DCT On Blocks of Image');
else
figure;
subplot(1,2,2);
imshow(k);
title('Decoded and Encoded Image Using DCT On Blocks of Image');
subplot(1,2,1)
imshow(k1);
title('Original Image');
suptitle('Comparison of Original and Decoded and Encoded Image using DCT On Blocks of Image');
saveas(gcf,'Decoded_Image4.jpg');
end

