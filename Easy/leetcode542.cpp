/*
 * 给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。
 * 两个相邻元素间的距离为 1 。
 */
//方法一算一种暴力解法？？？不过超时了
//思路：首先将数组中所有的1放进队列中，然后依次弹出，访问每个元素周围的四个元素，如果有0，说明这个元素距离0为1
//否则就是其周围4个元素到0距离最小+1
class Solution {
public:
    vector<int> direction = {-1, 0, 1, 0, -1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if(mat.empty() || mat[0].empty())   return {};
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        queue<pair<int, int>> points;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    points.push({i, j});
                }
            }
        }

        while(!points.empty()){
            auto [i, j] = points.front();
            points.pop();
            int x, y;
            int len = max(m, n);
            for(int k = 0; k < 4; k++){
                x = i + direction[k];
                y = j + direction[k+1];
                if(x < 0 || y < 0 || x >= m || y >= n){
                    continue;
                }
                if(mat[x][y] == 0){
                    ans[i][j] = 1;
                    break;
                }
                else{
                    len = min(len, ans[x][y]);
                }
            }
            if(ans[i][j] == 1){
                continue;
            }
            else if(len == 0){
                points.push({i, j});
            }
            else{
                ans[i][j] = len + 1;
            }
        }
        return ans;
    }
};

//还有另外一种暴力解法，就是找出距离每个1最近的0，然后计算距离，不过时间复杂度非常高

//方法二：广度优先搜索
//思路：从每个0开始搜索，依次向外扩展，每次距离+1，为了防止重复对同一个元素访问，需要记录是否访问过
//核心思想就是先访问到的一定距离比较近
class Solution {
public:
    vector<int> direction = {-1, 0, 1, 0, -1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> points;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    points.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        while(!points.empty()){
            auto [k, c] = points.front();
            points.pop();
            int x, y;
            for(int i = 0; i < 4; i++){
                x = k + direction[i];
                y = c + direction[i + 1];
                if(x < 0 || y < 0 || x >= m || y >= n || vis[x][y] == 1){
                    continue;
                }
                ans[x][y] = ans[k][c] + 1;
                vis[x][y] = 1;
                points.push({x, y});
            }
        }
        return ans;
    }
};
