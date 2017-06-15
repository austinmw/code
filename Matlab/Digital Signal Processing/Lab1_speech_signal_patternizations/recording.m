function [] = recording()
%This function is created for you to record the sentence "two plus seven is
% less than 10" into MATLAB. Please speak the sentence "two plus seven is
% less than 10" after running this function in EC516Lab1.m. You will be
% prompted to speak this sentence in the command window. The output is
% the original patternization of the signal data(input speech signal data) and is saved as speech.wav.
Fs=44100;
recObj = audiorecorder(Fs,16,1);
disp('Start speaking near the mic the sentence "2 plus seven is less than 10"')
recordblocking(recObj, 4);
disp('End of Recording.');
y1=getaudiodata(recObj);
y=y1./abs(max(y1));
disp('saving file as speech.wav...');
audiowrite('speech.wav',y,Fs);
end

