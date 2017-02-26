function [] = encoded_rect_window_decimation_25()
%Encode the windowed image using  25% decimation 

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
out=cell(m,n);

for i=1:m
    for j=1:n
   a=blkim{i,j};
   masked_a=a.*window2(8,8,@rectwin);   
   masked_a1=imresize(masked_a,0.25);

   masked_a=imresize(masked_a1,4);
   out{i,j}=masked_a;
    end
end
out1=out;

out_i=cell2mat(out1);
% save('rectwindowed_image_decimation.mat','out_i');
save('deap2.mat','out_i');

% figure;
% imshow(I);title('original image');
% figure
% imshow(out_i);title('encoded image');
end

