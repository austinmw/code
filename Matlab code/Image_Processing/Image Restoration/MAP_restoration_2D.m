function NewImg = MAP_restoration_2D(NoisyImg,nPasses,Lambda)
% 2-D MAP restoration 
    
    p = (0:255)/255; % possible values of u_hat(j,i)
    % Main loop
    I = NoisyImg; % copy noisy image
    for passes=1:nPasses % number of passes to repeat process
        fprintf('Pass #%d\n', passes); % iteration count to track progress
        vec = zeros(256,1); % init minimization vector for repeated use
        NewImg = I; % calculated estimate, updated at every pass
        for i=2:size(NoisyImg,1)-1 % loop through rows
            for j=2:size(NoisyImg,2)-1 % loop through columns
                for val=1:256 % loop through u_hats: 0,1/255,...,254/255,1
                    u_hat = p(val); % set u_hat
                    % calculate energy for u_hat(val) at position (i,j)
                    vec(val) = (I(i,j) - u_hat)^2 + ...
                        Lambda*(abs(I(i-1,j) - u_hat) + ...
                        abs(I(i,j+1) - u_hat) + abs(I(i+1,j) - u_hat) + ...
                        abs(I(i,j-1) - u_hat));
                end 
                [~,m] = min(vec); % determine position of minimum
                NewImg(i,j) = m/255; % set value to argmin/255
            end
        end
        I = NewImg; % set working image to new image for next pass
    end
    
end