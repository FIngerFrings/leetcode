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

//压缩空间后的动态规划
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(2, vector<int>(n+1));
        dp[0][0] = 0;
        for(int i = 0; i <= n; i++){
            dp[0][i] = i;
        }
        for(int i = 1; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(j == 0){
                    dp[1][j] = i;
                }
                else if(word1[i-1] != word2[j-1]){
                    dp[1][j] = min(dp[0][j], dp[1][j-1]) + 1;
                }
                else{
                    dp[1][j] = dp[0][j-1];
                }
            }
            dp[0] = dp[1];
        }
        return dp[1][n];
    }
};

//方法二：最长公共子序列
//思路：我们可以求出word1和word2的最长公共子序列的长度，最小步数就是word1.size() + word2.size() - 2 * 最小公共子序列长度
//这里是使用了动态规划求的最长公共子序列
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(word1[i-1] != word2[j-1]){
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                else{
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
            }
        }
        return m + n - 2 * dp[m][n];
    }
};

//上面是使用动态规划得到的最长公共子序列长度，下面的方法使用递归得到最长子序列的长度
//但是会超时
class Solution {
public:
    int minDistance(string word1, string word2) {
        return word1.size() + word2.size() - 2 * getmaxlength(word1, word2, word1.size(), word2.size());
    }

    int getmaxlength(string word1, string word2, int m, int n){
        if(m == 0 || n == 0){
            return 0;
        }
        int maxlength;
        if(word1[m-1] != word2[n-1]){
            maxlength = max(getmaxlength(word1, word2, m-1, n), getmaxlength(word1, word2, m, n-1));
        }
        else{
            maxlength = getmaxlength(word1, word2, m-1, n-1) + 1;
        }
        return maxlength;
    }
};

//上面会超时的原因是递归的过程中做了很多重复的计算，所以使用记忆化搜索减少时间
class Solution {
public:
    vector<vector<int>> dp;
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        dp.resize(m+1, vector<int>(n+1));
        return m + n - 2 * getmaxlength(word1, word2, m, n);
    }

    int getmaxlength(string word1, string word2, int m, int n){
        if(m == 0 || n == 0){
            return 0;
        }
        if(dp[m][n] > 0)    return dp[m][n];
        if(word1[m-1] != word2[n-1]){
            dp[m][n] = max(getmaxlength(word1, word2, m-1, n), getmaxlength(word1, word2, m, n-1));
        }
        else{
            dp[m][n] = getmaxlength(word1, word2, m-1, n-1) + 1;
        }
        return dp[m][n];
    }
};
