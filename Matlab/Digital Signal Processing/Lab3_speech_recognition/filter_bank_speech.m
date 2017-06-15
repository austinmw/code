function [X] = filter_bank_speech(y)
% filter outputs

N=10;           % number of filters = DFT length
fs=44100;        % sampling frequency (arbitrary)
% D=1;            % duration in seconds

L=length(y);
% L = ceil(fs*D)+1; % signal duration (samples)
n = 0:L-1;        % discrete-time axis (samples)
t = n/fs;         % discrete-time axis (sec)
% x = chirp(t,0,D,fs/2);   % sine sweep from 0 Hz to fs/2 Hz
%x = echirp(t,0,D,fs/2); % for complex "analytic" chirp
% x = x(1:L);       % trim trailing zeros at end
h = ones(1,N);    % Simple DFT lowpass = rectangular window
%h = hamming(N);  % Better DFT lowpass = Hamming window
X = zeros(N,L);   % X will be the filter bank output
for k=1:N         % Loop over channels
  wk = 2*pi*(k-1)/N;
  xk = exp(-1i*wk*n)* y;  % Modulation by complex exponential
  X(k,:) = filter(h,1,xk);
end

end

