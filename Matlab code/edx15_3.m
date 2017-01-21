matstruct = struct('mag5by5',magic(5),'randi3by3',randi([1 100],3,3), ...
    'rand2by2',rand(2,2));

save('testmats.mat','matstruct');
