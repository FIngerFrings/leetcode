/*
 * 给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 */
//方法一：动态规划
//思路：略，看官方阶段
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty())    return 0;
        int n = prices.size();
        k = min(k, n/2);
        vector<vector<int>> buy(n, vector<int>(k+1));
        vector<vector<int>> sell(n, vector<int>(k+1));
        buy[0][0] = -prices[0];
        sell[0][0] = 0;
        for(int i = 1; i <= k; i++){
            buy[0][i] = INT_MIN / 2;
            sell[0][i] = INT_MIN / 2;
        }

        for(int i = 1; i < n; i++){
            buy[i][0] = max(buy[i-1][0], sell[i-1][0] - prices[i]);
            for(int j = 1; j <= k; j++){
                buy[i][j] = max(sell[i-1][j] - prices[i], buy[i-1][j]);
                sell[i][j] = max(buy[i-1][j-1] + prices[i], sell[i-1][j]);
            }
        }

        return *max_element(sell[n-1].begin(), sell[n-1].end());
    }
};

//代码随想录动态规划
//思路：实际上就是之前股票问题动态规划的加强版
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k == 0 || n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(2*k+1, 0));
        for(int i = 1; i < 2*k+1; i+=2){
            dp[0][i] = -prices[0];
        }
        for(int i = 1; i < n; i++){
            dp[i][0] = dp[i-1][0];
            for(int j = 1; j < 2*k+1; j++){
                if(j % 2 != 0){
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] - prices[i]);
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + prices[i]);
                }
            }
        }
        return dp[n-1][2*k];
    }
};
