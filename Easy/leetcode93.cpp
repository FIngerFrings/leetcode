/*
 * 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
 * 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
 * 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你不能重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
 */
//方法一：回溯
//思路：通过切割字符串然后判断是否符合条件，如果符合条件则加入到ans中
class Solution {
    vector<string> ans;

    bool isValid(const string &s, int l, int r){
        if(l > r)   return false;

        if(s[l] == '0' && l != r)    return false;

        int num = 0;
        for(int i = l; i <= r; i++){
            if(s[i] > '9' || s[i] < '0'){
                return false;
            }

            num = num * 10 + (s[i] - '0');
            if(num > 255)   return false;
        }
        return true;
    }

    void backtracking(string &s, int l, int level){
        if(level == 3){
            if(isValid(s, l, s.size() - 1)){
                ans.push_back(s);
            }
            return;
        }

        for(int i = l; i < s.size(); i++){
            if(isValid(s, l, i)){
                s.insert(s.begin() + i + 1, '.');
                backtracking(s, i + 2, level + 1);
                s.erase(s.begin() + i + 1);
            }
            else{
                break;
            }
        }
        return;
    }

public:
    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        if(s.size() > 12)   return {};
        backtracking(s, 0, 0);
        return ans;
    }
};
