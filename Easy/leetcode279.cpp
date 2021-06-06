/* 
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 * 给你一个整数 n ，返回和为 n 的完全平方数的 最少数量 。
 * 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。
 */
//方法一：暴力法
//思路：一个直观的解决方案是使用暴力枚举法，我们枚举所有可能的组合，并找到完全平方数的个数最小的一个。
//整个解法基于以下式子：numSquare(n) = min(numSquare(n-k)+1) k属于square numbers
//不过这个方法会超时。首先就是创建一个数组，里面存放了所有小于n的完全平方数，因为是使用for循环产生的，所以如果n是个完全平方数，则n就是数组最后一个元素
//如果n是个完全平方数，则直接返回1。否则就进入递归。
//对于每一个进入递归的数，都会有一个minnum作为这个数的最小完全平方和，然后遍历square数组中的完全平方数，然后计算n-k的最小完全平方数和，计算所有k得到的结果，选择其中最小的值并+1
//得到的结果就是当前这个数的最小完全平方数和
//下面的程序应该是没毛病的，不过因为超时所以得不到验证
class Solution {
public:
    vector<int> square;
  
    int minSquare(int n){
        int minnum = INT_MAX;
        for(int k : square){
            if(n - k < 0){
                break;
            }
            else if(n == k){
                return 1;
            }
            else{
                minnum = min(minnum, minSquare(n-k));
            }
        }
        return minnum + 1;
    }
  
    int numSquares(int n) {
        for(int i = 1; i * i <= n; i++){
            square.push_back(i*i);
        }
        if(square.back() == n){
            return 1;
        }
        return minSquare(n);
    }
};

//方法二：动态规划
//思路：自己写的动态规划，根据上面的分析已经将问题分割并定义了状态，状态方程就是numSquare(n) = min(numSquare(n-k)+1)
//同样也是先创建一个数组存放1~n的每个元素的最小平方数个数，然后根据状态方程得到当前元素的最小平方和个数
class Solution {
public:
    int numSquares(int n) {
        vector<int> numSquare(n+1);
        numSquare[0] = 0;
        vector<int> square;
        for(int i = 1; i * i <= n; i++){
            square.push_back(i * i);
        }

        for(int i = 1; i <= n; i++){
            int minnum = INT_MAX;
            for(int k : square){
                if(i - k < 0){
                    break;
                }
                else if(i == k){
                    numSquare[i] = 1;
                    break;
                }
                else{
                    minnum = min(minnum, numSquare[i-k]);
                }
            }
            if(numSquare[i] != 1){
                numSquare[i] =  minnum + 1;
            }
        }
        return numSquare[n];
    }
};

//看了官方解法后简化的动态规划，实际上并不需要判断某个元素是否为最小平方和，因为如果它是最小平方和，则肯定会有某个k，使得i-k=0，则dp[i-k]=dp[0]=0
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        vector<int> square;
        for(int i = 1; i * i <= n; i++){
            square.push_back(i * i);
        }

        for(int i = 1; i <= n; i++){
            dp[i] = i;
            for(int k : square){
                if(i - k < 0){
                    break;
                }
                dp[i] = min(dp[i], dp[i-k]+1);
            }
        }
        return dp[n];

    }
};
