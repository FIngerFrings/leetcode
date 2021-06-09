/* 
 * 给定一个数组 prices ，其中 prices[i] 是一支给定股票第 i 天的价格。
 * 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 */

//方法一：
//思路：这道题实际上就是寻找多个不相交的区间的利润和的最大值，而某个区间的利润实际上就是将这个区间分成多个长度为1的区间，并计算每个区间的利润，之后将所有区间的利润相加
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
