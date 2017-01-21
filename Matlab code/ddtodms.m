function [d,m,s] = ddtodms(dd)
d = floor(dd);
m = int32((dd - d) * 60);
s = (dd - d - m/60) * 3600;
if s ~= uint32(s)
    s = 0
end
end
