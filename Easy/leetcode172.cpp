/* 给定一个整数 n，返回 n! 结果尾数中零的数量。 */
//方法一：暴力
//思路：原来这里的尾数是最后有几个连续的0.。。
//使用暴力解法会溢出。总之思路就是求出阶乘，然后使用模运算
class Solution {
public:
    long long jc(long long a){
        if(a == 1)  return 1;
        return a * jc(a-1);
    }

    int trailingZeroes(int n) {
        if(n == 0)  return 0;
        long long ret = jc(n);
        int num = 0;
        while(ret % 10 == 0){
            ++num;
            ret /= 10;
        }
        return num;
    }
};

//方法二：我也不知道应该叫什么方法
//思路：阶乘结果中尾部的0都是由2×5形成的，所以只要我们计算阶乘中所有数的因数中有几个2、5对即可
//因为2的数量肯定比5多，所以我们只需要计算5的个数即可，而因数中有5的肯定都是以0和5结尾的数
//所以在遍历过程中我们每次增加5，然后计算这个数的因数中有几个5，最后所有5的个数相加就是答案了
class Solution {
public:
    int trailingZeroes(int n) {
        if(n < 5)   return 0;
        int num5 = 0;
        for(int i = 5; i <= n; i+=5){
            int c = i;
            while(c % 5 == 0){
                ++num5;
                c /= 5;
            }
        }
        return num5;
    }
};

//思路和上面一样，不过代码较简洁，详细的看官方解答
class Solution {
public:
    int trailingZeroes(int n) {
        return (n == 0) ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};
