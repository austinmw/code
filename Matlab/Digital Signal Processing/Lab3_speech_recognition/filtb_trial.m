% [X,MN,MX]=melbankm(10,length(y),fs,0,0.5,'f');
% 
% plot(real(X(2,:)));


% H=cell(10,1);
% for i=1:74
% for w=0:(pi/500):pi
%    H0(j)=(1/74)*(sin(74*w/2))./(sin(w/2));
%    j=j+1;
% end
% end
M=147;
H=cell(10,1);
% for i=1:74
r=1;
    for j=0:13
    w=0:(pi/1000):pi;
   H{r,1}=(1/M).*exp((-1i.*(w-(2*pi*j)/M).*((M-1)/2))).*(sin(M.*(w-2*pi*j/M)./2))./(sin((w-2*pi*j/M)./2));
   H{r,1}(isnan(H{r,1}))=1;
   r=r+1;
    end
% end

w=(w./(2*pi))*fs;
figure;
% w=0:(pi/500):pi;
for i=10:13
% plot(w,10*log10(abs(H{i,1})));
subplot(4,1,i-9)
plot(w,(abs(H{i,1})));
xlabel('frequency(Hz)');ylabel('|Hk(f)|');
% xlim([0 20*pi/147]);
xlim([0 4000]);
% ylim([-30 0])
% hold on;
end
xlabel('frequency(Hz)');ylabel('|Hk(f)|');

q=yes_wav{15,1};
q=filter_rec(q);
t=0:(1/fs):(length(q)-1)/fs;
figure;
plot(t,q);
zoom(1,2);
xlabel('time(seconds)');ylabel('amplitude');


% frequency response

h=cell(14,1);
j=1;
for i=0:13
   r=hamming(M); 
   n=0:M-1;
   sh=exp(1i*2*pi*i*n/M);
   h{j,1}=r.*sh';
   j=j+1;
end

op=cell(14,1);
for i=1:14
   op{i,1}=conv(h{i,1},q); 
end

t=0:(1/fs):(length(op{1,1})-1)/fs;
figure;
% plot(real(op{1,1}));
for i=1:4
    subplot(5,1,i);
    plot(t,real(op{i,1}));
%     ylim([-1 1]);
end

en_try=en_filtb(op);
figure;
bar(log(en_try(1:12)));
xlabel('filter bank index');ylabel('log(energy)');

% figure;
% plot(y);
% figure;
% plot(real(op{14,1}));  
% freqz(h{4,1});

en=cell(14,1);
for i=1:14
    s=op{i,1};
   en{i,1}=sum((real(s)).^2);
end

yes_en1=horzcat(yes_en{:,1});
no_en1=horzcat(no_en{:,1});


features_tr=horzcat(yes_en1(:,(1:100)),no_en1(:,(1:100)));
features_tr=features_tr';
labels_tr=vertcat(ones(100,1),2.*ones(100,1));

SVMModel=svmtrain(features_tr,labels_tr);



% features_te=horzcat(yes_en1(:,(81:100)),no_en1(:,(81:100)));
% features_te=features_te';
 labs=predict(model_svm,features_te(:,(10:14)));

% y=record_and_filter;
[y,fs]=audioread('speech.wav');
op1=resp_filtb(y);
en=log(en_filtb(op1));
en1=en((10:14),1);
label=svmclassify(svmmodel,en1');
save('svm_model','svmmodel');

figure;
bar(en);
hold on;
plot(en,'r','LineWidth',4);

yes_en1=horzcat(yes_en{:,1});
no_en1=horzcat(no_en{:,1});


[y1,x]=record_and_filter;
sound(y1,fs);
op=resp_filtb(y1);
% en=en_filtb(op);
en1=log(en_filtb(op));


yes_en1=horzcat(yes_en{:,1});
no_en1=horzcat(no_en{:,1});