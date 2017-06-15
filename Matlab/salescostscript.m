% costs and sales per quarter plot and reorder/save
load costsales.dat
mat = costsales
[r,c] = size(mat);
fprintf('There were %d quarters in the file.\n', r)
quarter = [1:r];
cost = mat(:,1);
sales = mat(:,2);
figure
plot(quarter,cost,'ko',quarter,sales,'k*')
legend('costs','sales');
title('Company Costs and Sales');
xlabel('Quarter');
newmat = [cost;sales];
save newfile.dat newmat -ascii
