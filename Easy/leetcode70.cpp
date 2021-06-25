/*
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？ 
 */
//方法一：动态规划
//思路：整个动态规划分为四个步骤
//我们到达第 n 个楼梯可以从第 n – 1 个楼梯和第 n – 2 个楼梯到达，因此第 n 个问题可以拆解成第 n – 1 个问题和第 n – 2 个问题，第 n – 1 个问题和第 n – 2 个问题又可以继续往下拆，
//直到第 0 个问题，也就是第 0 个楼梯 (起点)
//接下来是状态定义，第 n 个楼梯会和第 n – 1 和第 n – 2 个楼梯有关联，那么具体的联系是什么呢？
//你可以这样思考，第 n – 1 个问题里面的答案其实是从起点到达第 n – 1 个楼梯的路径总数，n – 2 同理，从第 n – 1 个楼梯可以到达第 n 个楼梯，从第 n – 2 也可以，
//并且路径没有重复，因此我们可以把第 i 个状态定义为 “从起点到达第 i 个楼梯的路径总数”，状态之间的联系其实是相加的关系。
//第三步是递推方程，“状态定义” 中我们已经定义好了状态，也知道第 i 个状态可以由第 i – 1 个状态和第 i – 2 个状态通过相加得到，因此递推方程就出来了 dp[i] = dp[i - 1] + dp[i - 2]
//接下来就是实现
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        if(n == 1 || n == 2){
            return n;
        }
        dp[0] = 0;  //dp[0]为1和0都行
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i < n + 1; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

//上面的方法需要使用一个长度为n+1的数组来保存前面阶数楼梯的方法
//但是实际上我们后面的数量并不依靠前面的数量，因此只需要2个变量来保存数量即可
class Solution {
public:
    int climbStairs(int n) {
        if(n < 3)   return n;
        int r = 1, c = 2, temp;
        for(int i = 3; i <= n; i++){
            temp = r + c;
            r = c;
            c = temp;
        }
        return c;
    }
};

//方法二：矩阵快速幂
//思路：看解答
class Solution {
public:
    vector<vector<long long>> multiply(vector<vector<long long>> &a, vector<vector<long long>> &b) {
        vector<vector<long long>> c(2, vector<long long>(2));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }
        return c;
    }

    vector<vector<long long>> matrixPow(vector<vector<long long>> a, int n) {
        vector<vector<long long>> ret = {{1, 0}, {0, 1}};
        while (n > 0) {
            if ((n & 1) == 1) {
                ret = multiply(ret, a);
            }
            n >>= 1;
            a = multiply(a, a);
        }
        return ret;
    }

    int climbStairs(int n) {
        vector<vector<long long>> ret = {{1, 1}, {1, 0}};
        vector<vector<long long>> res = matrixPow(ret, n);
        return res[0][0];
    }
};

