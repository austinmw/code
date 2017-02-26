function [] = alternative_patternization()
%This function computes the alternative patternisation of signal data(APSD) with time on the x-axis and
%frequency on the y-axis. 
%The output is stored %as Alternative_patternization.mat.
[x,Fs]=audioread('speech.wav');
Fs=44100;%Sampling Frequency
s=spectrogram(x,4410,round(0.75*4410),44100,Fs,'yaxis');% spectrogram computation
save('alternative_patternization.mat','s');
end

