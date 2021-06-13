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
//方法一：暴力枚举（超出时间限制）
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
