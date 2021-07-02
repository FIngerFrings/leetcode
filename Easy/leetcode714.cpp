/*
 * 给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。
 * 你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
 * 返回获得利润的最大值。
 * 注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。
 */
//方法一：自己写的动态规划
//思路：本题和 122. 买卖股票的最佳时机 II 是非常类似的题，唯一的区别就在于本题有「手续费」而第 122 题没有。
//考虑到「不能同时参与多笔交易」，因此每天交易结束后只可能存在手里有一支股票或者没有股票的状态。
//定义状态dp[i][1] 表示第 i 天交易完后手里没有股票的最大利润，dp[i][0] 表示第 i 天交易完后手里持有一支股票的最大利润（i 从 0 开始）。
//如果第i天手里没有股票，则可能是昨天手里就没有股票，也有可能是昨天有，但是今天卖掉了，所以第i天手里没有股票的最大利润为dp[i][1] = max(dp[i-1][0] + prices[i] - fee, dp[i-1][1]);
//如果第i天有股票，则可能是今天买的，也有可能是昨天手里就有的，所以最大利润为dp[i][0] = max(dp[i-1][1] - prices[i], dp[i-1][0]);
//最后一天时，肯定是手里没有股票的时候利润最大，所以最后返回dp[n-1][1]
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < n; i++){
            dp[i][0] = max(dp[i-1][1] - prices[i], dp[i-1][0]);
            dp[i][1] = max(dp[i-1][0] + prices[i] - fee, dp[i-1][1]);
        }
        return dp[n-1][1];
    }
};

//压缩空间的动态规划
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int have = -prices[0];
        int n_have = 0;
        for(int i = 1; i < n; i++){
            int temp = have;
            have = max(n_have - prices[i], temp);
            n_have = max(temp + prices[i] - fee, n_have);
        }
        return n_have;
    }
};
