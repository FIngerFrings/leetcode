/*
 * 给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。
 * 连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。
 */
//方法1：动态规划
//思路：略
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                dp[i] = dp[i-1] + 1;
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

//方法二：贪心
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count = 1, ans = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                ++count;
            }
            else{
                count = 1;
            }
            if(count > ans) ans = count;
        }
        return ans;
    }
};
