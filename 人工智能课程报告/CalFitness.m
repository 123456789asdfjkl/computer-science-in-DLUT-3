%CalFitness函数则是计算chrom内每个个体的适应度，并将其保存在fitness中。
function fitness = CalFitness(chrom, N, N_chrom)
fitness = zeros(N, 1);
%开始计算适应度
for i = 1:N
    x = chrom(i, 1);
    y = chrom(i, 2);
    fitness(i) = 10*sin(x)+16*cos(y)+0.03*x.^2+0.02*y.^3;
end