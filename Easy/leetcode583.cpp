/* 给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。*/
//方法一：动态规划
//思路：动态规划的核心就在于状态方程的定义，在这题中dp[i][j]表示从word1的前i个字符转变成word2的前j个字符所需要的最小步数
//如果word1[i-1]和word2[j-1]不相等，则我们去计算word1的前i-1个字符转变成word2的前j个字符所需要的最小步数，以及word1的前i个字符转变到word2的前j个字符所需要的最小步数
//取其中的最小值并+1就是dp[i][j]了，这里你要相信之前算的都是对的
//如果word1[i-1]和word2[j-1]相等，则dp[i][j]就是dp[i-1][j-1]
//实际上的思路就是，对于word1[i-1]和word2[j-1]不相等的情况，这两个字母中的一个必定需要删掉，而删掉哪个比较好
//就看是从word1的前i-1个字符转变成word2的前j个字符所需要的最小步数最小，还是word1的前i个字符转变到word2的前j个字符所需要的最小步数
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(int i = 0; i <= m; i++){
            dp[i][0] = i;
        }
        for(int i = 0; i <= n; i++){
            dp[0][i] = i;
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(word1[i-1] != word2[j-1]){
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                }
                else{
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};
//其实我觉得在思路上这个比较合理
//上面的解法在word1[i-1]和word2[j-1]相等的情况下，是直接默认两个都不删除，所以dp[i][j]就是dp[i-1][j-1]，但是我觉得还是需要去考虑是否有可能删除其中某一个也可以达到最小步数
//因此在相等的情况下增加了去比较dp[i-1][j-1]和min(dp[i-1][j], dp[i][j-1])+1的步骤
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(int i = 0; i <= m; i++){
            dp[i][0] = i;
        }
        for(int i = 0; i <= n; i++){
            dp[0][i] = i;
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(word1[i-1] != word2[j-1]){
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                }
                else{
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])+1);
                }
            }
        }
        return dp[m][n];
    }
};
