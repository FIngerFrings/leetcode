/* 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。 */
//方法一：利用额外的数组
//思路：对于第i行第j列元素，反转后会变成倒数第i列的第j个元素
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        auto matrix_new = matrix;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matrix_new[j][n - 1 - i] = matrix[i][j];
            }
        }
        matrix = matrix_new;
    }
};

//方法二：原地旋转
//思路：将二维矩阵分成4个区域，四个区域中的点进行旋转，详见官方解答
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n / 2; i++){
            for(int j = 0; j < (n + 1) / 2; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = temp;
            }
        }
    }
};

//方法三：两次翻转
//思路：先根据水平翻转，之后根据主对角线翻转
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n / 2; i++){
            for(int j = 0; j < n; j++){
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
