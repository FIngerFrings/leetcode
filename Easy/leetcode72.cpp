/*
 * 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
 * 你可以对一个单词进行如下三种操作：
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 */
//方法一：动态规划
//思路：思路略，看官方解答
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if(m * n == 0)  return m + n;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for(int i = 0; i <= m; i++){
            dp[i][0] = i;
        }

        for(int i = 0; i <= n; i++){
            dp[0][i] = i;
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = min(dp[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1), min(dp[i-1][j] + 1,  dp[i][j-1] + 1));
            }
        }
        return dp[m][n];

    }
};

//下面也是动态规划，不过感觉和上面思路不太一样
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if(m * n == 0)  return m + n;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for(int i = 0; i <= m; i++){
            dp[i][0] = i;
        }

        for(int i = 0; i <= n; i++){
            dp[0][i] = i;
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                }   
            }
        }
        return dp[m][n];

    }
};
