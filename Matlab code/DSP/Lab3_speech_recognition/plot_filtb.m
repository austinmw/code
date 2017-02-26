function [] = plot_filtb(type)
%plot the dft filter bank

M=147;
H=cell(10,1);
% for i=1:74
r=1;
    for j=0:13
    w=0:(pi/10000):pi;
   H{r,1}=(1/M).*exp((-1i.*(w-(2*pi*j)/M).*((M-1)/2))).*(sin(M.*(w-2*pi*j/M)./2))./(sin((w-2*pi*j/M)./2));
   H{r,1}(isnan(H{r,1}))=1;
   r=r+1;
    end
% end

fs=44100;
w=(w./(2*pi))*fs;
figure;
% w=0:(pi/500):pi;

if type==1
for i=1:14
% plot(w,10*log10(abs(H{i,1})));
plot(w,(abs(H{i,1})));
% xlim([0 20*pi/147]);
xlim([0 4000]);
% ylim([-30 0])
hold on;
end
xlabel('frequency(Hz)');ylabel('|Hk(f)|');
title('DFT Filterbank');
else
for i=1:14
plot(w,10*log10(abs(H{i,1})));
plot(w,(abs(H{i,1})));
% % xlim([0 20*pi/147]);
xlim([0 4000]);
ylim([-10 0])
hold on;
end 
xlabel('frequency(Hz)');ylabel('|Hk(f)| (in dB)');
end
end

