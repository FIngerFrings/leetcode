/* 
 * 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
 * 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
 */
//方法一：暴力
//思路：求出所有子串，判断是否是回文串
class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = 1; j <= s.size() - i; j++){
                string temp = s.substr(i, j);
                reverse(temp.begin(), temp.end());
                if(s.substr(i, j) == temp){
                    ++ans;
                }                
            }
        }
        return ans;
    }
};

//方法二：中心扩展
//思路：可以遍历s，将其中的每个字符作为回文子串的中心
//定义两个指针，分别向两边扩展，如果相等则表示是一个回文子串，之后继续向两边扩展，直到不相等
//核心的问题就是回文子串的长度可能为奇数也可能为偶数，奇数情况中心字符是一个字符，而偶数情况是两个字符
//奇数情况则初始值l和r在同一个字符，偶数情况就分别为两个相邻的字符
class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            count += extendSubstrings(s, i, i);
            count += extendSubstrings(s, i, i + 1);
        }
        return count;
    }

    int extendSubstrings(string s, int l, int r){
        int count = 0;
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            --l;
            ++r;
            ++count;
        }
        return count;
    }
};

//上面的做法中使用了两次循环，下面的做法只需要1次循环，因为这里放不了图
//所以详细解释看官方
class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        for(int i = 0; i < 2 * n - 1; i++){
            int l = i / 2;
            int r = i / 2 + i % 2;
            while(l >= 0 && r < n && s[l] == s[r]){
                --l;
                ++r;
                ++count;
            }
        }
        return count;
    }
};

//方法三：manacher算法
//思路：该算法的实质是计算以每个字符为中心的回文子串长度
//不过就像上面一种算法中说到的，回文串分为奇数和偶数两种情况，这两种情况的中文不同，我们可以在字符串的每个字符中间以及开头和结尾添加#
//然后计算每个字符的最大回文半径，这样就可以包含两种情况的回文半径了
//计算出回文半径后，回文半径/2就是这个中心所包含的回文串个数了（证明这里就不写了）
//接下来就是详细的manacher算法，我们在遍历字符串的时候，还需要维护当前所能到达的最远回文串距离，
//如果当前遍历的字符在这个最大回文串中，那么其回文半径至少的长度有两种情况，一种是以最大回文半径对应的回文中心为中心的另一边的点的回文半径
//另一种情况就是最大回文半径 - i + 1，选出其中较小的值作为当前回文中心的回文半径初始值，如果当前点不在最大回文半径中，则将其半径初始化为1
//之后分别向两边扩展，扩展的方法就是增大回文半径，直到不相等
//这样相比较上面的方法实际上只是减少了需要计算的次数
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        string t = "$#";
        for(auto c : s){
            t += c;
            t += '#';
        }
        n = t.size();
        t += '!';

        int ans = 0;
        int imax = 0;
        int rmax = 0;
        vector<int> f(n);
        for(int i = 1; i < n; i++){
            f[i] = (i <= rmax) ? min(rmax - i + 1, f[2 * imax - i]) : 1;
            while(t[i + f[i]] == t[i - f[i]])   ++f[i];
            if(i + f[i] - 1 > rmax){
                imax = i;
                rmax = i + f[i] - 1;
            }
            ans += (f[i] / 2);
        }
        return ans;
    }
};
