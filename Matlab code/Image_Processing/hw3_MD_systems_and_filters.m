h = [0 0 1 1 1 0 0;0 1 2 2 2 1 0; 1 2 3 3 3 2 1; 1 2 3 4 3 2 1; 
    1 2 3 3 3 2 1; 0 1 2 2 2 1 0; 0 0 1 1 1 0 0];
h = h/68;
rho = 2*sqrt(3);
range = linspace(-rho,rho,64);

% 3.a.
figure(1);
subplot(3,2,1);
stem3(h);
title('2-D Impulse response');

subplot(3,2,2);
f = freqz2(h);
m = abs(f);
contour(range,range,f,'ShowText','on');
title('2-D Magnitude response');
caxis([0, 1]);
colorbar;

subplot(3,2,3);
surf(range,range,m);
title('2-D Magnitude response');

subplot(3,2,4);
plot(range,m(64/2,:));
title('1-D Magnitude response for f_{y}= 0');

subplot(3,2,5);
p = angle(f);
surf(range,range,p);
title('2-D Phase response');

subplot(3,2,6);
plot(range,p(64/2,:));
title('1-D Phase response for f_{y} = 0');

text(-6.5,14,'HW3 #3.b')

%3.d.
figure(2);
k = zeros(7);
sizek = round(size(k)/2);
k(sizek,sizek) = 1;
g = k - h;

subplot(3,2,1);
stem3(g);
title('2-D Impulse response');

subplot(3,2,2);
f = freqz2(g);
m = abs(f);
contour(range,range,f,'ShowText','on');
title('2-D Magnitude response');
caxis([0, 1]);
colorbar;

subplot(3,2,3);
surf(range,range,m);
title('2-D Magnitude response');

subplot(3,2,4);
plot(range,m(64/2,:));
title('1-D Magnitude response for f_{y}= 0');

subplot(3,2,5);
p = angle(f);
surf(range,range,p);
title('2-D Phase response');

subplot(3,2,6);
plot(range,p(64/2,:));
title('1-D Phase response for f_{y} = 0');


% 3.e.
figure(3);
B = imread('barbara.tif');
subplot(1,3,1);
imshow(B);
title('Original');

subplot(1,3,2);
f1 = filter2(h,B);
imshow(f1,[0 255]);
title('Filter h');

subplot(1,3,3);
f2 = filter2(g,B);
imshow(f2,[0 255]);
title('Filter g');

