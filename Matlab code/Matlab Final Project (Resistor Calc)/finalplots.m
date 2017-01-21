function finalplots(r)
l = length(r);
i = linspace(0,100,200);
v1 = r(1)*i;

firstplot = plot(i,v1,'r');
xlabel('Current (I)');
ylabel('Voltage (V)');
r1val = sprintf('Resistance value of %s', num2str(r(1)));
title(r1val);

end


