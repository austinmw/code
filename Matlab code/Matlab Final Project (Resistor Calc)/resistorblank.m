function resmat = resistorblank
% Reads jpeg to a matrix
resbody = imread('resbody.jpg');

% Colormap includes: black, brown, red, orange, yellow, green, blue, violet, grey, white, gold, silver, light brown.
cmap = [0 0 0; .8 .5 .4; 1 0 0; 1 .5 .25; 1 1 0; 0 1 0; 0 0 1; .8 0 1; .5 .5 .5; 1 1 1; .8 .8 .1; .8 .8 .8; .8 .7 .6; ...
    .914 .867 .686; .3725 .3529 .2824; .1415 .1415 .1415];
colormap(cmap)

% Convert from RGB to colormap index
resmat = rgb2ind(resbody, cmap);
end