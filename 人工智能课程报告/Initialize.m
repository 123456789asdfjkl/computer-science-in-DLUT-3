%Initialize函数是我自定义的一个函数，用于初始化染色体。
%具体操作就是用一个for循环对每个个体的染色体进行随机赋值，
%并利用chrom_range将其限定在变量规定的区间之内。
function chrom_new = Initialize(N, N_chrom, chrom_range)
chrom_new = rand(N, N_chrom);
for i = 1:N_chrom %每一列乘上范围
    chrom_new(:, i) = chrom_new(:, i)*(chrom_range(2, i)-chrom_range(1, i))+chrom_range(1, i);
end