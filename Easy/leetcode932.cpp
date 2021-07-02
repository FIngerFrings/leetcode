/*
 * 对于某些固定的 N，如果数组 A 是整数 1, 2, ..., N 组成的排列，使得：
 * 对于每个 i < j，都不存在 k 满足 i < k < j 使得 A[k] * 2 = A[i] + A[j]。
 * 那么数组 A 是漂亮数组。
 * 给定 N，返回任意漂亮数组 A（保证存在一个）。
 */
//方法一：漂亮数组
//思路：首先需要知道如果一个数组是漂亮数组，则它必须满足i < k < j 使得 A[k] * 2 = A[i] + A[j]。
//可以发现表达式左边是一个偶数，所以如果想要让表达式成立，右边可以是一个奇数加上偶数
//其次还需要知道一个性质就是漂亮数组中的元素经过线性变化后仍然是一个漂亮数组
//对于一个正整数 N, 我们将其等分为两部分，left和right， 如果left部分是漂亮数组，right部分也是漂亮数组， 同时left部分全部是奇数，right部分全部是偶数，
//那么此时left + right组成的数组一定也是一个漂亮数组。
class Solution {
public:
    unordered_map<int, vector<int>> dp;
    vector<int> beautifulArray(int n) {
        vector<int> ans(n, 0);
        if(dp.count(n)) return dp[n];
        int t = 0;
        if(n != 1){
            for(auto &x : beautifulArray((n+1)/2)){
                ans[t++] = 2 * x - 1;
            }
            for(auto &x : beautifulArray(n/2)){
                ans[t++] = 2 * x;
            }
        }
        else{
            ans[0] = 1;
        }
        dp[n] = ans;
        return ans;
    }
};

