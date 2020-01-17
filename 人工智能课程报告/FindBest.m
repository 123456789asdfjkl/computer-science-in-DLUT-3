%FindBest函数寻找出当前种群中的最优染色体，并将其保存在chrom_best。
function chrom_best = FindBest(chrom, fitness, N_chrom)
chrom_best = zeros(1, N_chrom+1);
[maxNum, maxCorr] = max(fitness);
chrom_best(1:N_chrom) =chrom(maxCorr, :);
chrom_best(end) = maxNum;