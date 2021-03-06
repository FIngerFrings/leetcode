/* leetcode74 搜索二维矩阵 */
/* 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
 * 每行中的整数从左到右按升序排列。
 * 每行的第一个整数大于前一行的最后一个整数。
 */
//方法1：暴力解法
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
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

//方法二，使用二分查找，官方解法，下面的方法是使用两次二分查找
//因为矩阵是按顺序排列的，所以可以先使用二分查找找出target会在哪一行，然后再在那一行使用二分查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto row = upper_bound(matrix.begin(), matrix.end(), target, [](const int& b, const vector<int> a)->bool{
            return b < a[0];
        });
        if(row == matrix.begin()){
            return false;
        }
        --row;
        return binary_search(row->begin(), row->end(), target);     //需要注意，row是个地址
    }
};

//方法三同样也是使用二分查找，但是这里只需要以此二分查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            int x = matrix[mid/n][mid%n];       //这样的使用方法要记住
            if(x < target){
                l = mid + 1;
            }
            else if(x > target){
                r = mid - 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
