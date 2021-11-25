/*
 * 实现 strStr() 函数。
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。
 */
//方法一：暴力
//思路：略
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())  return 0;
        int m = haystack.size();
        int n = needle.size();
        for(int i = 0; i < m; i++){
            if(m - i < n){
                return -1;
            }
            int k = i;
            int j = 0;
            while(j < n && haystack[k] == needle[j]){
                ++k;
                ++j;
            }
            if(j == n){
                return i;
            }
        }
        return -1;
    }
};

//同样是暴力，但是下面的代码比较好
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        if(n == 0)  return 0;
        for(int i = 0; i + n <= m; i++){
            bool flag = true;
            for(int j = 0; j < n; j++){
                if(haystack[i + j] != needle[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                return i;
            }
        }
        return -1;
    }
};

//方法二：KMP算法
class Solution {
public:
    void getNext(vector<int> &next, string t){
        int j = 0;
        next[0] = j;
        for(int i = 1; i < t.size(); i++){
            while(j > 0 && t[i] != t[j]){
                j = next[j-1];
            }

            if(t[i] == t[j]){
                ++j;
            }
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle) {
        if(needle.size() == 0)   return 0;
        vector<int> next(needle.size());
        int j = 0;
        getNext(next, needle);
        for(int i = 0; i < haystack.size(); i++){
            while(j > 0 && haystack[i] != needle[j]){
                j = next[j-1];
            }

            if(haystack[i] == needle[j]){
                ++j;
            }

            if(j == needle.size()){
                return i - needle.size() + 1;
            }
        }
        return -1;
    }
};
