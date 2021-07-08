/*
 * 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
 * 每行的元素从左到右升序排列。
 * 每列的元素从上到下升序排列。
 */
//方法一：暴力法（超时）
//思路：略
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == target){
                    return true;
                }
            }
        }
        return false;
    }
};

//方法二：二分查找（超时）
//思路：使用二分查找缩小范围
//下面的方法有些小细节没处理
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m - 1, row = m, col = n;
        while(l <= r){
            int mid = (l + r) / 2;
            if(matrix[mid][0] > target){
                r = mid - 1;
                row = mid;
            }
            else{
                l = mid + 1;
            }
        }

        l = 0;
        r = n - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(matrix[0][mid] > target){
                r = mid - 1;
                col = mid;
            }
            else{
                l = mid + 1;
            }
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == target){
                    return true;
                }
            }
        }
        return false;
        
    }
};

//对每一行二分查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()){
            return false;
        }

        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++){
            int l = 0, r = n - 1, ans = n;
            while(l <= r){
                int mid = (l + r) / 2;
                if(matrix[i][mid] <= target){
                    l = mid + 1;
                    ans = mid;
                }
                else{
                    r = mid - 1;
                }
            }
            //这里需要注意ans是可能溢出的
            if(ans == n){
                continue;
            }
            if(matrix[i][ans] == target){
                return true;
            }
        }
        return false;
    }
};

//从对角线二分查找
class Solution {
public:
    bool binary(vector<vector<int>>& matrix, int target, int i, int m, int n, int v){
        int p = (v == 0) ? n : m;
        int l = i, r = p - 1, ans = p;
        while(l <= r){
            int mid = (l + r) / 2;
            if(v == 0){
                if(matrix[i][mid] <= target){
                    l = mid + 1;
                    ans = mid;
                }
                else{
                    r = mid - 1;
                }
            }
            else{
                if(matrix[mid][i] <= target){
                    l = mid + 1;
                    ans = mid;
                }
                else{
                    r = mid - 1;
                }
            }
        }
        if(ans == p){
            return false;
        }
        else if(v == 0 && matrix[i][ans] == target){
            return true;
        }
        else if(v == 1 && matrix[ans][i] == target){
            return true;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()){
            return false;
        }

        int m = matrix.size();
        int n = matrix[0].size();
        int len = min(m, n);
        for(int i = 0; i < len; i++){
            bool rowfind = binary(matrix, target, i, m, n, 0);
            bool colfind = binary(matrix, target, i, m, n, 1);
            if(rowfind || colfind){
                return true;
            }
        }
        return false;
    }
};

//方法三：巧妙解法
//思路：我们可以从左下角出发，如果当前元素大于target，则上移，小于target就左移，等于直接返回
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()){
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int i = m - 1, j = 0;
        while(i >= 0 && j < n){
            if(matrix[i][j] == target){
                return true;
            }
            else if(matrix[i][j] > target){
                --i;
            }
            else{
                ++j;
            }
        }
        return false;
    }
};

//方法四：递归
//思路：将二维矩阵分成4个小矩阵，使用递归不断减小矩阵大小，最后找到
//具体思路懂了，但是实现还是有点困难
class Solution {
public:
    bool find(vector<vector<int>>& matrix, int target, int t, int d, int l, int r){
        if(l > r || t > d){
            return false;
        }

        if(matrix[t][l] > target || matrix[d][r] < target){
            return false;
        }

        int mid = (l + r) / 2;
        int row = t;
        while(row <= d && matrix[row][mid] <= target){
            if(matrix[row][mid] == target){
                return true;
            }
            ++row;
        }
        return find(matrix, target, row, d, l, mid - 1) || find(matrix, target, t, row - 1, mid + 1, r);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()){
            return false;
        }

        int m = matrix.size();
        int n = matrix[0].size();

        return find(matrix, target, 0, m - 1, 0, n - 1);
    }
};
