/*
 * 给定一个整数，写一个函数来判断它是否是 3 的幂次方。如果是，返回 true ；否则，返回 false 。
 * 整数 n 是 3 的幂次方需满足：存在整数 x 使得 n == 3x
 */
//方法一：普通的暴力解法
//思路：首先小于等于0的数肯定不是3的幂次
//对于其他正整数，如果模3等于0，说明可以被3整除，之后让它除以3，一直循环下去，如果最后得到1，则说明是3的幂次
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)  return false;
        while(n % 3 == 0){
            n /= 3;
        }
        return n == 1;
    }
};
