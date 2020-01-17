% AcrChrom函数是染色体交叉函数。逻辑相较染色体变异来说比较简单，大致可以分为以下几点
% 1.判断该节点是否交叉；
% 2.随机寻找一个与其交叉的节点；
% 3.对两个节点进行交叉。
function chrom_new = AcrChrom(chrom, acr, N, N_chrom)
for i = 1:N
    acr_rand = rand;
    if acr_rand<acr %如果交叉
        acr_chrom = floor((N-1)*rand+1); %要交叉的染色体
        acr_node = floor((N_chrom-1)*rand+1); %要交叉的节点
        %交叉开始
        temp = chrom(i, acr_node);
        chrom(i, acr_node) = chrom(acr_chrom, acr_node); 
        chrom(acr_chrom, acr_node) = temp;
    end
end
chrom_new = chrom;