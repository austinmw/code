function [y,x] = record_and_filter()
%record and initial filtering
fs=8000;
recObj = audiorecorder(fs,16,1);
disp('Start speaking.')
recordblocking(recObj, 5);
disp('End of Recording.');

% Play back the recording.
play(recObj);

% Store data in double-precision array.
myRecording = getaudiodata(recObj);
% myRecording((1:6000),1)=0;
% myRecording((end-6000:end),1)=0;
% n = 7;
% beginFreq = 700 / (fs/2);
% endFreq = 3999 / (fs/2);
% [b,a] = butter(n, [beginFreq, endFreq], 'bandpass');
% myRecording= filter(b, a, myRecording);
% % 
% % energy=energy_zc(myRecording,4410,4410,fs);
% % 
% % en=cell(length(energy),1);
% % for i=1:length(en)
% %    en{i,1}=energy(i).*ones(4410,1); 
% % end
% % 
% % % en1=zeros(length(myRecording)+1,1);
% % en1=vertcat(en{:,1});
% % en1(end+1:length(myRecording))=0;
% % thresh=mean(energy);
% % std_thresh=std(energy);
% % myRecording1=myRecording;
% % % myRecording1((en1<thresh))=0;
% % myRecording1((en1<thresh+0.5*std_thresh))=0;
% % 
% % 
% % % y=(myRecording1-min(myRecording1))./(max(myRecording1)-min(myRecording1));
% % y=myRecording1./max(abs(myRecording1));
y=myRecording./max(abs(myRecording));
% sound(t,fs);
end

