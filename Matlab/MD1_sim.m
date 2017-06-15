% Simulation of M/D/1 queue;
% Performance Measure: Mean number of packets in the system
% David Starobinski, 03/31/2016

close all;
clear all;

% queue parameters
lambda=0.1:0.1:0.9; % values of lambda for which the simulations are run
mean_serv_time = 1; % mean service time of packet
mu=1/mean_serv_time; % mean service rate
second_moment_serv = mean_serv_time^2; %second moment of service
rho=lambda/mu; %load


% analytical formulas to validate simulation;
w = lambda*second_moment_serv./(2*(1-rho)); % Mean waiting time PK-formula
mean_q_ana = lambda.*w + rho; % Mean number of packets in the system


% simulation setting
N=10^4; % Total number of packets
iteration_num=30; %number of independent iterations
alpha=0.05; % Confidence interval is 100(1-alpha) percent
frac=0.1; 
N_start = round(frac*N); %ignores simulation results for the first N_start packets
mean_q=[]; % stores the simulation mean queue length for each value of lambda and iteration

% main loop

for j=1:length(lambda) % iterate over values of lambda

    for k=1:iteration_num; % for each value of lambda run iteration_num iterations
    
    
        q=0; %size of queue at the beginning
        total_q=0; % total number of packets in the queue seen throughout the simulation
        serv_time = mean_serv_time; % for M/D/1 queue
        arrivals = poissrnd(lambda(j)*serv_time,1,N); % # arrivals during the service of each packet
 
        for i=1:N_start %transient period no collection statistics until N_start 
            q=max(q-1,0)+arrivals(i); % update queue length after each departure
        end

        for i=N_start+1:N % now starts collecting statistics
            q=max(q-1,0)+arrivals(i);
            total_q=total_q+q;
        end

        mean_q(k,j) = total_q/(N-N_start); %mean number of packets in the system
    
    end;
    
end;

% compute statistics

sample_mean=mean(mean_q); %mean of number of packets in the system averaged over all the iterations
err=std(mean_q)*norminv(1-alpha/2)/(iteration_num)^0.5; %confidence interval 


% output statistic

    % Compare analytical versus simulation results

    plot(rho,mean_q_ana,'b-'); %analytical
    xlabel('Load (rho)');
    ylabel('Mean number of packets');
    hold;
    errorbar(rho,mean(mean_q),err,'r*') %simulation with confidence intervals
    legend('analysis','simulation');

    % normalized error (error divided by mean)

    err./sample_mean