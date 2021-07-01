/*
 * 给出 n 个数对。 在每一个数对中，第一个数字总是比第二个数字小。
 * 现在，我们定义一种跟随关系，当且仅当 b < c 时，数对(c, d) 才可以跟在 (a, b) 后面。我们用这种形式来构造一个数对链。
 * 给定一个数对集合，找出能够形成的最长数对链的长度。你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。
 */
//方法一：贪心
//思路:这道题的思路和之前一道题很像，把这个数对看成是区间，找出所有没有重合的区间的最长个数
//为了给其他区间留更大的空间，我们应该优先选择右端最小的区间，然后再去选择和它没有重合同时右端最小的区间，重复这一过程直到遍历所有区间
//两个区间没有重合是右边区间的左端大于左边区间的右端
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        if(n == 1) return 1;
        sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1]; 
        });
        int len = 1;
        int minr = pairs[0][1];
        for(int i = 1; i < n; i++){
            if(pairs[i][0] <= minr){
                continue;
            }
            ++len;
            minr = pairs[i][1];
        }
        return len;
    }
};
//方法二：动态规划
//思路：同样先把pairs进行排序，不过是按区间的左端大小进行排序
//dp[i]表示以pairs[i]结尾的最长数对链长度，先遍历所有pairs[i]前面且区间右端比pairs[i]左端小的区间，选择其中最大的dp，dp[i]为最大值+1
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        if(n == 1)  return 1;
        sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0] < b[0];
        });
        vector<int> dp(n, 1);
        dp[0] = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(pairs[i][0] > pairs[j][1]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }

        return dp[n-1];
    }
};
