/*
 * 最初在一个记事本上只有一个字符 'A'。你每次可以对这个记事本进行两种操作：
 * Copy All (复制全部) : 你可以复制这个记事本中的所有字符(部分的复制是不允许的)。
 * Paste (粘贴) : 你可以粘贴你上一次复制的字符。
 * 给定一个数字 n 。你需要使用最少的操作次数，在记事本中打印出恰好 n 个 'A'。输出能够打印出 n  个 'A' 的最少操作次数。
 */
//方法一:动态规划
//思路：说实话pdf上的思路不是特别懂，但是第二种动态规划的思路还是理解的
class Solution {
public:
    int minSteps(int n) {
        if(n < 2)   return 0;
        vector<int> dp(n+1);
        int h = sqrt(n);
        for(int i = 2; i <= n; i++){
            dp[i] = i;
            for(int j = 2; j <= h; j++){
                if(i % j == 0){
                    dp[i] = dp[j] + dp[i/j];
                }
            }
        }
        return dp[n];

    }
};

//思路：同样是动态规划，对每一个格子i（i个A），如果i可以被j除尽，说明j个A可以通过复制粘贴得到i个A，复制粘贴次数为i / j。
//递推公式：dp[i] = min(dp[i], dp[j] + i / j)
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1);
        for(int i = 2; i <= n; i++){
            dp[i] = i;
            for(int j = 2; j <= i / 2; j++){
                if(i % j == 0){
                    dp[i] = min(dp[i], dp[j] + i/j);
                }
            }
        }
        return dp[n];
    }
};
