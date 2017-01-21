% Grader code

fid = fopen(var);
aline = {};
counter = 1;
while ~feof(fid)
    aline{counter} = fgetl(fid);
    if ~isempty(aline{counter}) && aline{counter}(1) == '%'
        aline{counter} = '';
    end
    counter = counter + 1;
end
aline(strcmp('',aline)) = [];
eval(aline{1});
assert(isvector(vec),'Input is not a vector.');
randcheck = strfind(aline{1},'rand');
assert(~isempty(randcheck),'Input is not a vector of random values.');
subtractioncheck = strfind(aline{2:end}, '-');
assert(~isempty(subtractioncheck), 'Error. Use - operator your solution');
diffcheck = strfind(aline{2:end}, 'diff(');
assert(isempty(diffcheck), 'Do not use diff() function.');
eval(aline{2:end})
assert(isequal(mydiff, diff(vec)),'Solution is not correct.');
disp('Pass!');






