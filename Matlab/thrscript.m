% calculates low end of target heart rate

age = input('Please enter your age in years: ');
THR = (220 - age) * 0.6;
fprintf('For a person %d years old, the target heart rate is %d.\n', age, THR)
