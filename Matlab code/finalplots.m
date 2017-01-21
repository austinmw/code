
function finalplots(r)
format long
l = length(r)
i = linspace(0,100,200);
v1 = r(1)*i;
figure(1)
firstplot = plot(i,v1,'k');
xlabel('Current (I)');
ylabel('Voltage (V)');
r1val = sprintf('Resistance value of %s', num2str(r(1)));
title(r1val);
if l == 2
    figure(2)
    r2val = sprintf('Resistance value of %s', num2str(r(2)));
    title(r2val);
    v2 = r(2)*i;
    secondplot = plot(i,v2,'b');
    xlabel('Current (I)');
    ylabel('Voltage (V)');
end 
if l == 3
    figure(2)
    r2val = sprintf('Resistance value of %s', num2str(r(2)));
    title(r2val);
    v2 = r(2)*i;
    secondplot = plot(i,v2,'b');
    xlabel('Current (I)');
    ylabel('Voltage (V)');
    r2val = sprintf('Resistance value of %s', num2str(r(2)));
    title(r2val);
    figure(3)
    v3 = r(3)*i;
    thirdplot = plot(i,v3,'r');
    xlabel('Current (I)');
    ylabel('Voltage (V)');
    r3val = sprintf('Resistance value of %s', num2str(r(3)));
    title(r3val);
end
end


