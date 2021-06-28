/*
 * 给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。
 * 一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
 * 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
 * 两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。
 */

//方法一：动态规划
//思路：说实话，依然不是特别懂这道题
//用二维数组存放动态规划的过程，dp是m+1×n+1的二维数组，其中dp[i][j]表示，长度为i-1的text1前缀和长度为j-1的text2的前缀的最长公共子串长度
//我们在遍历过程中，如果text[i-1]==text[j-1]，则dp[i][j] = dp[i-1][j-1]，即长度为i-1的text1前缀和长度为j-1的text2的前缀的最长公共子串长度是
//长度为i-2的text1前缀和长度为j-2的text2的前缀的最长公共子串长度+1，这个应该很好理解
//关键就在于如果text[i-1]！=text[j-1]，则最长公共子串的长度就是dp[i-1][j]和dp[i][j-1]中的最大值（关于这个要好好想想）
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
