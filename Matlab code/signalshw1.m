t=-10:10;

stepFCT=zeros(1,length(t));

%%%%%%u[n-1]%%%%%%

for i=1:length(t);
    if t(i) +2*t(i-3) -3*t(i-6)  >=0
        stepFCT(i)=1;
    else
    end
end

figure(1)
stem(t,stepFCT)