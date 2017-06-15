function out = rectareavol(varargin);
out = varargin{1} * varargin{2};
if length(varargin) > 2
      out = out * varargin{3};
end
end
