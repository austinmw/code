function panelhand = panel(r)
f = figure('Visible', 'off', 'Units', 'Normalized', 'Position', [.3 .3 .8 .27*r]);
panelh = uipanel(f, 'Position', [0 0 1 1]);
movegui(panelh, 'north')
set(f, 'Visible', 'on')
panelhand = panelh;
end