/* 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。 */
//方法一：模拟
//思路：直接模拟螺旋遍历的顺序，需要一个数组来记录下一个元素是否遍历过
class Solution {
public:
    vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans(m * n);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        int i = 0, j = 0;
        int p = 0;

        for(int k = 0; k < m * n; k++){
            ans[k] = matrix[i][j];
            visited[i][j] = true;

            int nexti = i + direction[p][0], nextj = j + direction[p][1];
            if(nexti < 0 || nexti >= m || nextj < 0 || nextj >= n || visited[nexti][nextj]){
                p = (p + 1) % 4;
            }
            i += direction[p][0];
            j += direction[p][1];
        }

        return ans;
    }
};
