figure
hold on
blueled = load('blu_led.txt');
greenled = load('green_led.txt');
orangeled = load('orange_led.txt');
redorangeled = load('redorange_led.txt');
redled = load('red_led.txt');
irled = load('ir_led.txt');

plot(blueled(:,1),blueled(:,2)./max(blueled(:,2)),'b','DisplayName','blue');
orange = [0.92941     0.69412     0.12549];
plot(orangeled(:,1),orangeled(:,2)./max(orangeled(:,2)),'Color',orange,'DisplayName','orange');
plot(greenled(:,1),greenled(:,2)./max(greenled(:,2)),'g','DisplayName','green');
orangered = [0.85098     0.32549    0.098039];
plot(redorangeled(:,1),redorangeled(:,2)./max(redorangeled(:,2)),'Color',orangered,'DisplayName','red-orange');
plot(redled(:,1),redled(:,2)./max(redled(:,2)),'r','DisplayName','red');
IR = [0.8         0.8         0.8];
plot(irled(:,1),irled(:,2)./max(irled(:,2)),'Color',IR,'DisplayName','infrared');

xlabel('Wavelength in nm');
ylabel('Intensity');
title('Peak wavelengths for LEDs');
h = legend('show');
c = h.TextColor;
h.TextColor = 'black';



