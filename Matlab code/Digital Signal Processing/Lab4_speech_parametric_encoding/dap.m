function [] = dap(bits,x)
fs=8000;
[r,voice,a,e,g]=encode_lpc(bits,x,fs);
k=find(voice==1);

% x=audioread('speech.wav');
g1=g(k);

a1=r(k);
k1=find(a1>0,159);
m1=x(k);
n1=find(m1>0,159);

l1=max(x(k))+0.1;
l2=min(x(k))-0.1;

a1(k1)=a1(k1)./max(abs(a1(k1)));
m1(n1)=m1(n1)./max(abs(m1(n1)));

t=0:(1/fs):(length(n1)-1)/fs;
figure;
subplot(4,1,1);
plot(t,m1(n1));
xlabel('time(seconds)');
ylabel('amplitude');
title('voiced segment of speech');

l=a(k);
subplot(4,1,2);
stem(l(1:18));
title('predictor coefficients');

% subplot(4,1,3);
% plot(t,e(k));ylim([l2,l1]);
% xlabel('time(seconds)');
% ylabel('amplitude');
% title('residual error');

subplot(4,1,3);
stem(g1(1));
title('gain');

subplot(4,1,4);
plot(t,a1(k1));
% plot(t,r(k)./max(abs(r(k))));
% ylim([l2,l1]);
xlabel('time(seconds)');
ylabel('amplitude');
title('synthetic speech of voiced segment');
end




