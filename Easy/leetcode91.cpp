/*
 * 题目有点复杂，自己去看去
 */
//方法一：动态规划
//思路：遍历字符串，在遍历的过程中将每个字符看成是最后一个字符并确定有多少种解法
//当遍历到i位时，无非就三种情况，一种是s[i]=0，此时需要判断是否合理，即如果s[i-1]=0或者大于2，则不合理，返回0
//否则此时的情况和i-2结尾的情况一样，因为s[i-1]和s[i]需要组合在一起
//第二种情况就是s[i]不为0，但是s[i-1]为0，此时不能将s[i]和s[i-1]组合在一起，所以这种情况和以i-1结尾的情况一样
//第三种情况就是正常情况，此时数量为以i-1结尾的数量加上以i-2结尾的数量
//下面是具体的实现，但是我写的比较繁琐，使用if比较多
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0')    return 0;
        int n = s.size();
        if(n == 1)  return 1;
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            int num = (s[i-2] - '0') * 10 + (s[i-1] - '0');
            if(s[i-1] == '0'){
                if(s[i-2] == '0' || s[i-2] > '2'){
                    return 0;
                }
                dp[i] = dp[i-2];
            }
            else if(s[i-2] == '0'){
                dp[i] = dp[i-1];
            }
            else{
                if(num > 26){
                    dp[i] = dp[i-1];
                }
                else{
                    dp[i] = dp[i-1] + dp[i-2];
                }
            }
        }
        return dp[n];
    }
};

//官方的动态规划，比较简洁，强
//直接从首个元素开始，原理其实和上面一样，就不做过多简介
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] != '0') {
                f[i] += f[i - 1];
            }
            if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)) {
                f[i] += f[i - 2];
            }
        }
        return f[n];
    }
};
