function [op] = resp_filtb(y)
% 
M=147;
h=cell(14,1);
j=1;
for i=0:13
   r=hamming(M); 
   n=0:M-1;
   sh=exp(1i*2*pi*i*n/M);
   if isrow(r)
      r=r.'; 
   end
   h{j,1}=r.*sh';
   j=j+1;
end

op=cell(14,1);
for i=1:14
   op{i,1}=conv(h{i,1},y); 
end
end