/* 
 * 给你一个字符串 s 和一个字符串数组 dictionary 作为字典，找出并返回字典中最长的字符串，该字符串可以通过删除 s 中的某些字符得到。
 * 如果答案不止一个，返回长度最长且字典序最小的字符串。如果答案不存在，则返回空字符串。
 */
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
