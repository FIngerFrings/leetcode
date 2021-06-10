/* 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。 */
//方法一：双指针
//思路：以下是自己实现的双指针，首先一个指针指向头，一个指针指向尾
//如果有某前后两个字符不同，则计数器+1，并进入递归判断子串是否是回文串，要判断两个子串，只要有一个是回文串即可
class Solution {
public:
    int num = 0;
    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        while(l <= r){
            if(s[l] == s[r]){
                ++l;
                --r;
            }
            else{
                ++num;
                if(num > 1) return false;
                if(validPalindrome(s.substr(l, r - l)) || validPalindrome(s.substr(l+1, r - l))){
                    return true;
                }
            }
        }
        return true;
    }
};

//官方解法，思路和我的差不多，遇到不相同的则判断子串是否是回文串，只要有一个子串是回文串，则返回会true
class Solution {
public:
    bool checkPalindrome(const string& s, int low, int high) {
        for (int i = low, j = high; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int low = 0, high = s.size() - 1;
        while (low < high) {
            char c1 = s[low], c2 = s[high];
            if (c1 == c2) {
                ++low;
                --high;
            } else {
                return checkPalindrome(s, low, high - 1) || checkPalindrome(s, low + 1, high);
            }
        }
        return true;
    }
};
