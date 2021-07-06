/*
 * 给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。
 *如果存在一个整数 x 使得  n == 2x ，则认为 n 是 2 的幂次方。
 */
//方法一：模运算和除运算
//思路：略
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)  return false;
        while(n % 2 == 0){
            n /= 2;
        }
        return n == 1;
    }
};

//方法二：位运算
//思路：如果一个数是2的幂，则它的二进制表示必定只有1个1，因此可以用n & (n - 1)得到结果
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n & (n - 1));
    }
};

//方法三：位运算
//思路：如果1个数是2的幂，则它的二进制表示必定只有1个1，因此可以用(n & (-n)) == n得到结果
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (-n)) == n;
    }
};

//方法三：取模
//思路：如果1个数是2的幂次，则它一定是2^30的约数，即2^30 % n == 0，2^30是int中最大的2的幂次，（因为int是有符号，所以最高位表示符号位，所以最大只到2^30）
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int p = 1 << 30;
        return n > 0 && p % n == 0;
    }
};
