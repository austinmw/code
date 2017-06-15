%{
Austin Welch
EC520
1/30/17

HW1 #3
%}

A = 1.0;
f = [4 3];
x1 = linspace(0.0,1.0,256);
x2 = x1;
phi = pi;

M = zeros(256,256);
for i = 1:256
    for j = 1:256
        x = [x1(i);x2(j)];
        val = A*cos(2*pi*f*x+phi);
        M(i,j) = val;
    end
end

figure
% image axes with regular scaling
subplot(2,2,1)
imshow(M)
title('2D cosine f=(4,3) c/ph, \phi=\pi image axes')
xlabel('x[ph]')
ylabel('y[ph]')
axis on

% image axes normalized
subplot(2,2,3)
imshow(M,'XData',[0 1],'YData',[0 1])
title('2D cosine f=(4,3) c/ph, \phi=\pi image axes')
xlabel('x[ph]')
ylabel('y[ph]')
axis on

% cartesian axes with regular scaling
subplot(2,2,2)
imshow(M)
title('2D cosine f=(4,3) c/ph, \phi=\pi cartesian axes')
xlabel('x[ph]')
ylabel('y[ph]')
axis on
axis xy

% cartesian axes normalized
subplot(2,2,4)
imshow(M,'XData',[0 1],'YData',[0 1])
title('2D cosine f=(4,3) c/ph, \phi=\pi cartesian axes')
xlabel('x[ph]')
ylabel('y[ph]')
axis on
axis xy


