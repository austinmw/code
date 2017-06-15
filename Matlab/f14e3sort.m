function out = f14e3sort(vec)

for i = 1:length(vec)-1


       indlow = i 
 

       for j=i+1:length(vec)

           if vec(j) < vec(indlow) 

              indlow = j
           end
       end
    
       temp = vec(i);
       vec(i) = vec(indlow);
       vec(indlow) = temp

 end



   out = vec;

end
