/* 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。*/
//方法一：动态规划
//思路：对于一个正整数n，首先可以将其拆分成两个正整数的和，设其中第一个数为j，则另一个数为n-j，对于n-j，你可以选择继续拆，也可以选择不拆
//如果选择不拆分，则对应的乘积为j*(n-j)，如果选择继续拆分，则对应的乘积为j*dp[n-j]，其中dp数组存放一个数拆分后所能得到的最大乘积
//因此动态规划的状态方程就得到了
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        for(int i = 2; i <= n; i++){
            int currmax = 0;
            for(int j = 1; j < i; j++){
                currmax = max(currmax, max((i-j)*j, j*dp[i-j]));
            }
            dp[i] = currmax;
        }
        return dp[n];
    }
};
