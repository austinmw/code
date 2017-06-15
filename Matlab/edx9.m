
[r c] = size(mat);
newmat = zeros(c,r);
for i = 1:r
    for j = 1:c
        newmat(j,i) = mat(i,j);
    end
end
[r c] = size(newmat);
matsum = zeros(1,c);
for i = 1:c
    for j = 1:r
        matsum(i) = matsum(i) + newmat(j,i);
    end
end



