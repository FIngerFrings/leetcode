/*
 * 数组的每个下标作为一个阶梯，第 i 个阶梯对应着一个非负数的体力花费值 cost[i]（下标从 0 开始）。
 * 每当你爬上一个阶梯你都要花费对应的体力值，一旦支付了相应的体力值，你就可以选择向上爬一个阶梯或者爬两个阶梯。
 * 请你找出达到楼层顶部的最低花费。在开始时，你可以选择从下标为 0 或 1 的元素作为初始阶梯。
 */
//方法一：动态规划
//思路：dp[i] = min(dp[i-1], dp[i-2]) + cost[i]
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 2) return min(cost[0], cost[1]);
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < n; i++){
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }
        return min(dp[n-1], dp[n-2]);
    }
};
