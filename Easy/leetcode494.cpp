/*
 * 给你一个整数数组 nums 和一个整数 target 。
 *向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
 * 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
 * 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
 */
//方法一：回溯法
//思路：对于数组中的每个元素，无非就两种选择，加它或减它
//所以使用回溯法遍历所有可能
class Solution {
public:
    int ret = 0;

    void backtrack(vector<int>& nums, int target, int curr, int n, int t){
        if(curr == n){
            if(t == target) ++ret;
            return;
        }

        backtrack(nums, target, curr + 1, n, t + nums[curr]);
        backtrack(nums, target, curr + 1, n, t - nums[curr]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        backtrack(nums, target, 0, nums.size(), 0);
        return ret;

    }
};

//方法二：动态规划
//思路：dp[i][j]用来记录nums前i个数的和等于j的方案数
//边界条件这里不详细说明了。每个元素有两种情况，选择还是不选择，如果不选择，则方案数为前面i-1个元素的方案数dp[i-1][j]，如果选择，则为dp[i-1][j-nums[i-1]]
//关键就在于怎么转化成01背包问题，可以先计算全部元素的和，假设所有前面加负号的元素和为neg，则前面加正号的元素和为sum-neg，则sum-neg-neg=target
//算出来neg=(sum-target)/2，如果neg不是整数，则返回0，否则就变成找出nums中的数是他们相加为neg，这就是01背包问题
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if((sum - target) % 2 || (sum - target) < 0)  return 0;
        int t = (sum - target) / 2;
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(t + 1));
        dp[0][0] = 1;
        for(int i = 1;i <= n; i++){
            for(int j = 0; j <= t; j++){
                if(j < nums[i-1]){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][t];
        
    }
};
