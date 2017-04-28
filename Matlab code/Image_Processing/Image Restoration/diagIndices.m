function [ilist,jlist] = diagIndices(sz)

    M = reshape(1:sz^2, [sz sz])';

    ind = reshape(1:numel(M), size(M));         
    ind = fliplr( spdiags( fliplr(ind) ) );     
    ind(:,1:2:end) = flipud( ind(:,1:2:end) );  
    ind(ind==0) = [];                           
    order = M(ind); 

  
    ilist = zeros(length(order),1);
    jlist = zeros(length(order),1);
    
    for n=1:length(order)
       [x,y] = find(M==order(n));
       ilist(n) = x;
       jlist(n) = y;
    end    
 
    %mat = [ilist,jlist];
    %save('diaginds.mat','mat');
end


