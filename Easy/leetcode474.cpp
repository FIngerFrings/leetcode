/*
 * 给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
 * 请你找出并返回 strs 的最大子集的大小，该子集中 最多 有 m 个 0 和 n 个 1 。
 * 如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
 */

//方法一：动态规划
//思路：使用三维数组记录动态规划过程，思路同01背包问题，不过这里有两个限制条件m和n
class Solution {
public:
    vector<int> getzerosones(string s){
        vector<int> res(2, 0);
        for(char k : s){
            if(k == '0'){
                ++res[0];
            }
            else{
                ++res[1];
            }
        }
        return res;

    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l = strs.size();
        vector<vector<vector<int>>> dp(l+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        for(int i = 1; i <= l; i++){
            auto node = getzerosones(strs[i-1]);
            int zero = node[0];
            int one = node[1];
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= n; k++){
                    if(j < zero || k < one){
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                    else{
                        dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-zero][k-one]+1);
                    }
                }
            }
        }
        return dp[l][m][n];
    }
};

//压缩空间后的动态规划
class Solution {
public:
    vector<int> getzerosones(string s){
        vector<int> res(2, 0);
        for(char k : s){
            if(k == '0'){
                ++res[0];
            }
            else{
                ++res[1];
            }
        }
        return res;

    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l = strs.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= l; i++){
            auto node = getzerosones(strs[i-1]);
            int zero = node[0];
            int one = node[1];
            for(int j = m; j >= 0; j--){
                for(int k = n; k >= 0; k--){
                    if(j < zero || k < one){
                        dp[j][k] = dp[j][k];
                    }
                    else{
                        dp[j][k] = max(dp[j][k], dp[j-zero][k-one]+1);
                    }
                }
            }
        }
        return dp[m][n];
    }
};
