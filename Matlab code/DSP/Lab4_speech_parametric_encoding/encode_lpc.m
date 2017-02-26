function [synth_speech,voiced,aCoeff,e,gain] = encode_lpc(bits,x,fs)
%MAIN BODY
% clear all;
% clc;
warning('off');
%TAKING INPUT WAVEFILE,
% inpfilenm = 's1ofwb';
% [x, fs] =wavread(inpfilenm); 
% x=x./max(x);

% x=wavrecord(,);
% [x,fs]=audioread('speech.wav');

% k=resample(x,1,2);
% sound(k,4000);

% k1=resample(x,1,4);


%LENGTH (IN SEC) OF INPUT WAVEFILE,
% t=length(x)./fs;
% sprintf('Processing the wavefile "%s"', inpfilenm)
% sprintf('The wavefile is  %3.2f  seconds long', t)


%THE ALGORITHM STARTS HERE,
M=10;  %prediction order
% bits=6;
[aCoeff, pitch_plot, voiced, gain,e] = f_ENCODER(x, fs, M,bits);  %pitch_plot is pitch periods
synth_speech = f_DECODER (aCoeff, pitch_plot, voiced, gain);

% M=10;  %prediction order
% [aCoeff1, pitch_plot1, voiced1, gain1,e1] = f_ENCODER(x, fs, M);  %pitch_plot is pitch periods
% synth_speech1 = f_DECODER (aCoeff1, pitch_plot1, voiced1, gain1);


%RESULTS,
% beep;
% disp('Press a key to play the original sound!');
% pause;
% sound(x, fs);
% sound(synth_speech, fs);
% figure;
% plot(e);
% 
% figure;
% subplot(2,1,1), plot(x); title(['Original signal = "', inpfilenm, '"']); %title('original signal = "%s"', inpfilenm);
% subplot(2,1,2), plot(synth_speech); title(['synthesized speech of "', inpfilenm, '" using LPC algo']);

end

