%{
Austin Welch
EC520
HW2 #3
%}

% (a)
figure(1);
%U1_[x]
x = [-16:1:15];
y = x;
[X_1,X_2] = meshgrid(x,y);
r=4;
z_1 = (abs(X_1)<=r) .* (abs(X_2)<=r);
subplot(3,1,1);
stem3(x,y,z_1);
title('u_{1}[x]');

%U_2[x] (shift by [8 8])
z_2 = circshift(z_1,[8 8]);
subplot(3,1,2);
stem3(x,y,z_2);
title('u_{2}[x]');

%U_3[x]
subplot(3,1,3);
z_3 = z_2/2 + circshift(z_1,[-8 -8])/2;
stem3(x,y,z_3);
title('u_{3}[x]');

% (b)
figure(2);
%FFT 1
F1 = fft2(z_1);
I1 = imag(F1);
F1 = fftshift(F1); % Center FFT
minI1 = min(min(I1));
maxI1 = max(max(I1));
p1 = sprintf('Imag part of u1 FFT max: %d, min: %d', minI1,maxI1);
disp(p1);
M1 = abs(F1); % Get the magnitude
P1 = angle(F1);
subplot(2,3,1);
surf(M1);
title('U_{1}');
subplot(2,3,4);
surf(P1);

% FFT 2
F2 = fft2(z_2);
I2 = imag(F2);
F2 = fftshift(F2); % Center FFT
minI2 = min(min(I2));
maxI2 = max(max(I2));
p2 = sprintf('Imag part of u2 FFT max: %d, min: %d', minI2,maxI2);
disp(p2);
M2 = abs(F2); % Get the magnitude
P2 = angle(F2);
subplot(2,3,2);
surf(M2);
title('U_{2}');
subplot(2,3,5);
surf(P2);

% FFT 3
F3 = fft2(z_3);
I3 = imag(F3);
F3 = fftshift(F3); % Center FFT
minI3 = min(min(I3));
maxI3 = max(max(I3));
p3 = sprintf('Imag part of u3 FFT max: %d, min: %d', minI3,maxI3);
disp(p3);
M3 = abs(F3); % Get the magnitude
P3 = angle(F3);
subplot(2,3,3);
surf(M3);
title('U_{3}');
subplot(2,3,6);
surf(P3);

