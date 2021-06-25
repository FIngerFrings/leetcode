/*
 * 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 说明：每次只能向下或者向右移动一步。
 */
//方法一：动态规划
//思路：因为(i,j)只能从其上面或者左边过来，所以dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < n; i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }

        for(int i = 1; i < m; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};
//自己写的压缩空间的动态规划，但是觉得不够好
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(2, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = grid[i][j];
                }
                else if(i == 0){
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                }
                else if(j == 0){
                    dp[1][j] = dp[0][j] + grid[i][j];
                }
                else{
                    dp[1][j] = min(dp[1][j-1], dp[0][j]) + grid[i][j];
                }
            }
            if(i != 0){
                dp[0] = dp[1];
            }
        }
        return dp[0][n-1];
    }
};

//只需要一维数组的动态规划
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[j] = grid[i][j];
                }
                else if(i == 0){
                    dp[j] = dp[j-1] + grid[i][j];
                }
                else if(j == 0){
                    dp[j] = dp[j] + grid[i][j];
                }
                else{
                    dp[j] = min(dp[j-1], dp[j]) + grid[i][j];
                }
            }
        }
        return dp[n-1];
    }
};


