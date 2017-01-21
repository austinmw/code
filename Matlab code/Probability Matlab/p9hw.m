%a)
%mu = [0, 0];
%sigma = [4, 0 ; 0, 1];
%x = mvnrnd(mu, sigma, 1000);
%plot(x(:,1),x(:,2),'o');
%axis([-6 6 -6 6]), axis square
%title('9.2 a.iii');


%b)
%sigma = [1, 0 ; 0, 1]
%mu0 = [4, 2]
%mu1 = [-2, 2]
%x_H0 = mvnrnd(mu0, sigma, 1000);
%x_H1 = mvnrnd(mu1, sigma, 1000);
%hold off
%plot(x_H0(:,1),x_H0(:,2),'o');
%hold on
%plot(x_H1(:,1),x_H1(:,2),'rx');
%axis([-6 6 -6 6]), axis square
%title('9.2 b.ii');

%c)


a = 1/length(H0labeled) * sum(H0labeled(:,1))
c = 1/length(H1labeled) * sum(H1labeled(:,1))
b = 1/length(H0labeled) * sum(H0labeled(:,2))
d = 1/length(H1labeled) * sum(H1labeled(:,2))
var1 = 1/length(H0labeled) * sum((H0labeled(:,1) - a).^2)
var2 = 1/length(H0labeled) * sum((H0labeled(:,2) - b).^2)

x_co = ((a-c)/var1)
y_co = ((b-d)/var2)

addterms = ((c.^2 - a.^2)/(2*var1)) + ((d.^2 - b.^2)/(2*var2))

m = -x_co/y_co
b = addterms/y_co


plot(unlabeled(:,1),unlabeled(:,2),'o');
axis([-6 8 -6 6]);
title('part c');
hold on

x1 = [-6:0.01:6];
y1 = 4.8796*x1 - 7.2938;
plot(x1,y1);



