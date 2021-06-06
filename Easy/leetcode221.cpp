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
//思路：根据动态规划四步骤，首先要分割问题并定义状态
//这里我们用dp[i][j]表示以(i,j)为右下角，且只包含1的正方形的边长最大值。如果我们能计算出所有dp[i][j]的值，那么其中的最大值即为矩阵中只包含 1 的正方形的边长最大值，
//其平方即为最大正方形的面积。
///那么如何计算dp[i][j]中的每个元素值呢？对于每个位置(i,j)，检查在矩阵中该位置的值：
//如果该位置的值是0，则dp(i,j)=0，因为当前位置不可能在由1 组成的正方形中；
//如果该位置的值是1，则dp(i,j) 的值由其上方、左方和左上方的三个相邻位置的dp 值决定。具体而言，当前位置的元素值等于三个相邻位置的元素中的最小值加1
//具体原因为左上角的dp值为左上角这个元素所能构成的最大正方形，如果当前元素为1，则要看新增加的两条边上有多少个1
//也就是看上方和左方两个元素的dp值。左上角、左边、上面这三个元素的dp值中的最小值加上1就是当前元素的dp值
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
