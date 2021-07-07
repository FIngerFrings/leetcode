/* 给定一个正整数，检查它的二进制表示是否总是 0、1 交替出现：换句话说，就是二进制表示中相邻两位的数字永不相同。 */
//方法一：位运算
//思路：如果是交替出现01，则将其右移一位后和原来的自己异或应该出线全是1的情况
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int p = n;
        int t = 0;
        while(p){
            t <<= 1;
            t ^= 1;
            p >>= 1;
        }
        return (n ^ (n >> 1)) == t;
    }
};

//方法二：除以2
//不断对比当前最后1位和之前的最后1位
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int pre = n & 1;
        n >>= 1;
        while(n){
            int curr = n & 1;
            if(curr ^ pre == 0){
                return false;
            }
            pre = curr;
            n >>= 1;
        }
        return true;
    }
};

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int pre = n % 2;
        n >>= 1;
        while(n){
            int curr = n % 2;
            if(curr ^ pre == 0){
                return false;
            }
            pre = curr;
            n /= 2;
        }
        return true;
    }
};
