/* 
 * 给你一个字符串 s 和一个字符串数组 dictionary 作为字典，找出并返回字典中最长的字符串，该字符串可以通过删除 s 中的某些字符得到。
 * 如果答案不止一个，返回长度最长且字典序最小的字符串。如果答案不存在，则返回空字符串。
 */
//下面是我自己做的，但是没有做出来，只差一步，有时间再做吧
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        unordered_map<char, bool> isOk;
        for(char str : s){
            isOk[str] = true;
        }
        
        int max_size = INT_MIN;
        string ans;
        for(string word : dictionary){
            int pre = -1;
            int n = word.size();
            int curr_size = 0;
            for(char k : word){
                if(isOk[k] && ){
                    
                    ++curr_size;
                }
                else{
                    break;
                }
                if(curr_size == n){
                    if(n > max_size){
                        max_size = n;
                        ans = word;
                    }
                    else if(n == max_size && word < ans){
                        ans = word;
                    }
                }
                
            }
        }
        return ans.empty() ? "" : ans;
    }
};
//方法一：递归枚举（超出时间限制）
//思路：列举出s所能组成的所有字符串，之后遍历dictionary，并选出最长字典序最小的字符串
class Solution {
public:
    unordered_map<string, bool> q;
    void generate(string s, int i, string prev){
        if(i == s.size()){
            q[prev] = true;
            return;
        }
        generate(s, i+1, prev + s[i]);
        generate(s, i+1, prev);
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        generate(s, 0, "");
        int maxsize = 0;    //为什么这里不能用INT_MIN
        string ans = "";
        for(string str : dictionary){
            if(q[str]){
                if(str.size() > maxsize){
                    ans = str;
                    maxsize = str.size();
                }
                else if(str.size() == maxsize && str < ans){
                    ans = str;
                }
            }
        }
        return ans;
    }
};

//方法二：迭代枚举
//思路：和上面相同，也是列出所有s可能的组合，然后再从中寻找，不过这里使用迭代的方法，使用二进制数得到所有组合
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        unordered_map<string, bool> q;
        int n = s.size();
        for(int i = 1; i <= 2^n; i++){
            string k = "";
            for(int j = 0; j < n; j++){
                if(i & s[j]){
                    k += s[j];
                }
            }
            q[k] = true;
        }
        int maxsize = 0;
        string ans = "";
        for(string str : dictionary){
            if(q[str]){
                if(str.size() > maxsize){
                    ans = str;
                    maxsize = str.size();
                }
                else if(str.size() == maxsize && str < ans){
                    ans = str;
                }
            }
        }
        return ans;
    }
};

//方法三：双指针
//思路：首先对字典排序，长度长且字典序小的在前面
//然后依次检查字典中的字符串是否是s的子串，如果是再比较长度和字典序，最后输出最长且字典序最小的字符串
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](const string &a, const string &b){
            return a.size() == b.size() ? a < b : a.size() > b.size();
        });
        string ans = "";
        int maxsize = 0;
        for(string str : dictionary){
            int l = 0, r = 0;
            while(l < str.size() && r < s.size()){
                if(str[l] == s[r]){
                    ++l;
                }
                ++r;
            }
            if(l == str.size()){
                if(str.size() > maxsize){
                    ans = str;
                    maxsize = str.size();
                }
                else if(str.size() == maxsize && str < ans){
                    ans = str;
                }
                
            }
        }
        return ans;
    }
};
//下面方法是不排序的
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        int maxsize = 0;
        for(string str : dictionary){
            int l = 0, r = 0;
            while(l < str.size() && r < s.size()){
                if(str[l] == s[r]){
                    ++l;
                }
                ++r;
            }
            if(l == str.size()){
                if(str.size() > maxsize){
                    ans = str;
                    maxsize = str.size();
                }
                else if(str.size() == maxsize && str < ans){
                    ans = str;
                }
                
            }
        }
        return ans;
    }
};
