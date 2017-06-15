function [] = deap4(varargin)
%display encoded alternative patternization using dct on triangular windows
k=importdata('windowed_image_dct.mat');
k1=read_image;
if nargin==1
% figure;
imshow(k);
title('Decoded and Encoded Image using DCT On Triangular Windows');
else
figure;
subplot(1,2,2);
imshow(k);
title('Decoded and Encoded Image Using DCT On Triangular Windows');
subplot(1,2,1)
imshow(k1);
title('Original Image');
suptitle('Comparison of Original and Decoded and Encoded Image using DCT On Triangular Windows');
saveas(gcf,'Decoded_Image5.jpg');
end

