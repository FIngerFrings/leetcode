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
