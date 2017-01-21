function out = presist(varargin)
out = sum(1 ./ cell2mat(varargin)) ^ -1;
end
