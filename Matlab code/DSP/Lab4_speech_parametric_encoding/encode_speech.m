function [x_q] = encode_speech(bitrate)


x=audioread('speech.wav');

if bitrate ==32000
bits=3;
    H1 = dsp.UniformEncoder;  H1.PeakValue = max(x);
    H1.NumBits = bits;
    H1.OutputDataType = 'Unsigned integer';
    enc_x= step(H1,x);

    H1_dec = dsp.UniformDecoder;H1_dec.PeakValue =max(x);
    H1_dec.NumBits =bits;x_q = step(H1_dec,enc_x);  
else if bitrate ==16000
bits=2;
    H1 = dsp.UniformEncoder;  H1.PeakValue = max(x);
    H1.NumBits = bits;
    H1.OutputDataType = 'Unsigned integer';
    enc_x= step(H1,x);

    H1_dec = dsp.UniformDecoder;H1_dec.PeakValue =max(x);
    H1_dec.NumBits =bits;x_q = step(H1_dec,enc_x);   
else
    k1=resample(x,1,8000./(bitrate/2));
    bits=2;
    H1 = dsp.UniformEncoder;  H1.PeakValue = max(k1);
    H1.NumBits = bits;
    H1.OutputDataType = 'Unsigned integer';
    enc_x= step(H1,k1);
    H1_dec = dsp.UniformDecoder;H1_dec.PeakValue =max(x);
    H1_dec.NumBits =bits;x_q = step(H1_dec,enc_x);
    end
end