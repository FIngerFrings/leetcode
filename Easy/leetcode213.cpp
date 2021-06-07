/*
 * 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。
 * 同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
 */
//方法一：动态规划
//思路：其实和198相同，只不过这里变成了一个环，对于0和n-1这两栋房子，只能偷其中的一栋
//所以实际上就是求[0, n-2]和[1, n-1]这两个范围中的最大值
class Solution {
public:
    int r(vector<int>& nums, int l, int r){
        int n = r - l + 1;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = nums[l];
        for(int i = 2; i <= n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[l+i-1]);
        }
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return 0;
        if(n < 3)   return *max_element(nums.begin(), nums.end());
        return max(r(nums, 0, n - 2), r(nums, 1, n-1));
    }
};
