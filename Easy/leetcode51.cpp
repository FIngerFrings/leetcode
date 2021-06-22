/* 
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 * 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 */
//方法一：回溯法
//思路：使用回溯法，用3个数组分别记录每列，左斜对角，右斜对角是否已经有皇后
//思路还是回溯法的思路，问题的关键就在于是否直到该从哪里下手
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> t;
    vector<bool> col, ldiag, rdiag;

    void backtrack(int n, int row){
        if(row == n){
            ans.push_back(t);
            return;
        }
        for(int i = 0; i < n; i++){
            if(col[i] || ldiag[row - i + n - 1] || rdiag[row + i]){
                continue;
            }
            t[row][i] = 'Q';
            col[i] = true;
            ldiag[row - i + n - 1] = true;
            rdiag[row + i] = true;
            backtrack(n, row + 1);
            t[row][i] = '.';
            col[i] = false;
            ldiag[row - i + n - 1] = false;
            rdiag[row + i] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        if(n == 0)  return ans;
        t.resize(n, string(n, '.'));
        col.resize(n, false);
        ldiag.resize(2*n-1, false);
        rdiag.resize(2*n-1, false);
        backtrack(n, 0);
        return ans;
    }
};
