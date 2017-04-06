function [r,k] = mfcc_vis(y)
% visualize mfcc

%% mfcc visualization
fs=44100;
 Tw = 25;                % analysis frame duration (ms)
    Ts = 10;                % analysis frame shift (ms)
    alpha = 0.97;           % preemphasis coefficient
    M = 14;  % number of filterbank channels 
    t=16;
    C = 12;                 % number of cepstral coefficients
    L = 22;                 % cepstral sine lifter parameter
    LF = 300;               % lower frequency limit (Hz)
    HF = 3700;              % upper frequency limit
    HF2=4000;
    
      [ MFCCs1, FBEs1, frames ] = ...
                    mfcc( y, fs, Tw, Ts, alpha, @hamming, [LF HF], M, C+1, L );
                
      [ MFCCs2, FBEs2, frames2 ] = ...
                    mfcc( y, fs, Tw, Ts, alpha, @hamming, [LF HF2], t, C+1, L );
                
      r=nanmean(FBEs1,2);  
      k=nanmean(FBEs2,2); 
%       figure;
%       bar(r(1:14));
end

