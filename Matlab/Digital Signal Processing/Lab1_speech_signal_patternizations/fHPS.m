function [pitches, numOfSpeaker,STFT] = fHPS(parameters,input,mode,inputCombination,frameIndex,STFT)

if strcmp(mode,'spectrum')
    
    powerSpectrum = abs(input);
    [~,b]=size(powerSpectrum);
    
elseif strcmp(mode,'signal')
    % Do STFT
    % STFT
    %STFT = cell(numOfSignals,1); numOfWindows = zeros(numOfSignals,1);
    if nargin < 6
        [STFT,numOfWindows] = fSTFT(parameters,input,parameters.HPS.FFT.FFTlength,parameters.HPS.window.windowSampleLength,parameters.HPS.window.overlapPercentage,parameters.HPS.window.windowMode);
        STFT = abs(STFT); % Get the power spectrum
    else
        numOfWindows = floor((length(input)-parameters.HPS.window.windowSampleLength*parameters.HPS.window.overlapPercentage)/(parameters.HPS.window.windowSampleLength*(1-parameters.HPS.window.overlapPercentage)));
        
    end
    
elseif strcmp(mode,'windowedSignal')
    % Do STFT
    
end

% numOfWindows = floor((length(input)-parameters.HPS.window.windowSampleLength*parameters.HPS.window.overlapPercentage)/(parameters.HPS.window.windowSampleLength*(1-parameters.HPS.window.overlapPercentage)));
% numOfWindows=b;
if nargin>=5
    numOfFrames = length(frameIndex);
else
    numOfFrames = numOfWindows;
    frameIndex = 1:numOfWindows;
end



numberOfCombinations = length(inputCombination);
if ~iscell(inputCombination)
    combination = cell(numberOfCombinations,1);
    for i = 1:numberOfCombinations
        combination{i,1} = inputCombination(i,:);
    end
    
else
    combination = inputCombination;
end

