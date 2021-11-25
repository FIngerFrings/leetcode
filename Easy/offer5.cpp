/* 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。 */
//方法一：遍历字符串？？？
//思路：遍历字符串，遇到空格变成%20，官方解法原理差不多
class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        for(char c : s){
            if(c == ' '){
                ans += "%20";
            }
            else{
                ans += c;
            }
        }
        return ans;
    }
};

//方法二：双指针
//思路：先计算字符串中有多少空格，然后扩展字符串大小，并设定两个指针，分别指向原来字符串的末尾以及扩充后字符串的末尾，然后同时移动两个字符串
class Solution {
public:
    string replaceSpace(string s) {
        int oldSize = s.size();
        int count = 0;
        for(char c : s){
            if(c == ' '){
                ++count;
            }
        }

        if(count == 0){
            return s;
        }

        int newSize = oldSize + (2 * count);
        s.resize(newSize);
        for(int i = newSize - 1, j = oldSize - 1; j < i; j--, i--){
            if(s[j] != ' '){
                s[i] = s[j];
            }
            else{
                s[i--] = '0';
                s[i--] = '2';
                s[i] = '%';
            }
        }
        return s;
    }
};
