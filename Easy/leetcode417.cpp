/* 
 * 给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。
 * 规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。
 * 请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。
 */
//方法一：DFS
//思路：虽然题目要求的是满足向下流能到达两个大洋的位置，如果我们对所有的位置进行搜索，那么在不剪枝的情况下复杂度会很高。因此我们可以反过来想，从两个大洋开始向上流，这样我们
//只需要对矩形四条边进行搜索。搜索完成后，只需遍历一遍矩阵，满足条件的位置即为两个大洋向上流都能到达的位置。
class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<vector<int>>& heights, vector<vector<bool>> &canreach, int i, int j){
        if(canreach[i][j])  return;
        int m = heights.size();
        int n = heights[0].size();
        canreach[i][j] = true;
        if(i - 1 >= 0 && heights[i-1][j] >= heights[i][j]){
            dfs(heights, canreach, i-1, j);
        }
        if(i + 1 < m && heights[i+1][j] >= heights[i][j]){
            dfs(heights, canreach, i+1, j);
        }
        if(j - 1 >= 0 && heights[i][j-1] >= heights[i][j]){
            dfs(heights, canreach, i, j-1);
        }
        if(j + 1 < n && heights[i][j+1] >= heights[i][j]){
            dfs(heights, canreach, i, j+1);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.empty() || heights[0].empty())   return {};
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> canreach_p(m, vector<bool>(n, false));
        vector<vector<bool>> canreach_a(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            dfs(heights, canreach_p, i, 0);
            dfs(heights, canreach_a, i, n - 1);
        }

        for(int i = 0; i < n; i++){
            dfs(heights, canreach_p, 0, i);
            dfs(heights, canreach_a, m - 1, i);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(canreach_p[i][j] && canreach_a[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
