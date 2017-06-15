function [] = encoded_window_decimation_25()
%Encode the windowed image using  25% decimation 

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
out=cell(m,n);

for i=1:m
    for j=1:n
   a=blkim{i,j};
   masked_a=a.*window2(8,8,@triang);   
   masked_a1=imresize(masked_a,0.25);
%    for l=1:8
%        for r=1:8  
%       if mod((l+r-2),4)~=0
%           masked_a(l,r)=0;
%       end
%        end
%    end
  masked_a=imresize(masked_a1,4);
   out{i,j}=masked_a;
    end
end

out1=out;
out_i=cell(m,n);
for i=2:m-1
    for j=2:n-1
    a1=out1{i-1,j-1};a2=out1{i-1,j};a3=out1{i-1,j+1};a4=out1{i,j-1};
    a5=out1{i,j};a6=out1{i,j+1};a7=out1{i+1,j-1};a8=out1{i+1,j};a9=out1{i+1,j+1};
    a11=a1((5:8),(5:8))+a2((5:8),(1:4))+a4((1:4),(5:8))+a5((1:4),(1:4));
    out_i{i,j}=a11;
    end
end
out_i=cell2mat(out_i);
save('tri_windowed_image_decimation.mat','out_i');
save('deap3.mat','out_i');

% figure;
% imshow(I);title('original image');
% figure
% imshow(out_i);title('encoded image');
end

