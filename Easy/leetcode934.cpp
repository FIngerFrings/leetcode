/* 
 * 在给定的二维二进制数组 A 中，存在两座岛。（岛是由四面相连的 1 形成的一个最大组。）
 * 现在，我们可以将 0 变为 1，以使两座岛连接起来，变成一座岛。
 * 返回必须翻转的 0 的最小数目。（可以保证答案至少是 1 。）
 */

//方法一：BFS
//思路：对于这种二维数组的问题，首先要从三种搜索中想，回溯法常见问题中并没有这道题，所以首先考虑DFS和BFS
//BFS和DFS实际上是相同的，所以用什么都行
//本题实际上是求两个岛屿间的最短距离，因此我们可以先通过任意搜索方法找到其中一个岛
//屿，然后利用广度优先搜索，查找其与另一个岛屿的最短距离。
class Solution {
public:
    queue<pair<int, int>> points;
    void dfs(vector<vector<int>>& grid, int i, int j, int n){
        if(i < 0 || j < 0 || i == n || j == n || grid[i][j] == 2){
            return;
        }

        if(grid[i][j] == 0){
            points.push({i, j});
            grid[i][j] = 2;
            return;
        }

        grid[i][j] = 2;
        dfs(grid, i - 1, j, n);
        dfs(grid, i + 1, j, n);
        dfs(grid, i, j - 1, n);
        dfs(grid, i, j + 1, n);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        bool find = false;
        int nums = 0;
        for(int i = 0; i < n; i++){
            if(find)    break;
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j, n);
                    find = true;
                    break;
                }
            }
        }

        while(!points.empty()){
            ++nums;
            int point_size = points.size();
            while(point_size > 0){
                auto [k, l] = points.front();
                points.pop();
                if(k - 1 >= 0){
                    if(grid[k-1][l] == 1){
                        return nums;
                    }
                    else if(grid[k-1][l] == 0){
                        points.push({k-1, l});
                        grid[k-1][l] = 2;
                    }
                }
                if(k + 1 < n){
                    if(grid[k+1][l] == 1){
                        return nums;
                    }
                    else if(grid[k+1][l] == 0){
                        points.push({k+1, l});
                        grid[k+1][l] = 2;
                    }
                }
                if(l - 1 >= 0){
                    if(grid[k][l-1] == 1){
                        return nums;
                    }
                    else if(grid[k][l-1] == 0){
                        points.push({k, l-1});
                        grid[k][l-1] = 2;
                    }
                }
                if(l + 1 < n){
                    if(grid[k][l+1] == 1){
                        return nums;
                    }
                    else if(grid[k][l+1] == 0){
                        points.push({k, l+1});
                        grid[k][l+1] = 2;
                    }
                }
                --point_size;
            }
        }
        return nums;
    }
};

//pdf上的解法
class Solution {
public:
    vector<int> direction{-1, 0, 1, 0, -1}; //这种用法学一下，可以省略很多代码
    queue<pair<int, int>> points;
    void dfs(vector<vector<int>>& grid, int i, int j, int n){
        if(i < 0 || j < 0 || i == n || j == n || grid[i][j] == 2){
            return;
        }

        if(grid[i][j] == 0){
            points.push({i, j});
            return;
        }

        grid[i][j] = 2;
        dfs(grid, i - 1, j, n);
        dfs(grid, i + 1, j, n);
        dfs(grid, i, j - 1, n);
        dfs(grid, i, j + 1, n);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        bool find = false;
        int nums = 0;
        for(int i = 0; i < n; i++){
            if(find)    break;
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j, n);
                    find = true;
                    break;
                }
            }
        }
        int x, y;
        while(!points.empty()){
            ++nums;
            int point_size = points.size();
            while(point_size > 0){
                auto [k, l] = points.front();
                points.pop();
                for(int i = 0; i < 4; i++){
                    x = k + direction[i];
                    y = l + direction[i+1];
                    if(x >= 0 && y >= 0 && x < n && y < n){
                        if(grid[x][y] == 2){
                            continue;
                        }
                        if(grid[x][y] == 1){
                            return nums;
                        }
                        points.push({x, y});
                        grid[x][y] = 2;
                    }
                }
                --point_size;
            }
        }
        return nums;
    }
};
