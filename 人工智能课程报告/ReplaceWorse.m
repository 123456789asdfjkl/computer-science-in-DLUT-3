% ReplaceWorse函数则是优胜劣汰这个过程，将种群中的最劣染色体替换掉。
% 这里是直接用最优染色体替换，并且替换掉的是最后几个染色体，目的是加快收敛速度，但可能会陷入局部最优解。
function [chrom_new, fitness_new] = ReplaceWorse(chrom, chrom_best, fitness)

max_num = max(fitness);
min_num = min(fitness);
limit = (max_num-min_num)*0.2+min_num;

replace_corr = fitness<limit;

replace_num = sum(replace_corr);
chrom(replace_corr, :) = ones(replace_num, 1)*chrom_best(1:end-1);
fitness(replace_corr) = ones(replace_num, 1)*chrom_best(end);
chrom_new = chrom;
fitness_new = fitness;

end