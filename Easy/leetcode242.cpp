/*
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
 */

//方法一：暴力
//思路：就记录每个字符串出现字母的次数并进行比较
//这里是用数组来记录
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())    return false;
        vector<int> nums(26, 0);
        for(char c : s){
            ++nums[c - 'a'];
        }
        for(char c : t){
            --nums[c - 'a'];
        }
        for(int t : nums){
            if(t > 0){
                return false;
            }
        }
        return true;
    }
};

//是用哈希表记录出现次数
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())    return false;
        unordered_map<char, int> hash;
        for(char c : s){
            hash[c] += 1;
        }
        for(char c : t){
            hash[c] -= 1;
        }
        for(auto [c, t] : hash){
            if(t != 0){
                return false;
            }
        }
        return true;
    }
};
