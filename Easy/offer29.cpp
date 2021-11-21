/* 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。 */
//方法一：模拟
//思路:同leetcode54
class Solution {
public:
    vector<vector<int>> direction{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0)  return {};
        int n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int i = 0, j = 0;
        int p = 0;
        vector<int> ans(m * n);
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
