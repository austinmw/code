function [] = display_alternative_patternization(varargin)
%This function display the alternative patternisation(DAP) of the speech signal data with time on the x-axis and
%frequency on the y-axis. The generated image is saved as Alternative_Patternization.jpg 

[x,Fs]=audioread('speech.wav');
fileID = fopen('name.txt','r');
name=textscan(fileID,'%s');
fclose(fileID);
if (isempty(char(name{1,1})))
msg = 'no name';
error(msg)
end
figure;
spectrogram(x,4410,round(0.75*4410),44100,Fs,'yaxis');ylim([0 1]);% displaying the spectrogram
% displaying the spectrogram
ylim([0 1])
if nargin==2
    xlim([varargin{1}+0.05 varargin{2}+0.05]);
end
colormap('parula');
try
title(['Displaying Alternative Patternization(DAP) for ' char(name{1,1}{1,1}) ' ' char(name{1,1}{2,1})]);
catch
title(['Displaying Alternative Patternization(DAP) for ' char(name{1,1}{1,1})]);    
end
saveas(gcf,'Alternative_Pattern.jpg');
end

