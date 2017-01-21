colormap(jet);
panda = imread('panda.jpeg');
grizzly = imread('grizzly.jpeg');
panda = imresize(panda, [168 300]);
%image(panda);
%figure
%image(grizzly);
newpic = panda;
newpic(:,:,1) = ((panda(:,:,1) .* grizzly(:,:,1)) ./ 2);
newpic(:,:,2) = ((panda(:,:,2) .* grizzly(:,:,2)) ./ 2);
newpic(:,:,3) = ((panda(:,:,3) .* grizzly(:,:,3)) ./ 2);
%image(newpic);






