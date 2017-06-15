% This takes argument of panelh
% Sets up the gui tolerance/resistance select and resistor image
% 1-3 instances depending on number of resistors from user menu
% Returns a matrix, first col is the tolerance handles, second col is the image handles

function makeguitolerance(panelh);
resistorImage(bhands)

if r == 2   % For 2 resistors
    % Set tolerance button group 1 position
    set(tolimagemat(1,1), 'Position', [0 .5 .3 .5])
    % Set resistor image 1 position
    set(tolimagemat(1,2), 'Units', 'Normalized', 'Position', [.305 .52 .3 .46])
    
    % Set second row to second tolerance/image handle pair
    tolimagemat(2,:) = makeguitolerance(panelh);
    resistorblank;  % Make an image
    axis off
    % Set tolerance button group 2 position
    set(tolimagemat(2,1), 'Position', [0 0 .3 .5], 'Title', 'Resistor 2')
    % Set resistor image 2 position
    set(tolimagemat(2,2), 'Units', 'Normalized', 'Position', [.305 .02 .3 .46])
elseif r == 3   % For 3 resistors
    % Set tolerance button group 1 position
    set(tolimagemat(1,1), 'Position', [0 .66 .3 .33])
    % Set resistor image 1 position
    set(tolimagemat(1,2), 'Units', 'Normalized', 'Position', [.305 .68 .3 .31])
    % Set second row to second tolerance/image handle pair
    tolimagemat(2,:) = makeguitolerance(panelh);
    resistorblank;  % Make an image
    axis off
    % Set tolerance button group 2 position
    set(tolimagemat(2,1), 'Position', [0 .33 .3 .33], 'Title', 'Resistor 2')
    % Set resistor image 2 position
    set(tolimagemat(2,2), 'Units', 'Normalized', 'Position', [.305 .35 .3 .31], 'Title', 'Resistor 2')
    % Set third row to third tolerance/image handle pair
    tolimagemat(3,:) = makeguitolerance(panelh);
    resistorblank;  % Make an image
    axis off
    % Set tolerance button group 3 position
    set(tolimagemat(3,1), 'Position', [0 0 .3 .33], 'Title', 'Resistor 3')
    % Set resistor image 3 position
    set(tolimagemat(3,2), 'Units', 'Normalized', 'Position', [.305 .02 .3 .31]);
end


 
