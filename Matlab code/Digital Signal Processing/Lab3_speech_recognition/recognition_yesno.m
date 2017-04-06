function [] = recognition_yesno()
% recognize yes/no
[y,fs]=audioread('speech.wav');
op1=resp_filtb(y);
en=log(en_filtb(op1));
% en1=en((1:14),1);

[en1,k]=mfcc_vis(y);
svmmodel=importdata('svm_model1.mat');
% svmmodel1=importdata('svm_model_yes_yeah.mat');
% label=svmclassify(svmmodel,en1');
label=predict(svmmodel,en1');
% 
% if (label==1)
%     label=svmclassify(svmmodel1,en1');
% end
%     

% if mean(en((10:14),1))>=5.6
%     label=1;
% else
%     label=2;
% end
% k=importdata('alternative_patternization.mat');
figure;
bar(en);
hold on;
plot(en,'r','LineWidth',4);
if label==1
    text(14,12,'Yes','Color','red','FontSize',20);
elseif label==2
    text(1,12,'No','Color','red','FontSize',20);
else
    text(1,12,'Yeah','Color','red','FontSize',14);   
end
xlabel('index of filterbank');ylabel('log energy of output from each filterbank');
title('Recognition of yes/no');
saveas(gcf,'Recognized_speech.jpg');
end

