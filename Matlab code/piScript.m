%script for calling functions for pi approximator
accuracy = piAccuracy;
[piApprox n] = piCalc(accuracy);
piPrint(piApprox, n);
