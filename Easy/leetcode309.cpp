/*
 * 给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。
 * 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
 * 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 */
//方法一：动态规划
//思路：略，看官方解答
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())  return 0;
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][0] = -prices[0];
        for(int i = 1; i < n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][2] - prices[i]);
            dp[i][1] = dp[i-1][0] + prices[i];
            dp[i][2] = max(dp[i-1][1], dp[i-1][2]);
        }
        return max(dp[n-1][1], dp[n-1][2]);
    }
};

//自己写的动态规划
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1) return 0;
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[1][0] = max(dp[0][0], -prices[1]);
        dp[1][1] = max(dp[0][1], dp[0][0] + prices[1]);
        for(int i = 2; i < n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-2][1] - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};

//代码随想录动态规划，4个状态
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));
        dp[0][0] = -prices[0];
        for(int i = 1; i < n; i++){
            dp[i][0] = max(dp[i-1][0], max(dp[i-1][3], dp[i-1][1]) - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][3]);
            dp[i][2] = dp[i-1][0] + prices[i];
            dp[i][3] = dp[i-1][2];
        }
        return max(dp[n-1][3], max(dp[n-1][1], dp[n-1][2]));
    }
};
