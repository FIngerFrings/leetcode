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
