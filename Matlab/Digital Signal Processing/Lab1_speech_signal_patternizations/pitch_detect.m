function [pitch] = pitch_detect()
%This function displays the Pitch Detection Activity(PDA). The input ap is
%the APSD computed using the alternative_patternization() function.
%% detect pitch using HPS algorithm
parameters.HPS.FFT.FFTlength=44100;
parameters.HPS.window.windowSampleLength=4410;
parameters.HPS.window.overlapPercentage=0.75;
parameters.HPS.window.windowMode='hanning';
parameters.interpolation.Fs=44100;
[y,Fs]=audioread('speech.wav');
% 
a=cell(1,1);
a{1,1}=[1;2;3;4];
% a{1,1}=y.';
pit1=fHPS(parameters,y,'signal',a);
pit1=pit1(1,:);
energy=energy_zc(y,4410,round(0.25*4410),Fs);
thresh=mean(energy);
pit1((energy<thresh))=inf;
pitch=medfilt1(pit1,1);
pitch(isinf(pitch))=NaN;
pitch=medfilt1(pitch,4);
pitch=pitch(:);
med_pitch=median(pitch);
for i=1:length(pitch)
 if (~isinf(pitch(i)))
     if pitch(i)>=1.8*med_pitch
         pitch(i)=pitch(i)./2;
     end
 end
end

save('detected_pitch.mat','pitch');
