function [] = display_pitch_detection_activity(varargin)
%This function displays the pitch detection activity(PDA). Pitch is the
%input to this function which is computed using the pitch_detect() function.
[y,Fs]=audioread('speech.wav');
pitch=importdata('detected_pitch.mat');
t=0:(4410*0.25/(44100)):(length(pitch)-1)*4410*0.25/(44100);
fileID = fopen('name.txt','r');
name=textscan(fileID,'%s');
fclose(fileID);
% if (isempty(char(name{1,1})))
% msg = 'no name';
% error(msg)
% end
figure;
spectrogram(y,4410,round(0.75*4410),44100,44100,'yaxis');ylim([0 1]);% displaying the spectrogram
colormap('parula');
hold on; 
plot(t,pitch./1000,'-r','LineWidth',1);
h=plot(t,pitch./1000,'-r','LineWidth',1);
ylim([0 1]);
if nargin==2
    xlim([varargin{1}+0.05 varargin{2}+0.05]);
end
legend(h,'detected pitch');
try
title(['pitch detection activity for ' char(name{1,1}{1,1}) ' ' char(name{1,1}{2,1})]);   
catch
title(['pitch detection activity for ' char(name{1,1}{1,1})]);       
end
saveas(gcf,'Detected_pitch_activity.jpg');
end

