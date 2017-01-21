format short
colors = {'black','brown','red','orange','yellow','green','blue',...
    'violet','gray','white','gold','silver'};
multipliers = [10E0,10E1,10E2,10E3,10E4,10E-1,10E-2];
numbers = [0:9, 0.1, 0.01];

resistorcolors = {};
resistorcolors{1} = colors{find(numbers == band(1))};
resistorcolors{2} = colors{find(numbers == band(2))};
if band(4) == 555
    resistorcolors{3} = colors{find(multipliers == band(3))};
    resistorcolors{3} = 'empty';
else
    resistorcolors{3} = colors{find(numbers == band(3))};
    resistorcolors{4} = colors{find(multipliers == band(4))};
end

disp(resistorcolors);