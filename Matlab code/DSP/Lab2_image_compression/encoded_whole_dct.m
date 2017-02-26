function [] = encoded_whole_dct(compression,type)
%encode image as whole using dct2 and discard coefficients depending on
%compression.
I=read_image();
I1=double(I);
% I2=adapthisteq((I),'Distribution','rayleigh','Range','original','Alpha',0.8);
% I2=double(I2);

% figure;
% imshow(I);title('original image');
% nobs=round(8*(1-compression));
% dct_I=dct2(I1);

% [m,n]=size(dct_I);


if type==2
dct_I=dct2(I1);
% msk=zeros(512-512*compression);
% l=512.*compression./2;
% msk1=padarray(msk,[l,l],1);
% msk1(((l/2+1):(512-l/2-1)),:)=0;
% msk1(:,((l/2+1):(512-l/2-1)))=0;
msk1=zeros(512);
msk1((1:200),(1:200))=1;
masked_dct_I=dct_I.*msk1;
r=idct2((masked_dct_I));
r1=uint8(r);
save('whole_image_dct.mat','r1');

elseif ((type==1)&&(compression==0.5)) 

I1_red=imresize(I1,0.5);
dct_I1_red=dct2(I1_red);

r=idct2(dct_I1_red,512,512);

% r=imresize(I2,2);
r1=uint8(r);

save('whole_image_dct.mat','r1');

elseif ((type==1)&&(compression==0.25)) 
I1_red=imresize(I1,0.25);
dct_I1_red=dct2(I1_red);
r=idct2(dct_I1_red,512,512);
r1=uint8(r);
save('whole_image_dct.mat','r1');

elseif((type==3))
% nobs=round(8*(compression));

dct_I=dct2(I1);
msk=zeros(512-512*compression);
l=512.*compression./2;
msk1=padarray(msk,[l,l],1);
msk1(((l/2+1):(512-l/2-1)),:)=0;
msk1(:,((l/2+1):(512-l/2-1)))=0;
masked_dct_I=dct_I.*msk1;
r=idct2((masked_dct_I));
r1=uint8(r);
% figure;
% imshow(r1);
save('whole_image_dct.mat','r1');
end
% figure;
% imshow(uint8(out));
% k=compression*100;
% title(['Image Encoded at ',num2str(k),'% using DCT']);
end

