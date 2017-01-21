function plotmean(x,y)
hold
plot(x,y,'ko');
yavg = mean(y);
[c i] = min(abs(y-yavg));
closest = y(i);
plot(x(i), closest, '*r');
line([x(1) x(end)],[yavg yavg],'LineWidth',1);
title(closest)
end
