function shades(n,color)

if color ~= 'r' && color ~= 'g' && color ~= 'b' && color ~= 'y'
    n = 1;
end

r = linspace(0,1,n);
g = linspace(0,1,n);
b = linspace(0,1,n);

colormat(:,1) = r;
colormat(:,2) = g;
colormat(:,3) = b;

colormap(colormat);

end



