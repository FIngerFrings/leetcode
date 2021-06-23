/* 
 * 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 */

//方法一：DFS
//思路：换位思考，和边界上的O相连的O一定不会是被X包围，所以只要对边界上的O进行搜索，找到所有与边界上的O相连的O，并标记为A，剩下的O就是被X包围的O
//之后遍历数组，将所有的A换成O，将所有的O换成X
class Solution {
public:
    vector<int> direction{-1, 0, 1, 0, -1};
    void dfs(vector<vector<char>>& board, int i, int j){
        int m = board.size();
        int n = board[0].size();
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] == 'X' || board[i][j] == 'A'){
            return;
        }

        board[i][j] = 'A';

        int x, y;
        for(int k = 0; k < 4; k++){
            x = i + direction[k];
            y = j + direction[k + 1];
            dfs(board, x, y);
        }
    }


    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }

        for(int i = 0; i < n; i++){
            dfs(board, 0, i);
            dfs(board, m - 1, i);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'A'){
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }

    }
};

//方法二：BFS
//思路：和上面一样，不过换成了用BFS实现
class Solution {
public:
    vector<int> direction{-1, 0, 1, 0, -1};
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O'){
                q.push({i, 0});
            }
            if(board[i][n-1] == 'O'){
                q.push({i, n-1});
            }
        }

        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O'){
                q.push({0, i});
            }
            if(board[m-1][i] == 'O'){
                q.push({m-1, i});
            }
        }

        while(!q.empty()){
            auto [k, c] = q.front();
            q.pop();
            board[k][c] = 'A';
            int x, y;
            for(int l = 0; l < 4; l++){
                x = k + direction[l];
                y = c + direction[l + 1];
                if(x < 0 || y < 0 || x >= m || y >= n){
                    continue;
                }
                if(board[x][y] == 'O'){
                    board[x][y] = 'A';
                    q.push({x, y});
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'A'){
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
