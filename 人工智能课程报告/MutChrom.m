% MutChrom函数用来对种群进行染色体变异操作。这里面的操作比较多，主要可以分为三步：
% 1.判断某节点是否变异；
% 2.判断变异是增加还是减少；
% 3.判断变异后的值是否越界。
function chrom_new = MutChrom(chrom, mut, N, N_chrom, chrom_range, t, iter)
for i = 1:N
    for j = 1:N_chrom
        mut_rand = rand; %是否变异
        if mut_rand <=mut
            mut_pm = rand; %增加还是减少
            mut_num = rand*(1-t/iter)^2;
            if mut_pm<=0.5
                chrom(i, j)= chrom(i, j)*(1-mut_num);
            else
                chrom(i, j)= chrom(i, j)*(1+mut_num);
            end
            chrom(i, j) = IfOut(chrom(i, j), chrom_range(:, j)); %检验是否越界
        end
    end
end
chrom_new = chrom;