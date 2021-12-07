/* 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。*/
//方法一：回溯
//思路：根据回溯法将字符串进行切割，然后判断字符串是否是回文串
class Solution {
    vector<vector<string>> ans;
    vector<string> path;

    bool isPalindrome(string &s, int l, int r){
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }

    void backtracking(string &s, int l){
        if(l >= s.size()){
            ans.push_back(path);
            return;
        }

        for(int i = l; i < s.size(); i++){
            if(isPalindrome(s, l, i)){
                string tmp = s.substr(l, i - l + 1);
                path.push_back(tmp);
            }
            else{
                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();
        }
        return;
    }

public:
    vector<vector<string>> partition(string s) {
        ans.clear();
        path.clear();
        backtracking(s, 0);
        return ans;
    }
};
