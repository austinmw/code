function [] = yes_no_recognize(y)
%test yes/no

fs=44100;
s_test=bandpower(y,fs,[0 2000])./bandpower(y,fs,[2000 22050]);
if s_test>8
    disp('no');
else
    disp('yes');
end
end

