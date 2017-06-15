load spectraref
load fivenm
load fiftynm
load onehundrednm
load twohundrednm
load customnp
load salt5
load salt10
load salt15

figure;
t5x = spectraref(1:end,1);
t5y = fivenm(1:end,2); % ./ spectraref(1:end,2);
subplot(2,2,1);
plot(t5x,t5y);
[maxval5 maxi5] = max(fivenm(1:end,2));
maxwl5 = num2str(fivenm(maxi5,1));
title(sprintf('5nm peak wavelength: %s', maxwl5));
xlabel('Wavelength (nm)');
ylabel('Optical Intensity');

t50x = t5x;
t50y = fiftynm(1:end,2); % ./ spectraref(1:end,2);
subplot(2,2,2);
plot(t50x,t50y);
[maxval50 maxi50] = max(fiftynm(1:end,2));
maxwl50 = num2str(fiftynm(maxi50,1));
title(sprintf('50nm peak wavelength: %s', maxwl50));
xlabel('Wavelength (nm)');
ylabel('Optical Intensity');

t100x = t5x;
t100y = onehundrednm(1:end,2); % ./ spectraref(1:end,2);
subplot(2,2,3);
plot(t100x,t100y);
[maxval100 maxi100] = max(onehundrednm(1:end,2));
maxwl100 = num2str(onehundrednm(maxi100,1));
title(sprintf('100nm peak wavelength: %s', maxwl100));
xlabel('Wavelength (nm)');
ylabel('Optical Intensity');

t200x = t5x;
t200y = twohundrednm(1:end,2); % ./ spectraref(1:end,2);
subplot(2,2,4);
plot(t200x,t200y);
[maxval200 maxi200] = max(twohundrednm(1:end,2));
maxwl200 = num2str(twohundrednm(maxi200,1));
title(sprintf('200nm peak wavelength: %s', maxwl200));
xlabel('Wavelength (nm)');
ylabel('Optical Intensity');

figure
tcx = spectraref(1:end,1);
tcy = customnp(1:end,2); % ./ spectraref(1:end,2);
subplot(2,2,1);
plot(tcx,tcy);
[maxvalc maxic] = max(customnp(1:end,2));
maxwlc = num2str(customnp(maxic,1));
title(sprintf('Custom NP peak wavelength: %s', maxwlc));
xlabel('Wavelength (nm)');
ylabel('Optical Intensity');

ts5x = spectraref(1:end,1);
ts5y = salt5(1:end,2); % ./ spectraref(1:end,2);
subplot(2,2,2);
plot(ts5x,ts5y);
[maxvals5 maxis5] = max(salt5(1:end,2));
maxwls5 = num2str(salt5(maxis5,1));
title(sprintf('Salt 5 drops peak wavelength: %s', maxwls5));
xlabel('Wavelength (nm)');
ylabel('Optical Intensity');

ts10x = spectraref(1:end,1);
ts10y = salt10(1:end,2); % ./ spectraref(1:end,2);
subplot(2,2,3);
plot(ts10x,ts10y);
[maxvals10 maxis10] = max(salt10(1:end,2));
maxwls10 = num2str(salt10(maxis10,1));
title(sprintf('Salt 10 drops peak wavelength: %s', maxwls10));
xlabel('Wavelength (nm)');
ylabel('Optical Intensity');

ts15x = spectraref(1:end,1);
ts15y = salt15(1:end,2); % ./ spectraref(1:end,2);
subplot(2,2,4);
plot(ts15x,ts15y);
[maxvals15 maxis15] = max(salt15(1:end,2));
maxwls15 = num2str(salt15(maxis15,1));
title(sprintf('Salt 15 drops peak wavelength: %s', maxwls15));
xlabel('Wavelength (nm)');
ylabel('Optical Intensity');


3E8 / (fivenm(maxi5,1) * 10 ^ -9)
3E8 / (fiftynm(maxi50,1) * 10 ^ -9)
3E8 / (onehundrednm(maxi100,1) * 10 ^ -9)
3E8 / (twohundrednm(maxi200,1) * 10 ^ -9)
3E8 / (customnp(maxic,1) * 10 ^ -9)
3E8 / (salt5(maxis5,1) * 10 ^ -9)
3E8 / (salt10(maxis10,1) * 10 ^ -9)
3E8 / (salt15(maxis15,1) * 10 ^ -9)
