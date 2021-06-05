/* 在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。*/
//方法一：暴力解法
//思路：由于正方形的面积等于边长的平方，因此要找到最大正方形的面积，首先需要找到最大正方形的边长，然后计算最大边长的平方即可。
//遍历矩阵中的每个元素，每次遇到 11，则将该元素作为正方形的左上角；
//确定正方形的左上角后，根据左上角所在的行和列计算可能的最大正方形的边长（正方形的范围不能超出矩阵的行数和列数），在该边长范围内寻找只包含 1 的最大正方形；
//每次在下方新增一行以及在右方新增一列，判断新增的行和列是否满足所有元素都是 11。
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        if(row == 0 || col == 0){
            return 0;
        }
        int maxside = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == '1'){
                    maxside = max(maxside, 1);
                    int currmaxside = min(row - i, col - j);
                    for(int k = 1; k < currmaxside; k++){
                        bool flag = true;
                        if(matrix[i+k][j+k] == '0'){
                            break;
                        }
                        for(int m = 0; m < k; m++){
                            if(matrix[i+k][j+m] == '0' || matrix[i+m][j+k] == '0'){
                                flag = false;
                                break;
                            }
                        }
                        if(!flag){
                            break;
                        }
                        else{
                            maxside = max(maxside, k+1);
                        }
                    }
                }
            }
        }
        return maxside * maxside;
    }
};

//方法二：动态规划
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxside = 0;
        if(matrix.size() == 0 || matrix[0].size() == 0){
            return 0;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col));

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == '1'){
                    if(i == 0 || j == 0){
                        dp[i][j] = 1;
                    }
                    else{
                        dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    }
                    maxside = max(maxside, dp[i][j]);
                }
            }
        }
        return maxside * maxside;
    }
};
