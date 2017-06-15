function [varargout] = bitstobytesnibs(in)
n = nargout;
for i = 3:n
varargout{n} = '';
end
varargout{1} = in * 8;
varargout{2} = in * 2;
end
