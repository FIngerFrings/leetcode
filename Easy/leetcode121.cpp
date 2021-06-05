/*
 * 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
 * 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
 * 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
 */
//方法一：暴力解法，会超时
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(prices[j] - prices[i] > max){
                    max = prices[j] - prices[i];
                }
            }
        }
        return max;
    }
};

//方法二：动态规划
//思路：这是自己想的动态规划，思路就是算出每天卖出能获得的最大利润，然后取其中的最大值
//第n天卖出的最大利润就是第n-1天卖出的最大利润加上这两天的差值
//执行后发现时间和内存消耗较大
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> q(n);
        q[0] = 0;
        for(int i = 1; i < n; i++){
            q[i] = (q[i-1] < 0) ? prices[i] - prices[i-1] : prices[i] - prices[i-1] + q[i-1];
        }
        return *max_element(q.begin(), q.end());
    }
};
