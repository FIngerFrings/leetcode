/* 
 * 给你一个由  '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 * 此外，你可以假设该网格的四条边均被水包围。
 */
//方法一：深度优先算法
//思路：从第一个元素开始搜索，如果某个元素为1，则对其进行深度优先算法，检测它上下左右4个元素的数值，如果为1，则再继续往下深度优先搜索，搜索到的所有元素都变为0
//岛屿的数量就是在外面循环中执行的深度搜索次数
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c){
        int nr = grid.size();
        int nc = grid[0].size();
        grid[r][c] = '0';
        if(r - 1 >= 0 && grid[r-1][c] == '1'){
            dfs(grid, r-1, c);
        }
        if(r + 1 < nr && grid[r+1][c] == '1'){
            dfs(grid, r+1, c);
        }
        if(c - 1 >= 0 && grid[r][c-1] == '1'){
            dfs(grid, r, c-1);
        }
        if(c + 1 < nc && grid[r][c+1] == '1'){
            dfs(grid, r, c+1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if(!nr){
            return 0;
        }
        int nc = grid[0].size();
        int nums = 0;
        for(int r = 0; r < nr; r++){
            for(int c = 0; c < nc; c++){
                if(grid[r][c] == '1'){
                    nums++;
                    dfs(grid, r, c);
                }
            }
        }
        return nums;
    }   
};
