/* 
 * 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 */
//方法一：回溯法
//思路：回溯法，不同于排列组合问题，本题采用的并不是修改输出方式，而是修改访问标记。在我们对任意位置进行深度优先搜索时，我们先标记当前位置为已访问，以避免重复遍历（如防止向右搜索后
//又向左返回）；在所有的可能都搜索完成后，再回改当前位置为未访问，防止干扰其它位置搜索到当前位置。使用回溯法，我们可以只对一个二维的访问矩阵进行修改，而不用把每次的搜索状
//态作为一个新对象传入递归函数中
class Solution {
public:
    vector<vector<bool>> visited;
    bool find = false;
    void backtrack(vector<vector<char>>& board, int i, int j, string word, int pos){
        int m = board.size();
        int n = board[0].size();

        if(visited[i][j]){
            return;
        }

        if(pos == word.size() - 1){
            find = true;
            return;
        }

        visited[i][j] = true;

        if(i - 1 >= 0 && board[i-1][j] == word[pos + 1]){
            backtrack(board, i - 1, j, word, pos + 1);
        }
        if(i + 1 < m && board[i+1][j] == word[pos + 1]){
            backtrack(board, i + 1, j, word, pos + 1);
        }
        if(j - 1 >= 0 && board[i][j-1] == word[pos + 1]){
            backtrack(board, i, j - 1, word, pos + 1);
        }
        if(j + 1 < n && board[i][j+1] == word[pos + 1]){
            backtrack(board, i, j + 1, word, pos + 1);
        }

        visited[i][j] = false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) return false;
        int m = board.size();
        int n = board[0].size();
        visited.resize(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(find){
                    return find;
                }
                if(board[i][j] == word[0]){
                    backtrack(board, i, j, word, 0);
                }
            }
        }
        return find;
    }
};
