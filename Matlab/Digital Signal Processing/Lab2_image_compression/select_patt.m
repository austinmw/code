function [] = select_patt(i,type)
%select pattern to display
if type==1
if i==1
    dop(1);
elseif i==2
    deap1(1);
elseif i==3
    deap2(1);
elseif i==4
    deap3(1);
elseif i==5
    deap5(1);
elseif i==6
    deap4(1);
end
elseif type==2
if i==1
    figure;
    dop(1);
    set(gcf, 'Visible', 'off');
elseif i==2
    figure;
    deap1(1);
    set(gcf, 'Visible', 'off');
elseif i==3
    figure;
    deap2(1);
    set(gcf, 'Visible', 'off');
elseif i==4
    figure;
    deap3(1);
    set(gcf, 'Visible', 'off');
elseif i==5
    figure;
    deap5(1);
    set(gcf, 'Visible', 'off');
elseif i==6
    figure;
    deap4(1);
    set(gcf, 'Visible', 'off');
end
end

