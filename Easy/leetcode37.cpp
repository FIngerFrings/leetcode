/* 
 * 编写一个程序，通过填充空格来解决数独问题。
 * 数独的解法需 遵循如下规则：
 * 数字 1-9  在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3  宫内只能出现一次。（请参考示例图）
 * 数独部分空格内已填入了数字，空白格用 '.'表示。
 */
//方法一：回溯法
//思路：其实核心思路就是回溯的思路，依次使，试到正确为止
//关键就在于要将每行和每列以及3×3方格中出现的数字记录下来
class Solution {
public:
    vector<vector<bool>> row;
    vector<vector<bool>> col;
    vector<vector<vector<bool>>> nine;
    vector<pair<int, int>> q;
    bool find = false;

    void dfs(vector<vector<char>>& board, int curr){
        if(curr == q.size()){
            find = true;
            return;
        }

        auto [k, c] = q[curr];
        for(int i = 1; i <= 9 && !find; i++){
            if(row[k][i-1] || col[c][i-1] || nine[k/3][c/3][i-1]){
                continue;
            }
            board[k][c] = i + '0';
            row[k][i-1] = true;
            col[c][i-1] = true;
            nine[k/3][c/3][i-1] = true;
            dfs(board, curr + 1);
            row[k][i-1] = false;
            col[c][i-1] = false;
            nine[k/3][c/3][i-1] = false;
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        row.resize(9, vector<bool>(9, false));
        col.resize(9, vector<bool>(9, false));
        nine.resize(3, vector<vector<bool>>(3, vector<bool>(9, false)));
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    q.push_back({i, j});
                }
                else{
                    int digit = board[i][j] - '1';
                    row[i][digit] = true;
                    col[j][digit] = true;
                    nine[i/3][j/3][digit] = true;
                }
            }
        }

        dfs(board, 0);

        
    }
};

//代码随想录回溯
class Solution {
    bool isValid(int r, int c, char k, vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            if(board[r][i] == k){
                return false;
            }
        }

        for(int i = 0; i < 9; i++){
            if(board[i][c] == k){
                return false;
            }
        }

        int sr = (r / 3) * 3;
        int sc = (c / 3) * 3;
        for(int i = sr; i < sr + 3; i++){
            for(int j = sc; j < sc + 3; j++){
                if(board[i][j] == k){
                    return false;
                }
            }
        }
        return true;
    }

    bool backtracking(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    continue;
                }

                for(char k = '1'; k <= '9'; k++){
                    if(isValid(i, j, k, board)){
                        board[i][j] = k;
                        if(backtracking(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }


public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};
