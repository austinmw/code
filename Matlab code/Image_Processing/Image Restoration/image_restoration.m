% Austin Welch
% EC520 HW10.1
% Image Restoration
% Image used: barbara.tif

clear; clc; tic;
%% (a) Original and noisy images
% Read the original image u into a double matrix and scale its amplitude to
% 0-1 range. Compute two noisy observations v of image u: v_G by adding 
% zero-mean Gaussian noise with variance 0.005 and v_sp by adding 
% salt-and-pepper noise with noise density of 0.1 (use imnoise). Display 
% and print (1 page) the three images in one row using subplot. Are the 
% images severely distorted? Calculate PSNR in each case (remember images 
% are in 0-1 range) and include it in the title.

u = imread('barbara.tif'); % read image
u = mat2gray(u); % normalize to (0,1)
Vg = imnoise(u, 'gaussian', 0, 0.005); % N(0,0.005) noise 
Vsp = imnoise(u,'salt & pepper', 0.1); % salt&pepper noise
sz = size(u,1);


figure(1);
subplot(3,1,1); imshow(u); title('Original', 'FontSize', 9);
subplot(3,1,2); imshow(Vg); 
title(sprintf('Gaussian noise, PSNR = %0.4f', psnr(Vg,u)), 'FontSize', 9);
subplot(3,1,3); imshow(Vsp); 
title(sprintf('Salt-and-pepper noise, PSNR = %0.4f', psnr(Vsp,u)), ...
    'FontSize', 9);


% Comments:
% The salt-and-pepper distorts the image more than the gaussian noise
% with these particular parameters. The noise is not significant enough
% that you are no longer able to identify the picture.



%% (b)  Reduction of Gaussian noise
% Apply the following restoration methods to the observarion with Gaussian
% noise V_g:
% (i) 2-D average filter with 3x3, 5x5, 7x7 masks (filter2),
avgG3 = filter2(ones(3)/3^2,Vg);
avgG5 = filter2(ones(5)/5^2,Vg);
avgG7 = filter2(ones(7)/7^2,Vg);
% (ii) 2-D median filter with 3x3,5x5,7x7 masks (medfilt2),
medG3 = medfilt2(Vg,[3 3]);
medG5 = medfilt2(Vg,[5 5]);
medG7 = medfilt2(Vg,[7 7]);
% (iii) 2-D Wiener filter with 3x3,5x5,7x7 masks (wiener2),
wienG3 = wiener2(Vg,[3 3]);
wienG5 = wiener2(Vg,[5 5]);
wienG7 = wiener2(Vg,[7 7]);

% (iv) 2-D MAP restoration 
nPasses = 3; % number of iterations to repeat MAP estimation
lambdasG = [0.01, 0.05, 0.1]; % Gibbs energy coefficients
MAP_G = cell(1,length(lambdasG)); % MAP estimates for different lambdas
PSNRs_G = zeros(1,length(lambdasG)); % PSNRs for different MAP estimates

% Main loop
for i=1:length(lambdasG) % iterate over lambda coefficients    
    % Call to 2-D MAP estimator function
    MAP_G{i} = MAP_restoration_2D(Vg,nPasses,lambdasG(i));
    % PSNR between MAP estimate and original image
    PSNRs_G(i) = psnr(MAP_G{i},u); 
end

% Plots
figure(2);
subplot(4,3,1); imshow(avgG3); title(sprintf('Mean 3x3, PSNR: %0.4f', ...
    psnr(Vg,avgG3)), 'FontSize', 9);
subplot(4,3,2); imshow(avgG5); title(sprintf('Mean 5x5, PSNR: %0.4f', ...
    psnr(Vg,avgG5)), 'FontSize', 9);
subplot(4,3,3); imshow(avgG7); title(sprintf('Mean 7x7, PSNR: %0.4f', ...
    psnr(Vg,avgG7)), 'FontSize', 9);
subplot(4,3,4); imshow(medG3); title(sprintf('Median 3x3, PSNR: %0.4f', ...
    psnr(Vg,medG3)), 'FontSize', 9);
subplot(4,3,5); imshow(medG5); title(sprintf('Median 5x5, PSNR: %0.4f', ...
    psnr(Vg,medG5)), 'FontSize', 9);
subplot(4,3,6); imshow(medG7); title(sprintf('Median 7x7, PSNR: %0.4f', ...
    psnr(Vg,medG7)), 'FontSize', 9);
subplot(4,3,7); imshow(wienG3); title(sprintf('Wiener 3x3, PSNR: %0.4f', ...
    psnr(Vg,wienG3)), 'FontSize', 9);
subplot(4,3,8); imshow(wienG5); title(sprintf('Wiener 5x5, PSNR: %0.4f', ...
    psnr(Vg,wienG5)), 'FontSize', 9);
subplot(4,3,9); imshow(wienG7); title(sprintf('Wiener 7x7, PSNR: %0.4f', ...
    psnr(Vg,wienG7)), 'FontSize', 9);
