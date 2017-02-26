function [] = dop(varargin)
% display original patternization
[k,k1]=read_image();
if nargin==1
imshow(k);
title('Original Patternization');    
else
figure;
subplot(1,2,1);
image(k1);axis off;
title('Uploaded Image');
subplot(1,2,2);
imshow(k);
title('Original Patternization (512*512*8 bits grayscale image)');
suptitle('Comparison of Uploaded Image and Conversion to Original Patternization');
save('Original_Patternization.mat','k');
saveas(gcf,'Original_Patternization.jpg');
end
end

