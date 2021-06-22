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
//皇后的走法是：可以横直斜走，格数不限。因此要求皇后彼此之间不能相互攻击，等价于要求任何两个皇后都不能在同一行、同一列以及同一条斜线上。
//直观的做法是暴力枚举将N个皇后放置在 N×N 的棋盘上的所有可能的情况，并对每一种情况判断是否满足皇后彼此之间不相互攻击。
//暴力枚举的时间复杂度是非常高的，因此必须利用限制条件加以优化。
//显然，每个皇后必须位于不同行和不同列，因此将 N 个皇后放置在 N×N 的棋盘上，一定是每一行有且仅有一个皇后，每一列有且仅有一个皇后，
//且任何两个皇后都不能在同一条斜线上。基于上述发现，可以通过回溯的方式寻找可能的解。
//回溯的具体做法是：使用一个数组记录每行放置的皇后的列下标，依次在每一行放置一个皇后。
//每次新放置的皇后都不能和已经放置的皇后之间有攻击：即新放置的皇后不能和任何一个已经放置的皇后在同一列以及同一条斜线上，
//并更新数组中的当前行的皇后列下标。当 NN 个皇后都放置完毕，则找到一个可能的解。
//由于每个皇后必须位于不同列，因此已经放置的皇后所在的列不能放置别的皇后。
//第一个皇后有 N 列可以选择，第二个皇后最多有 N-1 列可以选择，第三个皇后最多有 N-2 列可以选择（如果考虑到不能在同一条斜线上，可能的选择数量更少），
//因此所有可能的情况不会超过 N! 种，遍历这些情况的时间复杂度是 O(N!)。