subplot(4,3,10); imshow(MAP_G{1}); 
title(sprintf('MAP, lambda=%0.2f, PSNR: %0.4f', lambdasG(1), PSNRs_G(1)), ...
    'FontSize', 9);
subplot(4,3,11); imshow(MAP_G{2}); 
title(sprintf('MAP, lambda=%0.2f, PSNR: %0.4f', lambdasG(2), PSNRs_G(2)), ...
    'FontSize', 9);
subplot(4,3,12); imshow(MAP_G{3}); 
title(sprintf('MAP, lambda=%0.2f, PSNR: %0.4f', lambdasG(3), PSNRs_G(3)), ...
    'FontSize', 9);


%% (c) Reduction of salt-and-pepper noise
% Redo everything for s&p, with lambdas of 0.15,0.25,0.35

% (i) 2-D average filter with 3x3, 5x5, 7x7 masks (filter2),
avgSP3 = filter2(ones(3)/3^2,Vsp);
avgSP5 = filter2(ones(5)/5^2,Vsp);
avgSP7 = filter2(ones(7)/7^2,Vsp);
% (ii) 2-D median filter with 3x3,5x5,7x7 masks (medfilt2),
medSP3 = medfilt2(Vsp,[3 3]);
medSP5 = medfilt2(Vsp,[5 5]);
medSP7 = medfilt2(Vsp,[7 7]);
% (ii) 2-D Wiener filter with 3x3,5x5,7x7 masks (wiener2),
wienSP3 = wiener2(Vsp,[3 3]);
wienSP5 = wiener2(Vsp,[5 5]);
wienSP7 = wiener2(Vsp,[7 7]);

% (iv) 2-D MAP restoration 
nPasses = 3; % number of iterations to repeat MAP estimation
lambdasSP = [0.15,0.25,0.35]; % Gibbs energy coefficients
MAP_SP = cell(1,length(lambdasSP)); % MAP estimates for different lambdas
PSNRs_SP = zeros(1,length(lambdasSP)); % PSNRs for different MAP estimates

% Main loop
for i=1:length(lambdasSP) % iterate over lambda coefficients    
    % Call to 2-D MAP estimator function
    MAP_SP{i} = MAP_restoration_2D(Vsp,nPasses,lambdasSP(i));
    % PSNR between MAP estimate and original image
    PSNRs_SP(i) = psnr(MAP_SP{i},u); 
end
toc % elapsed time

% Plots
figure(3);
subplot(4,3,1); imshow(avgSP3); title(sprintf('Mean 3x3, PSNR: %0.4f', ...
    psnr(Vg,avgSP3)), 'FontSize', 9);
subplot(4,3,2); imshow(avgSP5); title(sprintf('Mean 5x5, PSNR: %0.4f', ...
    psnr(Vg,avgSP5)), 'FontSize', 9);
subplot(4,3,3); imshow(avgSP7); title(sprintf('Mean 7x7, PSNR: %0.4f', ...
    psnr(Vg,avgSP7)), 'FontSize', 9);
subplot(4,3,4); imshow(medSP3); title(sprintf('Median 3x3, PSNR: %0.4f', ...
    psnr(Vg,medSP3)), 'FontSize', 9);
subplot(4,3,5); imshow(medSP5); title(sprintf('Median 5x5, PSNR: %0.4f', ...
    psnr(Vg,medSP5)), 'FontSize', 9);
subplot(4,3,6); imshow(medSP7); title(sprintf('Median 7x7, PSNR: %0.4f', ...
    psnr(Vg,medSP7)), 'FontSize', 9);
subplot(4,3,7); imshow(wienSP3); title(sprintf('Wiener 3x3, PSNR: %0.4f', ...
    psnr(Vg,wienSP3)), 'FontSize', 9);
subplot(4,3,8); imshow(wienSP5); title(sprintf('Wiener 5x5, PSNR: %0.4f', ...
    psnr(Vg,wienSP5)), 'FontSize', 9);
subplot(4,3,9); imshow(wienSP7); title(sprintf('Wiener 7x7, PSNR: %0.4f', ...
    psnr(Vg,wienSP7)), 'FontSize', 9);
subplot(4,3,10); imshow(MAP_SP{1}); 
title(sprintf('MAP, lambda=%0.2f, PSNR: %0.4f', lambdasSP(1), PSNRs_SP(1)), ...
    'FontSize', 9);
subplot(4,3,11); imshow(MAP_SP{2}); 
title(sprintf('MAP, lambda=%0.2f, PSNR: %0.4f', lambdasSP(2), PSNRs_SP(2)), ...
    'FontSize', 9);
subplot(4,3,12); imshow(MAP_SP{3}); 
title(sprintf('MAP, lambda=%0.2f, PSNR: %0.4f', lambdasSP(3), PSNRs_SP(3)), ...
    'FontSize', 9);
