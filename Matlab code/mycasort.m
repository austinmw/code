function outv = mycasort(inarg, n)
 
for i = 1:length(inarg{n})-1
    low = i;
    
    for j=i+1:length(inarg{n})
        if inarg{n}(j) < inarg{n}(low)
            low = j;
        end
    end
   
    for k = 1:length(inarg)
      temp = inarg{k}(i);
      inarg{k}(i) = inarg{k}(low);
      inarg{k}(low) = temp;
    end
end
outv = inarg;

newca = mycasort(partsca,3);
>> celldisp(newca)
