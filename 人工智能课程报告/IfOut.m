% 越界函数IfOut函数我们看它是左越界还是右越界，
% 如果是左越界，则让节点值等于区间下限；
% 如果是右越界，则让节点值等于区间上限。
function c_new = IfOut(c, range)
if c<range(1) || c>range(2)
    if abs(c-range(1))<abs(c-range(2))
        c_new = range(1);
    else
        c_new = range(2);
    end
else
    c_new = c;
end