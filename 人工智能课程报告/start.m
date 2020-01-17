%求10*sin(x)+16*cos(y)+0.02*x.^2+0.03*y.^3在x[-10,10]且y[-10,10]的最大值;
clc, clear, close all

%%基础参数
N = 100;  %种群内个体数目
N_chrom = 2; %染色体节点数
iter = 2000; %迭代次数
mut = 0.2;  %突变概率
acr = 0.2; %交叉概率
best = 1;

chrom_range = [-10 -10;10 10];%每个节点的值的区间
chrom = zeros(N, N_chrom);%存放染色体的矩阵
fitness = zeros(N, 1);%存放染色体的适应度
fitness_ave = zeros(1, iter);%存放每一代的平均适应度
fitness_best = zeros(1, iter);%存放每一代的最优适应度
chrom_best = zeros(1, N_chrom+1);%存放当前代的最优染色体与适应度

%%初始化
chrom = Initialize(N, N_chrom, chrom_range); %初始化染色体
fitness = CalFitness(chrom, N, N_chrom); %计算适应度
chrom_best = FindBest(chrom, fitness, N_chrom); %寻找最优染色体
fitness_best(1) = chrom_best(end); %将当前最优存入矩阵当中
fitness_ave(1) = CalAveFitness(fitness); %将当前平均适应度存入矩阵当中

for t = 2:iter
    chrom = MutChrom(chrom, mut, N, N_chrom, chrom_range, t, iter); %变异
    chrom = AcrChrom(chrom, acr, N, N_chrom); %交叉
    fitness = CalFitness(chrom, N, N_chrom); %计算适应度
    chrom_best_temp = FindBest(chrom, fitness, N_chrom); %寻找最优染色体
    if chrom_best_temp(end)>chrom_best(end) %替换掉当前储存的最优
        chrom_best = chrom_best_temp;
    end
    %%替换掉最劣
    [chrom, fitness] = ReplaceWorse(chrom, chrom_best, fitness);
    fitness_best(t) = chrom_best(end); %将当前最优存入矩阵当中
    fitness_ave(t) = CalAveFitness(fitness); %将当前平均适应度存入矩阵当中
end

%%作图
figure(1)
plot(1:iter, fitness_ave, 'r', 1:iter, fitness_best, 'b')
grid on
legend('平均适应度', '最优适应度','Location','east')
e = PlotModel(chrom_best);

%%输出结果
disp(['最大值坐标为', num2str(chrom_best(1:end-1))])
disp(['最大值为为', num2str(chrom_best(end))])