% calculates volume of a hollow sphere

innerrad = input('What is the inner radius? ');
outerrad = input('What is the outer radius? ');
volume = (4*pi/3)*(outerrad^3 - innerrad^3);
fprintf('The volume of this sphere is %.2f.\n', volume)

        