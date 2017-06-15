function [] = dap2()
%Display alternative patternization 2
% k=importdata('dap2.mat');
% k=imresize(k,10);
% figure;
% imshow(k);
% I = read_image();
% I = im2double(I);
% 
% blkim=cell(1,1);
% for k1=0:63
%    for k2=0:63
%        p1=(1+8*k1):(8+8*k1);
%        p2=(1+8*k2):(8+8*k2);
%        blkim{k1+1,k2+1}=I(p1,p2);
%    end
% end
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
% save('dap2.mat','out');
% f=figure;
% subplot(1,2,1);
% imshow(I);
% title('Original Patternization');
% subplot(1,2,2);
% % image((out)*255);truesize;axis off;
% imshow(out);axis image;
% % annotation(f,'textarrow',[.468 .57],[.468 .47],'LineWidth',2);
% % k=annotation('textbox','String','Divide into 8*8 blocks','Position',[.5 .469 .01 .01],'LineStyle','none','FontSize',15);
% % text([.48 .57],[.48 .47],'String','Divided into 8*8 blocks')
% title('Alternative Patternization (8*8 Blocks of Image)');
% suptitle('Computation of Alternative Patternization');

k=imread('dap2.jpg');
figure;
imshow(k);
title('Encoding and Decoding using Alternative Patternization 2 (8*8 Blocks of Image)');
end

