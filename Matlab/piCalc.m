function [out n] = piCalc(accuracy)
n = accuracy;
out = 0;
    for i = 1:4:(accuracy*2)-1
        out = out + (4 / i);
    end
    for i = 3:4:(accuracy*2)-1
        out = out - (4 / i);
    end
end
    
    
  
        