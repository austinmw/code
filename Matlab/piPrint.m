function piPrint(approx, num)
decApprox = sprintf('%0.7f\n', 10 ^ -num);
decApprox = decApprox(1:num+2);
fprintf('\nSpecified accuracy: %s\n\n', decApprox);
fprintf('Approximation is %1.15f compared to actual value %1.15f\n', ...
    approx, pi);
end
