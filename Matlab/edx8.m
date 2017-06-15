disp('This script will calculate the volume of a pyramid.');
length = input('Enter the length of the base: ');
lengthunits = input('Is that i or c? ', 's');
if lengthunits == 'c'
    length = length / 2.54;
end
width = input('Enter the width of the base: ');
widthunits = input('Is that i or c? ', 's');
if widthunits == 'c'
    width = width / 2.54;
end
height = input('Enter the height of the base: ');
heightunits = input('Is that i or c? ', 's');
if heightunits == 'c'
    height = height / 2.54;
end
volume = length * width * height;
fprintf('The volume of the pyramid is %.3f cubic inches.\n', volume);

