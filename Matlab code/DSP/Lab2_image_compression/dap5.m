function [] = dap5()
%
I = read_image();
I = im2double(I);

blkim=cell(1,1);
for k1=0:63
   for k2=0:63
       p1=(1+8*k1):(8+8*k1);
       p2=(1+8*k2):(8+8*k2);
       blkim{k1+1,k2+1}=I(p1,p2);
   end
end
[m,n]=size(blkim);
blkim1=cell(m,n);
for i=1:m
    for j=1:n
        g=dct2(blkim{i,j});
%         g1=padarray(g,[2,2],0);
        blkim1{i,j}=log(abs(g));
    end
end

out=cell2mat(blkim1);
out(isinf(out))=-10;
save('dap5.mat','out');
f=figure;
subplot(1,2,1);
imshow(I);
title('Original Patternization');
subplot(1,2,2);
% image((out)*255);truesize;axis off;
imshow(out,[]);
p=get(gca,'position'); 
colorbar;
set(gca,'position',p);
annotation(f,'textarrow',[.468 .57],[.468 .47],'LineWidth',2);
k=annotation('textbox','String','Divide into 8*8 blocks and compute DCT','Position',[.5 .469 .01 .01],'LineStyle','none');
% text([.48 .57],[.48 .47],'String','Divided into 8*8 blocks')
title('Alternative Patternization (DCT of 8*8 Blocks of Image)');
suptitle('Computing Alternative Patternization');

k=imread('dap5.jpg');
figure;
imshow(k);
title('Encoding and Decoding using Alternative Patternization 5 (DCT of 8*8 Blocks of Image)');
end

