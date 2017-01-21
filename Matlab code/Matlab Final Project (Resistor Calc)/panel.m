function [figurehand, panelhands] = panel(r)
% Creates a figure with dimensions based on menu input 
% Creates 1, 2, or 3 panels
% Returns the figure handle and the panel handles
f = figure('Visible', 'off', 'Units', 'Normalized', 'Position', [.3 .3 .8 .27*r]);
phands = zeros(1,r);
if r == 1
    phands(1) = uipanel(f, 'Position', [0 0 1 1]);
elseif r == 2
    phands(1) = uipanel(f, 'Position', [0 .5 1 .5]);
    phands(2) = uipanel(f, 'Position', [0 0 1 .5]);
else 
    phands(1) = uipanel(f, 'Position', [0 .66 1 .33]);
    phands(2) = uipanel(f, 'Position', [0 .33 1 .33]);
    phands(3) = uipanel(f, 'Position', [0 0 1 .33]);
    
end
movegui(f, 'north')     % Put the figure at top center
figurehand = f;
panelhands = phands;
end