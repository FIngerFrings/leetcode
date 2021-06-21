/* 
 * 给定一个包含了一些 0 和 1 的非空二维数组 grid 。
 * 一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。
 * 找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)
 */
//方法一：深度优先搜索
//思路：遍历二维数组，如果为1，则dfs，遍历过的元素置0
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int r, int c){
        int ret = 1;
        grid[i][j] = 0;
        if(i - 1 >= 0 && grid[i-1][j] == 1){
            grid[i-1][j] = 0;
            ret += dfs(grid, i-1, j, r, c);
        }
        if(i + 1 < r && grid[i+1][j] == 1){
            grid[i+1][j] = 0;
            ret += dfs(grid, i+1, j, r, c);
        }
        if(j - 1 >= 0 && grid[i][j-1] == 1){
            grid[i][j-1] = 0;
            ret += dfs(grid, i, j-1, r, c);
        }
        if(j + 1 < c && grid[i][j+1] == 1){
            grid[i][j+1] = 0;
            ret += dfs(grid, i, j+1, r, c);
        }
        return ret;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        if(r == 0)  return 0;
        int c = grid[0].size();

        int max_size = 0;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == 1){
                    max_size = max(max_size, dfs(grid, i, j, r, c));
                }
            }
        }
        return max_size;
    }
};

//方法二：用栈实现深度优先搜索
//思路：用栈来实现深度优先算法，代码和广度优先算法的其实一样，只不过是queue换成了stack
//需要注意的是queue的第一个元素是front，stack的第一个元素是top
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        if(r == 0)  return 0;
        int c = grid[0].size();
        int max_size = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == 1){
                    int cur = 0;
                    stack<pair<int, int>> island;
                    island.push({i, j});
                    grid[i][j] = 0;
                    while(!island.empty()){
                        auto [row, cow] = island.top();
                        island.pop();
                        ++cur;
                        if(row - 1 >= 0 && grid[row-1][cow] == 1){
                            island.push({row-1, cow});
                            grid[row-1][cow] = 0;
                        }
                        if(row + 1 < r && grid[row+1][cow] == 1){
                            island.push({row+1, cow});
                            grid[row+1][cow] = 0;
                        }
                        if(cow - 1 >= 0 && grid[row][cow-1] == 1){
                            island.push({row, cow-1});
                            grid[row][cow-1] = 0;
                        }
                        if(cow + 1 < c && grid[row][cow+1] == 1){
                            island.push({row, cow+1});
                            grid[row][cow+1] = 0;
                        }
                    }
                    max_size = max(cur, max_size);
                }
            }
        }
        return max_size;
    }
};


//方法三：广度优先算法
//思路：和其他的广度优先算法一样，也是while+queue
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        if(r == 0)  return 0;
        int c = grid[0].size();
        int max_size = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == 1){
                    int cur = 0;
                    queue<pair<int, int>> island;
                    island.push({i, j});
                    grid[i][j] = 0;
                    while(!island.empty()){
                        auto [row, cow] = island.front();
                        island.pop();
                        ++cur;
                        if(row - 1 >= 0 && grid[row-1][cow] == 1){
                            island.push({row-1, cow});
                            grid[row-1][cow] = 0;
                        }
                        if(row + 1 < r && grid[row+1][cow] == 1){
                            island.push({row+1, cow});
                            grid[row+1][cow] = 0;
                        }
                        if(cow - 1 >= 0 && grid[row][cow-1] == 1){
                            island.push({row, cow-1});
                            grid[row][cow-1] = 0;
                        }
                        if(cow + 1 < c && grid[row][cow+1] == 1){
                            island.push({row, cow+1});
                            grid[row][cow+1] = 0;
                        }
                    }
                    max_size = max(cur, max_size);
                }
            }
        }
        return max_size;
    }
};
