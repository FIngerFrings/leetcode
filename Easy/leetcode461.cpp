/*
 * 两个整数之间的 汉明距离 指的是这两个数字对应二进制位不同的位置的数目。
 * 给你两个整数 x 和 y，计算并返回它们之间的汉明距离。
 */
//方法一：Brian Kernighan 算法
//思路：按位异或后计算有多少个1即可，这里可以对异或结果不断去掉最后1位1，得到有多少位1
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int count = 0;
        while(n){
            count++;
            n &= (n-1);
        }
        return count;
    }
};
//除了上面的方法计算1的个数，还可以循环移位计算1的个数
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int count = 0;
        while(n){
            count += (n & 1);
            n >>= 1;
        }
        return count;
    }
};
