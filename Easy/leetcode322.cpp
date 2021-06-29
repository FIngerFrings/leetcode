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

//方法二：暴力解法，会超时
//思路：同样和leetcode279相同
class Solution {
public:
    int numAmount(vector<int>& coins, int amount, int max){
        int num = max;
        for(int k : coins){
            if(k < amount){
                num = min(numAmount(coins, amount - k, max) + 1, num);
            }
            else if(k == amount){
                return 1;
            }
        }
        return num;
    }

    int coinChange(vector<int>& coins, int amount) {
        int max = amount + 1;
        int minnum = numAmount(coins, amount, max);
        if(amount == 0){
            return 0;
        }
        return minnum == max ? -1 : minnum;
    }
};

//方法三：记忆化搜索
//思路：实际上就是暴力解法，或称为递归，然后配合一个数组实现的，数组用来存放之前计算的结果，如果在后面的计算中有用到，则直接拿来用
//这样就不用重新计算了，减少了时间
//实际上就是递归+动态规划
class Solution {
public:
    vector<int> count;
    
    int dp( vector<int> &coins, int amount){
        if(amount == 0){
            return 0;
        }
        if(count[amount-1] != 0)    return count[ amount-1] ;
        int minnum = INT_MAX;
        for(int k : coins){
            if(k <= amount){
                int res = dp(coins, amount - k);
                if(res != -1){
                    minnum = min(res + 1, minnum);
                }
            }
        }
        if(minnum == INT_MAX){
            count[ amount-1] = -1;
        }
        else{
            count[ amount-1] = minnum;
        }
        return count[ amount-1];
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount < 0)    return 0;
        count.resize(amount);
        return dp(coins, amount);
    }
};

//方法三：动态规划（完全背包问题）
//思路：这实际上是一个完全背包问题
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(n == 0)  return 0;
        vector<vector<int>> dp(n+1, vector<int>(amount+1, amount+1));
        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= amount; j++){
                if(coins[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1);
                }
            }
        }
        return (dp[n][amount] == amount+1) ? -1 : dp[n][amount];
    }
};

//压缩空间后的完全背包问题的动态规划
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(n == 0)  return 0;
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= amount; j++){
                if(coins[i-1] > j){
                    continue;
                }
                dp[j] = min(dp[j], dp[j-coins[i-1]] + 1);
            }
        }
        return (dp[amount] == amount+1) ? -1 : dp[amount];
    }
};
