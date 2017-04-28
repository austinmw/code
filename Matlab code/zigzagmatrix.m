
% code from stackoverflow user Amro

M = randi(100, [3 4]);                      %# input matrix

ind = reshape(1:numel(M), size(M));         %# indices of elements
ind = fliplr( spdiags( fliplr(ind) ) );     %# get the anti-diagonals
ind(:,1:2:end) = flipud( ind(:,1:2:end) );  %# reverse order of odd columns
ind(ind==0) = [];                           %# keep non-zero indices

M(ind)                                      %# get elements in zigzag order
