/* 
 * 给定一个三角形 triangle ，找出自顶向下的最小路径和。
 * 每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。
 * 也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。
 */
//方法一：动态规划
//思路：根据求解动态规划问题的步骤，首先要分割问题，我们可以看到，题目要求从顶到底的最短路径和
//而三角形中从顶点到其他点[i][j]的最短路径和实际上是从顶点到[i-1][j]和到[i-1][j-1]的最短路径和中的较小值加上[i][j]的值
//以上考虑的是从上往下，但是对于边缘的元素，例如[i][0]和[i][i+1]这两个元素，只能从[i-1][0]和[i-1][i]到达，因此考虑从下到上会比较好，这样每行中的每个点都可以做相同的运算
//以上就将问题分割并定义了状态，根据上面的思路，我们可以创建一个二维数组存放每个点的最短路径和，这样[0][0]就是我们所要求的最短路径和，以下为代码
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> ans(n);
        for(int i = n-1; i >= 0; i--){
            ans[i].resize(i+1);
            if(i == n-1){
                for(int j = 0; j < n; j++){
                    ans[i][j] = triangle[i][j];
                }
            }
            else{
                for(int j = 0; j < i+1; j++){
                    ans[i][j] = min(ans[i+1][j], ans[i+1][j+1]) + triangle[i][j];
                }
            }
        }
        return ans[0][0];
    }
};

//下面的方法是官方解法，是从上往下的，上面已经分析过了，从下往上会比较好
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> f(n, vector<int>(n));     //这样的初始化方式一开始是没想到的
        f[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
          //可以看到，对于同一行中不同的点，做法是不同的
            f[i][0] = f[i - 1][0] + triangle[i][0];
            for (int j = 1; j < i; ++j) {
                f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + triangle[i][j];
            }
            f[i][i] = f[i - 1][i - 1] + triangle[i][i];
        }
      //最后还需要一个函数才能求出其中的最小值
        return *min_element(f[n - 1].begin(), f[n - 1].end());
    }
};


//下面的方法使用的空间较少，因为第i行的元素值只与i-1行有关（实际上并不是，只是我们直接将最小路径和存放在了相应位置，因此不用再去看i-1行之前的元素了）
//因此可以只用两行数组存放数据
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> f(2, vector<int>(n));
        f[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            int curr = i % 2;
            int prev = 1 - curr;
            f[curr][0] = f[prev][0] + triangle[i][0];
            for (int j = 1; j < i; ++j) {
                f[curr][j] = min(f[prev][j - 1], f[prev][j]) + triangle[i][j];
            }
            f[curr][i] = f[prev][i - 1] + triangle[i][i];
        }
        return *min_element(f[(n - 1) % 2].begin(), f[(n - 1) % 2].end());
    }
};

//下面是只需要一行数组的方法
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> f(n);
        f[0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            f[i] = f[i - 1] + triangle[i][i];
            for (int j = i - 1; j > 0; --j) {
                f[j] = min(f[j - 1], f[j]) + triangle[i][j];
            }
            f[0] += triangle[i][0];
        }
        return *min_element(f.begin(), f.end());
    }
};

//只有一层数组，且是从下到上的做法，应该是这几个解法中最好的了
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.back());
        for(int i = triangle.size() - 2; i >= 0; i --)
            for(int j = 0; j <= i; j ++)
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
        return dp[0];
    }
};
