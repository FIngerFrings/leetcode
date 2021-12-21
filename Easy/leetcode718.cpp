/* 给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。 */
//方法一：动态规划
//思路：略
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int ans = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                if(dp[i][j] > ans) ans = dp[i][j];
            }
        }
        return ans;
    }
};
