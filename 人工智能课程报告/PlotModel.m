%×÷Í¼º¯Êý
function y = PlotModel(chrom)
x = chrom(1);
y = chrom(2);
z = chrom(3);
figure(2)
scatter3(x, y, z, 'k*')
hold on
[X, Y] = meshgrid(-10:0.1:10);
Z =10*sin(X)+16*cos(Y)+0.03*X.^2+0.02*Y.^3;
mesh(X, Y, Z)
y=1;