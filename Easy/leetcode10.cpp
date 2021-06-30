/*
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 * 所谓匹配，是要涵盖 整个 字符串s的，而不是部分字符串。
 */
//方法一：动态规划
//思路：和之前二维动态规划思路差不多，关键就在于一些特殊情况的处理
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i < n + 1; ++i) {
            if (p[i-1] == '*') {
                dp[0][i] = dp[0][i-2];
            }
        }
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] != '*') {
                    dp[i][j] = dp[i-1][j-1] && p[j-1] == s[i-1];
                } else if (p[j-2] != s[i-1] && p[j-2] != '.') {
                    dp[i][j] = dp[i][j-2];
                } else {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j] || dp[i][j-2];
                }
            }
        }
        return dp[m][n];        
    }
};
