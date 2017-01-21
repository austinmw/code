function shades(n,color)
figure
r = linspace(0,1,n);
g = linspace(0,1,n);
b = linspace(0,1,n);
empty = zeros(n,1);
colormat(:,1) = r;
colormat(:,2) = g;
colormat(:,3) = b;
if color == 'y'
    colormat(:,3) = empty;
elseif color == 'b'
    colormat(:,1) = empty;
    colormat(:,2) = empty;
elseif color == 'g'
    colormat(:,1) = empty;
    colormat(:,3) = empty;
elseif color == 'r'
    colormat(:,2) = empty;
    colormat(:,3) = empty;
else
    n = 1;
    colormat(:,3) = empty;
    colormat(:,2) = empty;
    colormat(:,1) = empty;
end
colormap(colormat);
image([1:n])
end
