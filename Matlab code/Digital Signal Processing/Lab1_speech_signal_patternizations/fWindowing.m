% Giving the signal and the windowLength & overlapLength of windows in 
% numebr of samples, produce windowed signals

% Last modified: WZ @ Apr 6, 2016 19:12 works with non integer number of
% overlapSampleLength


% DEBUG: The two if conditions can actually be combined. Only the else part
% is needed
function [ output ] = fWindowing( signal, windowSampleLength, overlapSampleLength,mode )

    switch nargin
        case 3
            output = fWindowing_rectangular( signal, windowSampleLength, overlapSampleLength );
        case 4
            if strcmp(mode, 'rectangular')
                output = fWindowing_rectangular( signal, windowSampleLength, overlapSampleLength );
            elseif strcmp(mode,'triangular');
                output = fWindowing_triangular( signal, windowSampleLength, overlapSampleLength );
            elseif strcmp(mode,'hanning');
                output = fWindowing_hanning( signal, windowSampleLength, overlapSampleLength );    
            else
                error('ERROR in fWindowing: Unspecified mode is given');
            end
            
        otherwise
            error('ERROR in fWindowing: Incorrect number of inputs are given');
            
    end


end




function [ output ] = fWindowing_rectangular( signal, windowSampleLength, overlapSampleLength )
if overlapSampleLength == 0
    numOfWindows = floor(length(signal)/(windowSampleLength));
    if numOfWindows == 0
        error('ERROR in fWindowing: window length is longer than the signal length'); 
    end
    output = zeros(numOfWindows,windowSampleLength);
    for i = 1:numOfWindows
        output(i,:) = signal((i-1)*windowSampleLength+1 : windowSampleLength*(i));
    end
else
    nonOverlapSampleLength = windowSampleLength - overlapSampleLength;
    windowOverOverlapRatio = windowSampleLength/nonOverlapSampleLength;
    if (round(windowOverOverlapRatio) ~= windowOverOverlapRatio)
        error('ERROR in fWindowing: non integer number of windows');
    end
    numOfWindows = floor((length(signal)-overlapSampleLength)/nonOverlapSampleLength); % To see how many one second window is there in the segment
    output = zeros(numOfWindows,windowSampleLength);
    for i = 1:numOfWindows
        output(i,:) = signal((i-1)*nonOverlapSampleLength+1 : windowSampleLength+ (i-1)*nonOverlapSampleLength);
    end
    
end
end






function [ output ] = fWindowing_triangular( signal, windowSampleLength, overlapSampleLength )
triangularWindow = triang(windowSampleLength)';
if overlapSampleLength == 0
    numOfWindows = floor(length(signal)/(windowSampleLength));
    if numOfWindows == 0
        error('ERROR in fWindowing: window length is longer than the signal length'); 
    end
    output = zeros(numOfWindows,windowSampleLength);   
    for i = 1:numOfWindows
        output(i,:) = triangularWindow.*signal((i-1)*windowSampleLength+1 : windowSampleLength*(i));
    end
else
    nonOverlapSampleLength =windowSampleLength - overlapSampleLength;
    windowOverOverlapRatio = windowSampleLength/nonOverlapSampleLength;
    if (round(windowOverOverlapRatio) ~= windowOverOverlapRatio)
        error('ERROR in fWindowing: non integer number of windows');
    end
    numOfWindows = floor((length(signal)-overlapSampleLength)/nonOverlapSampleLength); % To see how many one second window is there in the segment
    output = zeros(numOfWindows,windowSampleLength);
    for i = 1:numOfWindows
        output(i,:) = triangularWindow.*signal((i-1)*nonOverlapSampleLength+1 : windowSampleLength+ (i-1)*nonOverlapSampleLength);
    end
    
end
end




function [ output ] = fWindowing_hanning( signal, windowSampleLength, overlapSampleLength )
if ~isrow(signal)
    signal = signal.';
end
%hanningWindow = hann(windowSampleLength)';
hanningWindow = hanning(windowSampleLength)';
hanningWindow = sqrt(hanning(windowSampleLength)');
if overlapSampleLength == 0
    numOfWindows = floor(length(signal)/(windowSampleLength));
    if numOfWindows == 0
        error('ERROR in fWindowing: window length is longer than the signal length'); 
    end
    output = zeros(numOfWindows,windowSampleLength);   
    for i = 1:numOfWindows
        output(i,:) = hanningWindow.*signal((i-1)*windowSampleLength+1 : windowSampleLength*(i));
    end
else
    nonOverlapSampleLength = windowSampleLength - overlapSampleLength;
    %windowOverOverlapRatio = windowSampleLength/nonOverlapSampleLength;
%     if (round(windowOverOverlapRatio) ~= windowOverOverlapRatio)
%         error('ERROR in fWindowing: non integer number of windows');
%     end
    numOfWindows = floor((length(signal)-windowSampleLength)/nonOverlapSampleLength)+1; % To see how many one second window is there in the segment
    if length(signal) < windowSampleLength+ (numOfWindows-1)*nonOverlapSampleLength
        if iscolumn(signal)
            signal = vertcat(signal,zeros(windowSampleLength+ (numOfWindows-1)*nonOverlapSampleLength - length(signal),1));
        elseif isrow(signal)
            signal = horzcat(signal,zeros(1,windowSampleLength+ (numOfWindows-1)*nonOverlapSampleLength - length(signal)));
        end
    end
    output = zeros(numOfWindows,windowSampleLength);
    for i = 1:numOfWindows
        output(i,:) = hanningWindow.*signal((i-1)*nonOverlapSampleLength+1 : windowSampleLength+ (i-1)*nonOverlapSampleLength);
    end
    
end
end