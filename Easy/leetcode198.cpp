/*
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
 * 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
 */

//方法一：动态规划
//思路：用dp[i]来表示偷窃前i间房所能获得的最高金额，如果不偷第i间房，则所能获得的最大金额就是dp[i-1]，如果偷窃第i间房
//所能获得的最大金额就是前i-2间房所能得到的最大金额加上第i间房的金额
//dp[i] = max(dp[i-1], dp[i-2] + nums[i-1])
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        if(n < 2){
            return nums[0];
        }
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = nums[0];

        for(int i = 2; i <= n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }
        return dp[n];
    }
};
//比较规范的写法
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())  return 0;
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[1] = nums[0];
        for(int i = 2; i <= n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }
        return dp[n];
    }
};

//压缩空间的dp
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())  return 0;
        int n = nums.size();
        if(n == 1)  return nums[0];
        int pre2 = 0, pre1 = 0, curr;
        for(int i = 0; i < n; i++){
            curr = max(pre2 + nums[i], pre1);
            pre2 = pre1;
            pre1 = curr;
        }
        return pre1;
    }
};
