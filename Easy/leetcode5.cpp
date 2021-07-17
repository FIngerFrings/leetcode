/* 给你一个字符串 s，找到 s 中最长的回文子串。 */
//方法一：暴力
//思路：找出所有子串，判断是否是回文串，并返回其中长度最长的回文子串
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int m = 0;
        string ans = "";
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= n - i; j++){
                string temp = s.substr(i, j);
                reverse(temp.begin(), temp.end());
                if(temp == s.substr(i, j) && temp.size() > m){
                    ans = s.substr(i, j);
                    m = temp.size();
                }
            }
        }
        return ans;
    }
};

//方法二：manacher算法
//思路：思路太多在这里就不写了
//详细见官方解答
//下面是自己写的解法，但是觉得不够好
class Solution {
public:
    string longestPalindrome(string s) {
        string t = "$#";
        for(char c : s){
            t += c;
            t += '#';
        }
        int n = t.size();
        t += '!';

        int imax = 0; 
        int rmax = 0;
        string ans = "";
        vector<int> f(n);
        for(int i = 1; i < n; i++){
            f[i] = (i <= rmax) ? min(rmax - i + 1 , f[2 * imax - i]) : 1;
            while(t[i + f[i]] == t[i - f[i]])   ++f[i];
            if(i + f[i] - 1 > rmax){
                imax = i;
                rmax = i + f[i] - 1;
            }
        }
        imax = max_element(f.begin(), f.end()) - f.begin();
        rmax = f[imax];
        for(int i = imax - rmax + 1; i <= imax + rmax - 1; i++){
            if(t[i] != '#'){
                ans += t[i];
            }
        }
        return ans;
        
    }
};

//同样是manacher算法，但是我觉得比上面的代码好一些
//官方解法也就那样吧
class Solution {
public:
    string longestPalindrome(string s) {
        string t = "$#";
        for(char c : s){
            t += c;
            t += '#';
        }
        int n = t.size();
        t += '!';

        int imax = 0; 
        int rmax = 0;
        string ans = "";
        vector<int> f(n);
        int m = 0;
        string temp = "";
        for(int i = 1; i < n; i++){
            f[i] = (i <= rmax) ? min(rmax - i + 1 , f[2 * imax - i]) : 1;
            while(t[i + f[i]] == t[i - f[i]])   ++f[i];
            if(i + f[i] - 1 > rmax){
                imax = i;
                rmax = i + f[i] - 1;
            }
            if(f[i] > m){
                temp = t.substr(i - f[i] + 1, 2 * f[i] - 1);
                m = f[i];
            }
        }
        for(char c : temp){
            if(c != '#'){
                ans += c;
            }
        }
        return ans;
        
    }
};

//方法二：动态规划
//思路：状态方程为dp[i][j] = dp[i+1][j-1] && s[i] == s[j]
//详细见官方解答
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n < 2)   return s;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }

        int mlen = 1;
        int begin = 0;
        //要注意迭代的顺序，如果按照正常动态规划的顺序，那么dp[i+1][j-1]会在dp[i][j]之后出现
        //所以应该先从长度短到长的顺序动态规划
        for(int L = 2; L <= n; L++){
            for(int i = 0; i < n; i++){
                int j = i + L - 1;
                if(j >= n)  break;

                if(s[i] != s[j]){
                    dp[i][j] = false;
                }
                else{
                    if(j - i < 3){
                        dp[i][j] = true;
                    }
                    else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                }

                if(dp[i][j] && j - i + 1 > mlen){
                    mlen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, mlen);
    }
};

//方法三：中心扩展
//思想：遍历s，以每个字符作为回文中心，找出其中最长的回文子串
//注意要考虑回文子串长度为奇数和偶数两种情况
class Solution {
public:
    pair<int, int> getlr(string s, int l, int r){
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            --l;
            ++r;
        }
        return {l + 1, r - 1};
    }

    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;
        for(int i = 0; i < s.size(); i++){
            auto [left1, right1] = getlr(s, i, i);
            auto [left2, right2] = getlr(s, i, i + 1);
            if(right1 - left1 > end - start){
                end = right1;
                start = left1;
            }

            if(right2 - left2 > end - start){
                end = right2;
                start = left2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
