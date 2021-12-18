/*
 * 给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
 * 题目数据保证答案符合 32 位整数范围。
 */
//方法一：动态规划
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1;
        for(int j = 0; j <= target; j++){
            for(int i = 1; i <= n; i++){
                if(j >= nums[i-1] && dp[i-1][j] < INT_MAX - dp[n][j-nums[i-1]]){
                   dp[i][j] = dp[i-1][j] + dp[n][j-nums[i-1]]; 
                }
                else{
                    dp[i][j] = dp[i-1][j]; 
                }
            }
        }
        return dp[n][target];
    }
};

//压缩空间的动态规划
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int j = 0; j <= target; j++){
            for(int i = 1; i <= n; i++){
                if(j >= nums[i-1] && dp[j - nums[i-1]] < INT_MAX - dp[j]){
                    dp[j] += dp[j-nums[i-1]];
                }
            }
        }
        return dp[target];
    }
};
