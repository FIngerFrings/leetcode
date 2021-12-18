/*
 * 给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
 */
//方法一：动态规划
//思路：类似于完全平方数分割问题，这道题的分割条件由集合内的字符串决定，因此在考虑每个分
//割位置时，需要遍历字符串集合，以确定当前位置是否可以成功分割。注意对于位置 0，需要初
//始化值为真。
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++){
            for(const string &word : wordDict){
                int m = word.size();
                if(m > i || s.substr(i-m, m) != word){
                    continue;
                }
                dp[i] = dp[i] || dp[i-m];
            }
        }
        return dp[n];

    }
};

//完全背包问题求排列
//没有压缩空间的动态规划
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        int m = s.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        for(int j = 0; j <= m; j++){
            for(int i = 1; i <= n; i++){
                int l = wordDict[i-1].size();
                if(j >= l && s.substr(j-l, l) == wordDict[i-1]){
                    dp[i][j] = dp[i-1][j] || dp[n][j-l];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};

//压缩空间的动态规划
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        int m = s.size();
        vector<bool> dp(m+1, false);
        dp[0] = true;
        for(int j = 0; j <= m; j++){
            for(int i = 1; i <= n; i++){
                int l = wordDict[i-1].size();
                if(j >= l && s.substr(j-l, l) == wordDict[i-1]){
                    dp[j] = dp[j] || dp[j-l];
                }
                else{
                    dp[j] = dp[j];
                }
            }
        }
        return dp[m];
    }
};
