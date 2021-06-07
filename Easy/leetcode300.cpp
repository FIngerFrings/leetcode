/*
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 * 子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
 */
//方法一：自己写的动态规划
//思路：首先也是分割问题和定义状态，这里的状态 方程就是dp[i] = max(dp[i]) + 1，其中i < j且nums[i] < nums[j]
//但是这样时间复杂度比较高
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = 1;
        for(int i = 1; i < n; i++){
            int maxlength = 0;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    maxlength = max(maxlength, dp[j]);
                }
            }
            dp[i] = maxlength + 1;
        }
        sort(dp.begin(), dp.end());
        return dp[n-1];
    }
};
