function [] = dap3()
%Display alternative patternization 3k=importdata('dap3.mat');
% k=importdata('dap3.mat');
% k=imresize(k,10);
% figure;
% imshow(k);
% 
% I = read_image();
% I = im2double(I);
% 
% blkim=cell(1,1);
% for k1=0:126
%    for k2=0:126
%        p1=(1+4*k1):(8+4*k1);
%        p2=(1+4*k2):(8+4*k2);
%        blkim{k1+1,k2+1}=I(p1,p2);
%    end
% end
% 
% [m,n]=size(blkim);
% blkim1=cell(m,n);
% for i=1:m
%     for j=1:n
%         g=blkim{i,j};
%         g1=padarray(g,[2,2],0.9);
%         blkim1{i,j}=g1;
%     end
% end
% 
% out=cell2mat(blkim1);
% save('dap3.mat','out');
% f=figure;
% subplot(1,2,1);
% imshow(I);
% title('Original Patternization');
% subplot(1,2,2);
% image((out)*255);truesize;axis off;
% % imshow(out,'InitialMagnification',500);
% annotation(f,'textarrow',[.468 .57],[.468 .47],'LineWidth',2);
% annotation('textbox','String','Divide into overlapping blocks and window','Position',[.5 .469 .01 .01],'LineStyle','none');
% % text([.48 .57],[.48 .47],'String','Divided into 8*8 blocks')
% title('Alternative Patternization (Image Windowed on overlapping blocks of image)');
% suptitle('Computation of Alternative Patternization');
% title('Alternative Patternization (8*8 Block of Image Windowed with an overlapping triangular window)');
k=imread('dap3.jpg');
figure;
imshow(k);
title('Encoding and Decoding using Alternative Patternization 3 (Image Windowed on overlapping blocks of image)');
end

