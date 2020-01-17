%CalAveFitness函数用于计算当前种群中的平均适应度。
function fitness_ave = CalAveFitness(fitness)
[N ,~] = size(fitness);
fitness_ave = sum(fitness)/N;