pitches = zeros(2*numberOfCombinations,numOfWindows); numOfSpeaker = zeros(numberOfCombinations,numOfWindows);
for i = 1:numOfFrames
    if frameIndex(i) == numOfWindows
        disp('');
    end
    [pitchesTemp,numOfSpeaker(:,frameIndex(i))] = fFrameHPS(parameters,combination,numberOfCombinations,STFT(:,frameIndex(i)),frameIndex(i));
    pitches(:,frameIndex(i)) = reshape(pitchesTemp.',[numberOfCombinations*2,1]);
end


end


function [pitches,numOfSpeaker] = fFrameHPS(parameters,combination,numberOfCombinations,powerSpectrum,frameIndex)

%combination = [1,2,3]; % Find the peak using a combination of different downsampled powerSpectrum


compressedPowerSpectrum = cell(numberOfCombinations,1);

shortestLength = inf*ones(numberOfCombinations,1);
for i = 1:numberOfCombinations
    for j = 1:length(combination{i})
        compressedPowerSpectrum{i}{j} = downsample(powerSpectrum,combination{i}(j));
        if shortestLength(i)>length(compressedPowerSpectrum{i}{j});
            shortestLength(i) = length(compressedPowerSpectrum{i}{j});
        end
    end
end

multipliedSpectrum = cell(numberOfCombinations,1);
for i = 1:numberOfCombinations
    multipliedSpectrum{i}  = ones(shortestLength(i),1);
    for j = 1:length(combination{i})
        multipliedSpectrum{i} = multipliedSpectrum{i}.*compressedPowerSpectrum{i}{j}(1:shortestLength(i));
    end
end

pitches = zeros(numberOfCombinations,2);
subbandWidth = parameters.interpolation.Fs/parameters.HPS.FFT.FFTlength;
numOfSpeaker = zeros(numberOfCombinations,1);
for i = 1:numberOfCombinations
    gap = ceil( 3/subbandWidth);
    [peaks,locs] = findpeaks(multipliedSpectrum{i},'SORTSTR','descend','minpeakdistance',gap); % Make sure the peaks are gap samples away
    [maxPeak,loc] = max(multipliedSpectrum{i});
    if isempty(peaks)
        numOfSpeaker(i) = 0; pitches(i,:) = [inf, inf];
    else
    if maxPeak >peaks(1)
        peaks = [maxPeak;peaks]; locs = [loc;locs];
    end
    [numOfSpeaker(i),pitches(i,:)] = fDetermineNumOfSpeaker(parameters,peaks,locs,multipliedSpectrum{i});
    end
end




plotSwitch = false;

if plotSwitch
    figure; title(strcat('HPS of ',{' '},num2str(frameIndex),'th frame')); hold on;
    freqLimit = 1000;
    freqLimitIndex = round(freqLimit/subbandWidth);
    
    subplot(numberOfCombinations(1)+1,1,1); plot((0:subbandWidth:freqLimitIndex*subbandWidth)+0.5*subbandWidth, powerSpectrum(1:freqLimitIndex+1));
    xlim([0,freqLimitIndex*subbandWidth+0.5*subbandWidth]);
    title(strcat('Power Spectrum of ',{' '},num2str(frameIndex),'th frame'));
    freqLimit = 300;
    freqLimitIndex = round(freqLimit/subbandWidth);
    for i = 1:numberOfCombinations(1)
        %subplot(combinationSize(1),1,i); plot((0:shortestLength(i)-1)*subbandWidth+0.5*subbandWidth, multipliedSpectrum{i});
        subplot(numberOfCombinations(1)+1,1,i+1); plot((0:subbandWidth:freqLimitIndex*subbandWidth)+0.5*subbandWidth, multipliedSpectrum{i}(1:freqLimitIndex+1));
        xlim([0,freqLimitIndex*subbandWidth+0.5*subbandWidth]);
        title(strcat('HPS of ',{' '},num2str(frameIndex),'th frame',{' ('},'Compression factors:',{' '},num2str(combination{i}),{')'}));
    end
    
end
end

function [numOfSpeaker,pitches] = fDetermineNumOfSpeaker(parameters,peaks,locs,powerSpectrum)
ratioThreshold = 5; % Threshold need to be chosen
pitchRange = [100 300];
harmonicFreqDiffThreshold = 5;
harmonicRatioThreshold = 5;
[numOfSpeaker,pitches] = fDetermineNumOfSpeakerSub(parameters,peaks,locs,powerSpectrum,pitchRange,ratioThreshold);


if abs(pitches(1) - pitches(2) - pitches(2)) < harmonicFreqDiffThreshold && peaks(1)/peaks(2) < harmonicRatioThreshold
    peaks(1) = []; locs(1) = [];
    [numOfSpeaker,pitches] = fDetermineNumOfSpeakerSub(parameters,peaks,locs,powerSpectrum,pitchRange,ratioThreshold);
elseif abs(pitches(2) - pitches(1) - pitches(1)) < harmonicFreqDiffThreshold && peaks(2)/peaks(1) < harmonicRatioThreshold
    peaks(2) = []; locs(2) = [];
    [numOfSpeaker,pitches] = fDetermineNumOfSpeakerSub(parameters,peaks,locs,powerSpectrum,pitchRange,ratioThreshold);
end



end


function [numOfSpeaker,pitches] = fDetermineNumOfSpeakerSub(parameters,peaks,locs,powerSpectrum,pitchRange,threshold)
if isempty(peaks)
    numOfSpeaker = 0;
    pitches(1) = inf;
    pitches(2) = inf;
elseif length(peaks) == 1
    numOfSpeaker = 1;
    pitches(1) = locs(1)*parameters.interpolation.Fs/parameters.HPS.FFT.FFTlength;
    pitches(2) = inf;
    if pitches(1) > pitchRange(2) || pitches(1) < pitchRange(1)
        pitches(1) = inf;
        numOfSpeaker = 0;
    end
else
    if peaks(1)/peaks(2) >= threshold
        numOfSpeaker = 1;
        pitches(1) = locs(1)*parameters.interpolation.Fs/parameters.HPS.FFT.FFTlength;
        pitches(2) = inf;
        if pitches(1) > pitchRange(2) || pitches(1) < pitchRange(1)
            pitches(1) = inf;
            numOfSpeaker = 0;
        end
    else
        numOfSpeaker = 2;
        pitches(1) = locs(1)*parameters.interpolation.Fs/parameters.HPS.FFT.FFTlength;
        pitches(2) = locs(2)*parameters.interpolation.Fs/parameters.HPS.FFT.FFTlength;
        if pitches(1) > pitchRange(2) || pitches(1) < pitchRange(1)
            pitches(1) = pitches(2);
            pitches(2) = inf;
            numOfSpeaker = 1;
            if pitches(1) > pitchRange(2) || pitches(1) < pitchRange(1)
                pitches(1) = pitches(2);
                pitches(2) = inf;
                numOfSpeaker = 0;
            end
        elseif pitches(2) > pitchRange(2) || pitches(2) < pitchRange(1)
            
            pitches(2) = inf;
            numOfSpeaker = 1;
        end
    end
end
end



% This function is designed to perform STFT on the input signal
function [mic1WindowedSTFT,numOfWindows] = fSTFT(parameters,signal,FFTlength,windowSampleLength,overlapPercentage,windowMode)

overlapSampleLength = floor(overlapPercentage*windowSampleLength);
nonOverlapSampleLength = windowSampleLength - overlapSampleLength;
numOfWindows = floor((length(signal)-windowSampleLength)/nonOverlapSampleLength)+1;
if numOfWindows == 0
    disp('ERROR: window length is longer than the signal length');
end

mic1Windowed = fWindowing( signal, windowSampleLength, overlapSampleLength, windowMode);

mic1WindowedSTFT = zeros(FFTlength,numOfWindows);

for j = 1:numOfWindows
    mic1WindowedSTFT(:,j)=fft(mic1Windowed(j,:)',FFTlength);
end

end
