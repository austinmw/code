function rmat = resistorImage(varargin)
% Displays a colored band corresponding to tolerance input 

if nargin == 2
    resmat = varargin{1};
    tol = varargin{2};
else
    resmat = varargin{1};
    tol = varargin{2};
    res = varargin{3};
end
% Colormap includes: black, brown, red, orange, yellow, green, blue, violet, grey, white, gold, silver, body color.
cmap = [0 0 0; .8 .5 .4; 1 0 0; 1 .5 .25; 1 1 0; 0 1 0; 0 0 1; .8 0 1; .5 .5 .5; 1 1 1; .8 .8 .1; .8 .8 .8; .8 .7 .6; ...
    .914 .867 .686; .3725 .3529 .2824; .1415 .1415 .1415];
colormap(cmap)

if nargin == 3 && ~isempty(res)
    % Add resistance bands
    bandvec = bands(res);
    if length(bandvec) >= 3
        resmat(2:79,80:100) = bandvec(1);
        resmat(8:73,130:150) = bandvec(2);
        resmat(8:73,165:185) = bandvec(3);
        if length(bandvec) == 4
            resmat(8:73,200:220) = bandvec(4);
        else
            resmat(8:73,200:220) = 13;
        end
    end
elseif ~isnan(tol)
    % Add color of tolerance band
    if isequal(tol, '0.10')
        resmat(2:79,320:340) = 7;
    elseif isequal(tol, '0.25')
        resmat(2:79,320:340) = 6;
    elseif isequal(tol, '0.50')
        resmat(2:79,320:340) = 5;
    elseif isequal(tol, '1')
        resmat(2:79,320:340) = 1;
    elseif isequal(tol, '2')
        resmat(2:79,320:340) = 2;
    elseif isequal(tol, '5')
        resmat(2:79,320:340) = 10;
    elseif isequal(tol, '10')
        resmat(2:79,320:340) = 11;
    end
end

image(resmat)
axis image
axis off
rmat = resmat;
end