function guitolerance(f, panelh, resstruct)
% guitolerance select has 7 radio buttons to select desired tolerance
% Resistance entered by user generates colored bands on resistor image
% Creates image and resistance plot for each resistor

persistent rvec
persistent resmat

% Create button group and axes for image and plot
imaxh = axes('Units', 'Normalized', 'Position', [.330 .02 .3 .96]);
set(imaxh, 'Parent', panelh)
if isempty(resmat)
    resmat = resistorblank;
end
image(resmat)
axis off
axis image

%numr = sprintf('Resistor %d\n', l);
tolerances = uibuttongroup(panelh, 'Units', 'Normalized', 'Position', [0 0 .3 1], 'Title', 'Resistor Value', 'SelectedObject', [], 'SelectionChangeFcn', @gettol);
plotaxh = axes('Units', 'Normalized', 'Position', [.68 .2 .27 .65]);
set(plotaxh, 'Parent', panelh)

% Create static titles and edit box to enter desired resistance
toltitle = uicontrol(tolerances, 'Style', 'text', 'Units', 'Normalized', 'Position', [.08 .85 .3 .1], 'String', 'Select tolerance:');
restitle = uicontrol(tolerances, 'Style', 'text', 'Units', 'Normalized', 'Position', [.5 .62 .3 .2], 'String', 'Desired Resistance:');
desiredr = uicontrol(tolerances, 'Style', 'edit', 'Units', 'Normalized', 'Position', [.54 .58 .2 .13], 'Callback', @getres);

% Add 7 radio buttons to group
opt01 = uicontrol(tolerances, 'Style', 'radiobutton', 'String', '0.10', 'Units', 'Normalized', 'Position', [.05 .75 .2 .1]);
opt025 = uicontrol(tolerances, 'Style', 'radiobutton', 'String', '0.25', 'Units', 'Normalized', 'Position', [.05 .6 .2 .1]);
opt05 = uicontrol(tolerances, 'Style', 'radiobutton', 'String', '0.50', 'Units', 'Normalized', 'Position',[.05 .45 .2 .1]);
opt1 = uicontrol(tolerances, 'Style', 'radiobutton', 'String', '1', 'Units', 'Normalized', 'Position', [.05 .3 .2 .1]);
opt2 = uicontrol(tolerances, 'Style', 'radiobutton', 'String', '2', 'Units', 'Normalized', 'Position', [.25 .67 .2 .1]);
opt5 = uicontrol(tolerances, 'Style', 'radiobutton', 'String', '5', 'Units', 'Normalized', 'Position', [.25 .52 .2 .16]);
opt10 = uicontrol(tolerances, 'Style', 'radiobutton', 'String', '10', 'Units', 'Normalized', 'Position', [.25 .37 .2 .16]);

set(f, 'Visible', 'on')

    function gettol(tolerances,~)
        % Renders the resistance bands and tolerance band
        tolh = get(tolerances, 'SelectedObject');
        tol = get(tolh, 'String');
        axes(imaxh)
        resmat = resistorImage(resmat, tol);
    end

    function getres(desiredr,~)
        % Renders the resistance bands and tolerance band
        res = get(desiredr, 'String');
        tolh = get(tolerances, 'SelectedObject');
        tol = get(tolh, 'String');
        [r, tol, minval] = searchstruct(resstruct, tol, res);
        axes(imaxh)
        resmat = resistorImage(resmat, tol, r);
        actualr = [sprintf('Closest Resistance: %.2f', r) '\Omega'];
        text(90, -15, actualr, 'Fontsize', 12);
        error = (minval/str2double(res))*100;
        perr = sprintf('Percent Error: %.1f%%\n', error);
        text(140, 100, perr, 'Fontsize', 10);
        
        persistent count
        if isempty(count) == 1
            count = 1;
        else
            count = count + 1;
        end
        rvec = [rvec r];
        axes(plotaxh);
        
        finalplots(rvec(count));
    end
end