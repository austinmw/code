function [] = display_original_patternization(varargin)
%This function displays the original
%patternization(DOP). The original pattern is saved as Original_pattern.jpg
[y,Fs]=audioread('speech.wav');
% Fs=44100;
num=fir1(35,0.362,'low');%high pass filter to remove frequencies above 16kHz analog(=16k/44.1k digital)
y1=filter(num,1,y);
y1=y./max(abs(y));
% sound(y1,Fs);
t=0:(1/Fs):(length(y1)-1)/Fs;

% hfig=figure;
% for j=1:round((length(y1)-1)/(0.25*Fs))
%   k=plot(t,y1);
%   xlim([0.25*(j-1) 0.25*(j)]);
%   r=round((0.25*(j-1)*44100)+1):round((0.25*(j)*44100)+1);
%   try
%   sound(y1(r),44100);
%   catch
%   end
%   ylim([-1 1]);
%    pause(.25)
% end
% close(hfig);
% % end

fclose all;
fileID = fopen('name.txt','r');
name=textscan(fileID,'%s');
fclose(fileID);
if (isempty(char(name{1,1})))
msg = 'no name';
error(msg)
end
figure;
plot(t,y1);
ylim([-2 2]);
zoom(2);
if nargin==2
xlim([varargin{1} varargin{2}]);
end
try
title(['Displaying Original Patternization(DOP) for ' char(name{1,1}{1,1}) ' ' char(name{1,1}{2,1})]);
catch
title(['Displaying Original Patternization(DOP) for ' char(name{1,1}{1,1})]);
end
xlabel('Time(in seconds)');ylabel('Amplitude');
saveas(gcf,'Original_Pattern.jpg');
end

