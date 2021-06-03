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

//方法二：广度优先算法
//思路：同样首先也是要搜索值为1的元素，之后创建队列，将其上下左右中值为1的元素加入队列，然后将它们变为0.同时对它们的上下左右做同样的操作
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if(!nr) return 0;
        int nc = grid[0].size();
        int num = 0;

        for(int r = 0; r < nr; r++){
            for(int c = 0; c < nc; c++){
                if(grid[r][c] == '1'){
                    num++;
                    grid[r][c] = '0';
                    queue<pair<int, int>> q;            //可以不用直接将元素放入队列中，而是将其下标放入队列，如果是多个下标的情况可以使用pair
                    q.push({r, c});
                    while(!q.empty()){
                        auto rc = q.front();
                        q.pop();
                        int row = rc.first;
                        int col = rc.second;
                        if(row - 1 >= 0 && grid[row-1][col] == '1'){
                            q.push({row-1, col});
                            grid[row-1][col] = '0';
                        }
                        if(row + 1 < nr && grid[row+1][col] == '1'){
                            q.push({row+1, col});
                            grid[row+1][col] = '0';
                        }
                        if(col - 1 >= 0 && grid[row][col-1] == '1'){
                            q.push({row, col-1});
                            grid[row][col-1] = '0';
                        }
                        if(col + 1 < nc && grid[row][col+1] == '1'){
                            q.push({row, col+1});
                            grid[row][col+1] = '0';
                        }
                    }
                }
            }
        }
        return num;
    }
};

//和leetcode938中所想的一样，深度优先算法用递归，广度优先算法用while循环+队列
//方法三：并查集
//思路：使用并查集，如果某个元素为1，就将其上下左右元素中为1的元素加入到同一个集合中，最后剩下几个集合，就有几块岛屿
class UnionFind{
public:
    UnionFind(vector<vector<char>>& grid){
        count = 0;      //一开始忘记初始化count，得到的结果总是不对
        int nr = grid.size();
        int nc = grid[0].size();

        for(int i = 0; i < nr; i++){
            for(int j = 0; j < nc; j++){
                if(grid[i][j] == '1'){
                    parent.push_back(i*nc+j);
                    count++;
                }
                else{
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }

    int find(int i){
        if(parent[i] != i){
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void unit(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx == rooty){
            return;
        }

        if(rank[rootx] < rank[rooty]){
            swap(rootx, rooty);
        }

        parent[rooty] = rootx;
        count--;
        if(rank[rootx] == rank[rooty]){
            rank[rootx]++;
        }
    }

    int getcount(void){
        return count;
    }
private:
    vector<int> parent;
    vector<int> rank;
    int count;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if(!nr) return 0;
        int nc = grid[0].size();

        UnionFind q(grid);

        for(int r = 0; r < nr; r++){
            for(int c = 0; c < nc; c++){
                if(grid[r][c] == '1'){
                    grid[r][c] = '0';
                    if(r - 1 >= 0 && grid[r-1][c] == '1'){
                        q.unit(r*nc+c, (r-1)*nc+c);
                    }
                    if(r + 1 < nr && grid[r+1][c] == '1'){
                        q.unit(r*nc+c, (r+1)*nc+c);
                    } 
                    if(c - 1 >= 0 && grid[r][c-1] == '1'){
                        q.unit(r*nc+c, r*nc+c-1);
                    } 
                    if(c + 1 < nc && grid[r][c+1] == '1'){
                        q.unit(r*nc+c, r*nc+c+1);
                    } 
                }
            }
        }
        return q.getcount();
    }
};

//想这种需要分类的可以使用并查集
