/*
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 */
//方法一：回溯
//思路：对于数组中的每个元素，无非就两种选择，加入分割后的两个子集中的一个，那么可以使用递归（回溯）的方式遍历所有情况
//说实话现在想想确实时间复杂度很高
//结果也确实超时了，但我觉得方法是没问题的
class Solution {
public:
    bool find = false;
    void backtrack(vector<int>& nums, int curr, int sum1, int sum2, int n){
        if(find == true)    return;
        if(curr == n){
            if(sum1 == sum2){
                find = true;
            }
            return;
        }

        backtrack(nums, curr + 1, sum1 + nums[curr], sum2, n);
        backtrack(nums, curr + 1, sum1, sum2 + nums[curr], n);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        backtrack(nums, 0, 0, 0, n);
        return find;
    }
};

//根据动态规划的思路改进后的回溯法，但是还是超时了
class Solution {
public:
    bool find = false;

    void backtrack(vector<int>& nums, int curr, int sum, int n, int target){
        if(sum == target){
            find = true;
            return;
        }
        else if(sum > target){
            return;
        }

        if(curr == n){
            return;
        }
        
        backtrack(nums, curr + 1, sum, n, target);
        backtrack(nums, curr + 1, sum + nums[curr], n, target);
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2) return false;
        int target = sum / 2, n = nums.size();
        backtrack(nums, 0, 0, n, target);
        return find;
    }
};

//方法二：动态规划
//思路：本题等价于 0-1 背包问题，设所有数字和为 sum，我们的目标是选取一部分物品，使得它们的总和为 sum/2。
//如果sum不能被2整除，说明不会有子集的和为sum的一半，直接返回false
//同时，如果数组个数小于2，则说明不能分为两个子集，返回false
//对于dp[i][j]，如果nums[i-1]大于j，则不能选择nums[i-1]， dp[i][j] = dp[i-1][j]
//否则就是dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if (sum % 2 || n < 2) return false;
        int target = sum / 2, n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                if(j >= nums[i-1]){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    }
};
