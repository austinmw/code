


clear; clc;

% say, 
%h = 2
%v = 5
%b = 3


syms x y z b h v
eqn1 = -x - y*h*v - z*v + h == 0;
eqn2 = -x*h*v - y - z*h + v == 0;
eqn3 = -x*v - y*h - z + h*v == 0;
eqn4 = -x*h - y*v - z*h*v + 1 == b^2;

[A,B] = equationsToMatrix([eqn1, eqn2, eqn3, eqn4], [x, y, z])

