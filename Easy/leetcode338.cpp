/* 给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。 */
//方法一：暴力法
//思路：略
class Solution {
public:
    int getbit(int n){
        int num = 0;
        while(n){
            num += n & 1;
            n >>= 1;
        }
        return num;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        ans[0] = 0;
        if(n == 0)  return ans;
        for(int i = 1; i <= n; i++){
            ans[i] = getbit(i);
        }
        return ans;
    }
};

//也可以通过n &= (n - 1)将最低位的1去掉从而计算1的个数
class Solution {
public:
    int getbit(int n){
        int num = 0;
        while(n){
            ++num;
            n &= (n - 1);
        }
        return num;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        ans[0] = 0;
        if(n == 0)  return ans;
        for(int i = 1; i <= n; i++){
            ans[i] = getbit(i);
        }
        return ans;
    }
};

//方法二：动态规划 + 位运算
//思路：如果1个数的最后一位是1，则dp[i] = dp[i-1] + 1，如果最后1位是0，则dp[i] = dp[i >> 1]
class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0)  return {0};
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = (i & 1) ? dp[i-1] + 1 : dp[i >> 1];
        }
        return dp;
    }
};

//方法三：动态规划 + 最高有效位
//思路：i的1的个数是将它最高位1去掉后的数的1的位数+1，因此可以计算每个数的最高有效位，并将i-最高有效位得到的1的个数+1就是i的1的位数
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        int highbit = 0;
        for(int i = 1; i <= n; i++){
            if((i & (i - 1)) == 0){
                highbit = i;
            }
            ans[i] = ans[i - highbit] + 1;
        }
        return ans;
    }
};

//方法四：动态规划 + 最低有效位（就是方法二）
//思路：对于偶数，将它右移1位，1的个数不变，而对于奇数，将其右移1位，1的个数-1
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for(int i = 1; i <= n; i++){
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};

//方法五：动态规划 + 最低设置位
//思路：i & (i - 1) 可以将最后1位1去掉，因此ans[i] = ans[i & (i - 1)] + 1;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for(int i = 1; i <= n; i++){
            ans[i] = ans[i & (i - 1)] + 1;
        }
        return ans;
    }
};
