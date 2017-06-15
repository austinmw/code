function [] = deap3(varargin)
% display encoded alternative patternization using triangular windows
k=importdata('deap3.mat');
k1=read_image;
if nargin==1
% figure;
imshow(k);
title('Decoded and Encoded Image using Triangular Windows');
else
figure;
subplot(1,2,2)
imshow(k);
title('Encoded Image Using Triangular Windows');
subplot(1,2,1)
imshow(k1);
title('Original Image');
suptitle('Comparison of Original and Decoded and Encoded Image using Triangular Windows');
saveas(gcf,'Decoded_Image3.jpg');
end
end

