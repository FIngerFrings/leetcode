/* 
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
 * 问总共有多少条不同的路径？
 */
//方法一：动态规划
//思路：根据动态规划的四个步骤，可知[m][n]点的路径数是[m-1][n]和[m][n-1]的路径和的和
//同时知道边界条件，然后写出下面的解答
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> q(m, vector<int>(n));
        for(int i = 0; i < n; i++){
            q[0][i] = 1;
        }

        for(int i = 0; i < m; i++){
            q[i][0] = 1;
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                q[i][j] = q[i-1][j] + q[i][j-1];
            }
        }
        return q[m-1][n-1];
    }
};

//方法二：组合数字
//思路:从左上角到右下角的过程中，我们需要移动 m+n-2m+n−2 次，其中有 m-1m−1 次向下移动，n-1n−1 次向右移动。因此路径的总数，
//就等于从 m+n-2m+n−2 次移动中选择 m-1m−1 次向下移动的方案数，即组合数：C(m-1)(m+n-1).具体公式看解答
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        for (int x = n, y = 1; y < m; ++x, ++y) {
            ans = ans * x / y;
        }
        return ans;
    }
};
//这种解法时间很快
