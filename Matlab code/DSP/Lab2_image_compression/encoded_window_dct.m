function [] = encoded_window_dct(compression,type)
%Encode the windowed image to 25% or 50% using dct  
warning('off','all');
I = read_image();
I = im2double(I);
% I1=adapthisteq(I,'Distribution','rayleigh','Range','original');

% start here dct2
blkim=cell(1,1);
for k1=0:126
   for k2=0:126
       p1=(1+4*k1):(8+4*k1);
       p2=(1+4*k2):(8+4*k2);
       blkim{k1+1,k2+1}=I(p1,p2);
   end
end

% blkim1=cell(1,1);
% for k1=0:126
%    for k2=0:126
%        p1=(1+4*k1):(8+4*k1);
%        p2=(1+4*k2):(8+4*k2);
%        blkim1{k1+1,k2+1}=I1(p1,p2);
%    end
% end
% 

[m,n]=size(blkim);
out=cell(m,n);

if type==2
for i=1:m
    for j=1:n
   a=blkim{i,j};
   masked_a=a.*window2(8,8,@triang);
dct_I=dct2(masked_a);
% msk=zeros(8-8*compression);
% l=8.*compression./2;
% msk1=padarray(msk,[l,l],1);
% msk1(((l/2+1):(8-l/2-1)),:)=0;
% msk1(:,((l/2+1):(8-l/2-1)))=0;
msk1=zeros(8);
msk1((1:4),(1:4))=1;
masked_dct_I=dct_I.*msk1;
r=idct2((masked_dct_I));
%    dct_I=dct2(masked_a);
%    sorted_dct=unique(abs(dct_I(:)));
%    l=round(length(sorted_dct)*(1-compression));
%    dct_I(abs(dct_I)<=sorted_dct(l))=0;
   out{i,j}=r;
    end
end
out_i=cell(1,1);
for i=2:m-1
    for j=2:n-1
    a1=out{i-1,j-1};a2=out{i-1,j};a3=out{i-1,j+1};a4=out{i,j-1};
    a5=out{i,j};a6=out{i,j+1};a7=out{i+1,j-1};a8=out{i+1,j};a9=out{i+1,j+1};
    a11=a1((5:8),(5:8))+a2((5:8),(1:4))+a4((1:4),(5:8))+a5((1:4),(1:4));
    out_i{i,j}=a11;
    end
end
out_i=cell2mat(out_i);

save('windowed_image_dct.mat','out_i');

elseif((type==1)&&(compression==0.5))
for i=1:m
    for j=1:n
   a=blkim{i,j};
   masked_a=double(a).*window2(8,8,@triang);
   masked_a_r=imresize(masked_a,0.5);
   dct_masked_a=dct2(masked_a_r);
% % %    dct_masked_a=dct2(masked_a);
% % %    dct_masked_a(2:2:end,2:2:end)=0;
%    sorted_dct_masked_a=unique(abs(dct_masked_a(:)));
%    l=round(length(sorted_dct_masked_a)*(1-compression));
%    dct_masked_a(abs(dct_masked_a)<=sorted_dct_masked_a(l))=0;
%    sorted_dct_masked_a(isnan(sorted_dct_masked_a))=[];
% %    masked_a_r=imresize(masked_a,0.5);
% %    dct_I=dct2(masked_a_r);
%    dct_I=double(dct_I).*window2(8,8,@triang);
%    dct_I2=imresize(dct_I,0.5);
%   for k=1:8
%       for l=1:8
%       if mod((l+k-2),2)~=0
%           dct_I(l,k)=0;
%       end    
%       end
%   end
%    dct_I(dct_I==0)=NaN;
%    dct_I1=inpaint_nans(dct_I);
%    sorted_dct=unique(abs(dct_I(:)));
%    l=round(length(sorted_dct)*(1-compression));
%    dct_I(abs(dct_I)<=sorted_dct(l))=0;
% %    idct_I=idct2(dct_I);
   idct_I=idct2(dct_masked_a,8,8);
% %    out{i,j}=imresize(idct_I,2);
   out{i,j}=idct_I;
    end
end
out_i=cell(1,1);
for i=2:m-1
    for j=2:n-1
    a1=out{i-1,j-1};a2=out{i-1,j};a3=out{i-1,j+1};a4=out{i,j-1};
    a5=out{i,j};a6=out{i,j+1};a7=out{i+1,j-1};a8=out{i+1,j};a9=out{i+1,j+1};
    a11=a1((5:8),(5:8))+a2((5:8),(1:4))+a4((1:4),(5:8))+a5((1:4),(1:4));
    out_i{i,j}=a11;
    end
end
out_i=cell2mat(out_i);

% out_i1=uint8(out_i);
save('windowed_image_dct.mat','out_i');  

elseif((type==1)&&(compression==0.25))
for i=1:m
    for j=1:n
   a=blkim{i,j};
   masked_a=double(a).*window2(8,8,@triang);
% %    masked_a_r=imresize(masked_a,0.25);
masked_a_r=imresize(masked_a,0.25);
   dct_I=dct2(masked_a_r);
%    dct_I2=imresize(dct_I,0.25);
%  dct_I=dct2(a);
% %   for k=1:8
% %       for l=1:8
% %       if mod((l+k-2),4)~=0
% %           dct_I(l,k)=0;
% %       end    
% %       end
% %   end
%   dct_I=double(dct_I).*window2(8,8,@triang);
%    dct_I(dct_I==0)=NaN;
%    dct_I1=inpaint_nans(dct_I);
%    sorted_dct=unique(abs(dct_I(:)));
%    l=round(length(sorted_dct)*(1-compression));
%    dct_I(abs(dct_I)<=sorted_dct(l))=0;
%    dct_I=imresize(dct_I2,4);
   idct_I=idct2(dct_I,8,8);
   out{i,j}=(idct_I);
% %    out{i,j}=imresize(idct_I,4);
    end
end
out_i=cell(1,1);
for i=2:m-1
    for j=2:n-1
    a1=out{i-1,j-1};a2=out{i-1,j};a3=out{i-1,j+1};a4=out{i,j-1};
    a5=out{i,j};a6=out{i,j+1};a7=out{i+1,j-1};a8=out{i+1,j};a9=out{i+1,j+1};
    a11=a1((5:8),(5:8))+a2((5:8),(1:4))+a4((1:4),(5:8))+a5((1:4),(1:4));
    out_i{i,j}=a11;
    end
end
out_i=cell2mat(out_i);

% out_i1=uint8((out_i));
save('windowed_image_dct.mat','out_i');     
end
% figure;
% imshow(I);title('original image');
% figure;
% imshow(out_i);title('compressed image');
end

