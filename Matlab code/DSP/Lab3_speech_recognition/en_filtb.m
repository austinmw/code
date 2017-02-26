function [en] = en_filtb(op)
%
en=zeros(14,1);
for i=1:14
    s=op{i,1};
   en(i,1)=sum((real(s)).^2);
end
end

