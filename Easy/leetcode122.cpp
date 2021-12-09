/* 
 * 给定一个数组 prices ，其中 prices[i] 是一支给定股票第 i 天的价格。
 * 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 */

//方法一：贪心
//思路：这道题实际上就是寻找多个不相交的区间的利润和的最大值，而某个区间的利润实际上就是将这个区间分成多个长度为1的区间，并计算每个区间的利润，之后将所有区间的利润相加
//贪心的角度考虑我们每次选择贡献大于 0 的区间即能使得答案最大化
//需要说明的是，贪心算法只能用于计算最大利润，计算的过程并不是实际的交易过程。
//这道题得出的一个结论就是，对于一个区间，所能获得的最大利润就是只要涨了卖就能获得最大利润
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for(int i = 1; i < prices.size(); i++){
            res += max(0, prices[i]-prices[i-1]);
        }
        return res;
    }
};


//方法二：动态规划
//思路：每天交易结束后只可能存在手里有一支股票或者没有股票的状态。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp0 = 0, dp1 = -prices[0];
        for(int i = 1; i < n; i++){
            int newdp0 = max(dp0, dp1 + prices[i]);
            int newdp1 = max(dp1, dp0 - prices[i]);
            dp0 = newdp0;
            dp1 = newdp1;
        }
        return dp0;
    }
};

//代码随想录动态规划
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        for(int i = 1; i < n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};
