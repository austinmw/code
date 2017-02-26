function [SVMModel,yes_energy,no_energy] = train_svm()
%

M=200;
no=cell(M,1);j=1;
for i=0:M-1
    k=num2str(i);
    no{j,1}=['no',k,'.wav'];
    j=j+1;
end

no_wav=cell(M,1);% no training data
no_energy=cell(M,1);
no_energy_mfcc=cell(M,1);


fs=44100;
for i=1:M
   r=audioread(no{i,1}); 
   t=r(:,1);
   t=filt_rec(t);
   t=t./(max(abs(t)));
   no_wav{i,1}=t;
   op=resp_filtb(t);
   no_energy{i,1}=log(en_filtb(op));
   no_energy_mfcc{i,1}=mfcc_vis(t);

%    s_no(i)=bandpower(t,fs,[0 2000])./bandpower(t,fs,[2000 22049]);
end

yes=cell(M,1);j=1;
for i=0:M-1
    k=num2str(i);
    yes{j,1}=['yes',k,'.wav'];
    j=j+1;
end

yes_wav=cell(M,1);% yes training data
yes_energy=cell(M,1);
yes_energy_mfcc=cell(M,1);


for i=1:M
   r=audioread(yes{i,1}); 
   t=r(:,1);
   t=filt_rec(t);
   t=t./(max(abs(t)));
   yes_wav{i,1}=t;
   op=resp_filtb(t);
   yes_energy{i,1}=log(en_filtb(op));
   yes_energy_mfcc{i,1}=mfcc_vis(t);
%  s_yes(i)=bandpower(t,fs,[0 2000])./bandpower(t,fs,[2000 22049]);
end

yes_en1=horzcat(yes_energy{:,1});
no_en1=horzcat(no_energy{:,1});

yes_en2=horzcat(yes_energy_mfcc{:,1});
no_en2=horzcat(no_energy_mfcc{:,1});


features_tr=horzcat(yes_en2((1:14),(1:M)),no_en2((1:14),(1:M)));
features_tr=features_tr';
labels_tr=vertcat(ones(M,1),2.*ones(M,1));
SVMModel=ClassificationTree.fit(features_tr,labels_tr,'NVarToSample',4);
%  SVMModel=svmtrain(features_tr,labels_tr);
 save('svm_model1','SVMModel');
end
