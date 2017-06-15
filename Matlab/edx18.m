axis([0 1 0 1]);
fv = struct('vertices', [rand rand; rand rand; rand rand], 'faces', ...
    [1 2 3]);
patch(fv, 'FaceColor', [.5 .5 .5], 'LineWidth', 3, 'Edgecolor', 'k');
