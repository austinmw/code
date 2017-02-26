function [ ] = dap1()
%display alternative patternization 1
% k=importdata('dap1.mat');
% figure;
% cmap=contrast(k);
I = read_image();
I = im2double(I);
dct_I=dct2(I);
f=figure;
subplot(1,2,1);
imshow(I);
title('Original Patternization');
subplot(1,2,2);
imshow(log(abs(dct_I)),[]), colormap(gray);p=get(gca,'position'); 
colorbar;
set(gca,'position',p);
annotation(f,'textarrow',[.468 .57],[.468 .47],'LineWidth',2);
k=annotation('textbox','String','Compute Full DCT','Position',[.5 .469 .01 .01],'LineStyle','none','FontSize',15);
% text([.48 .57],[.48 .47],'String','Divided into 8*8 blocks')
title('Alternative Patternization (DCT on whole image)');
suptitle('Computation of Alternative Patternization');

k=imread('dap1.jpg');
figure;
imshow(k);
title('Encoding and Decoding using Alternative Patternization 2 (DCT on whole image)');
save('Alternative_Patternization1.mat','dct_I');
end

