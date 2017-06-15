function hw4_Gaussian(M,var,delta)

% An M-file to generate a (2*M+1) x (2*M+1) Gaussian signal
% with variance "var":
%
%		exp^(-(x^2+y^2)/var)
%
% and evaluate its Continuous-Space Fourier Transform (from analytic calculations)
% and then compute its 2-D FFT.
%
% Example: 127, 1, 1.0352/0.7

%Y = double(zeros(2*M+1));

% Generate a (2*M+1) x (2*M+1) mesh gri and scale it to be delta.
m = meshgrid(-M:1:M, -M:1:M);
n = meshgrid(-M:1:M, -M:1:M)';
x = delta.*m;
y = delta.*n;
Gauss = exp(-(x.^2+y.^2)/var);

% Sample the Voronoi cell of the recpirocal lattice: (-1/2*delta:1/2*delta)
% by (-1/2*delta:1/2*delta) on a grid of (2*M+1) x (2*M+1) points, and
% evaluate the analytic CSFT on this grid.
fx = 1/ (2*delta) *m/M;
fy = 1/( 2*delta) *n/M;
Gauss_ft = pi * exp(-pi*pi*var*(fx.^2+fy.^2));

% Calculate the DFT of the Gaussian signal and scale it by delta^2 to
% account for the scaling factor equal to the determinant of lattice Lambda
% in the equation for the spectrum of the sampled signal as a function of
% the spectrum of the underlying continuous-space signal.
Gauss_fft2 = abs(fftshift(fft2(ifftshift(Gauss))));
Gauss_fft2 = Gauss_fft2.*delta.*delta;

% Plot the results.
figure(1);
subplot(2,4,1);
imshow(Gauss,[]); axis image;
title(['Gaussian, ', num2str(2*M+1), 'x', num2str(2*M+1), ', var=', num2str(var)]);
subplot(2,4,5);
mesh(x,y,Gauss); axis tight;

subplot(2,4,2);
imshow(Gauss_ft, []); axis image;
title(['Analytic FT, \Delta=', num2str(delta)]);
subplot(2,4,6);
mesh(fx,fy,Gauss_ft); axis tight;

subplot(2,4,3);
imshow(Gauss_fft2,[]); axis image;
title(['FFT2, \Delta=' num2str(delta)]);
subplot(2,4,7);
mesh(fx,fy,Gauss_fft2); axis tight;

subplot(2,4,4);
[cs,h] = contour(fx,fy,Gauss_ft,[0.1 0.314 0.628 1.0 1.5 2.0]);
%clabel(cs,h,); colorbar;
title(['Analytic FT, \Delta=', num2str(delta)]);
set(h,'ShowText','on'); axis square;

subplot(2,4,8);
[cs,h] = contour(fx,fy,Gauss_fft2,[0.1 0.314 0.628 1.0 1.5 2.0]);
title(['FFT2, \Delta=' num2str(delta)]);
set(h,'ShowText','on'); axis square;

eval(['print -depsc2 Plot_Gaussian_delta_' num2str(delta) '.eps'])

end

