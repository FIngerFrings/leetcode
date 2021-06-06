/*
 * 给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
 * 你可以认为每种硬币的数量是无限的。
 */
//方法一：动态规划
//思路：下面是自己写的动态规划，思路和leetcode279相同，分割问题和定义状态得到下面的状态方程：
//dp[i] = min(dp[i-j]) + 1，其中j是硬币的面值，实现方法如下：
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int k : coins){
                if(i - k < 0 || dp[i-k] == -1){
                    continue;
                }
                else{
                    dp[i] = min(dp[i-k]+1, dp[i]);
                }
            }
            if(dp[i] == INT_MAX){
                dp[i] = -1;
            }
        }
        return dp[amount];
    }
};
//官方给的动态规划解法和上面一样，但是我写的还不够简洁
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int max = amount + 1;           //因为最多的情况就是amount全部由1元组成，所以max不会超过amount
        vector<int> dp(amount+1, max);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int k : coins){
                if(i - k >= 0){
                    dp[i] = min(dp[i-k]+1, dp[i]);    //如果这里使用的是INT_MAX，则会溢出，所以最好用amount+1
                }
            }
        }
        return dp[amount] == max ? -1 : dp[amount];
    }
};
