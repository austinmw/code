function [] = dap4( )
%Display alternative patternization 4
% k=importdata('dap4.mat');
% k=imresize(k,10);
% figure;
% % cmap=contrast(k);
% imshow(log(abs(k)),[]), colormap(gray), colorbar

I = read_image();
I = im2double(I);

blkim=cell(1,1);
for k1=0:126
   for k2=0:126
       p1=(1+4*k1):(8+4*k1);
       p2=(1+4*k2):(8+4*k2);
       blkim{k1+1,k2+1}=I(p1,p2);
   end
end

[m,n]=size(blkim);
blkim1=cell(m,n);
for i=1:m
    for j=1:n
        g1=(blkim{i,j}).*window2(8,8,@triang); 
        g1=dct2(g1);
%         g(1,1)=0;g(1,8)=0;g(8,1)=0;g(8,8)=0;
%         g1=padarray(g,[2,2],1);
        blkim1{i,j}=log(abs(g1));
    end
end

out=cell2mat(blkim1);
out(isinf(out))=-10;
save('dap4.mat','out');
f=figure;
subplot(1,2,1);
imshow(I);
title('Original Patternization');
subplot(1,2,2);
imshow((out),[]), colormap(gray);p=get(gca,'position'); 
colorbar;
set(gca,'position',p);
% p=get(gca,'position'); 
% set(gca,'position',p);
% image((out)*255);truesize;axis off;
annotation(f,'textarrow',[.468 .57],[.468 .47],'LineWidth',2);
annotation('textbox','String','Windowing and compute dct','Position',[.5 .469 .01 .01],'LineStyle','none');
% text([.48 .57],[.48 .47],'String','Divided into 8*8 blocks')
title('Alternative Patternization (Windowing and DCT of image)');suptitle('Computing Alternative Patternization');

k=imread('dap4.jpg');
figure;
imshow(k);
title('Encoding and Decoding using Alternative Patternization 4 (Windowing and DCT of image)');
end