/*
 * 给你一个字符串 s ，逐个翻转字符串中的所有 单词 。
 * 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
 * 请你返回一个翻转 s 中单词顺序并用单个空格相连的字符串。
 * 说明：
 * 输入字符串 s 可以在前面、后面或者单词间包含多余的空格。
 * 翻转后单词间应当仅用一个空格分隔。
 * 翻转后的字符串中不应包含额外的空格。
 */
//方法一：双指针
//思路：通过双指针从后开始找单词
class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int r = s.size() - 1;
        while(r >= 0){
            if(s[r] == ' '){
                --r;
                continue;
            }
            int l = r;
            while(l >= 0 && s[l] != ' '){
                --l;
            }
            ans += s.substr(l + 1, r - l);
            ans += ' ';
            r = l;
        }
        ans.pop_back();
        return ans;
    }
};

//方法二：代码随想录双指针
//思路：先将多余的空格去掉，然后反转整个字符串，之后再逐一反转单词
class Solution {
public:
    void MySwap(string &s, int l, int r){
        while(l < r){
            swap(s[l], s[r]);
            ++l;
            --r;
        }
    }

    void DelBlank(string &s){
        int fast = 0, slow = 0;
        while(fast < s.size() && s[fast] == ' '){
            ++fast;
        }

        for(; fast < s.size(); fast++){
            if(fast > 0 && s[fast - 1] == s[fast] && s[fast] == ' '){
                continue;
            }

            s[slow++] = s[fast];
        }

        if(slow > 0 && s[slow-1] == ' '){
            s.resize(slow-1);
        }
        else{
            s.resize(slow);
        }
    }

    string reverseWords(string s) {
        DelBlank(s);
        MySwap(s, 0, s.size() - 1);
        int start = 0, end = 0;
        bool entry = false;
        for(int i = 0; i < s.size(); i++){
            if(!entry){
                start = i;
                entry = true;
            }

            if(entry && s[i] == ' '){
                end = i - 1;
                entry = false;
                MySwap(s, start, end);
            }

            if(i == s.size() - 1){
                end = i;
                MySwap(s, start, end);
            }
        }
        return s;
    }
};

//稍微有点修改
class Solution {
public:
    void MySwap(string &s, int l, int r){
        while(l < r){
            swap(s[l], s[r]);
            ++l;
            --r;
        }
    }

    void DelBlank(string &s){
        int fast = 0, slow = 0;
        while(s.size() > 0 && fast < s.size() && s[fast] == ' '){
            ++fast;
        }

        for(; fast < s.size(); fast++){
            if(fast > 0 && s[fast - 1] == s[fast] && s[fast] == ' '){
                continue;
            }

            s[slow++] = s[fast];
        }

        if(slow > 0 && s[slow-1] == ' '){
            s.resize(slow-1);
        }
        else{
            s.resize(slow);
        }
    }

    string reverseWords(string s) {
        DelBlank(s);
        MySwap(s, 0, s.size() - 1);
        int start = 0, end = 0;
        bool entry = false;
        for(int i = 0; i < s.size(); i++){
            if(!entry){
                start = i;
                entry = true;
            }

            if(entry && s[i] == ' '){
                end = i - 1;
                entry = false;
                MySwap(s, start, end);
            }

            if(entry && i == s.size() - 1 && s[i] != ' '){
                end = i;
                entry = false;
                MySwap(s, start, end);
            }
        }
        return s;
    }
};
