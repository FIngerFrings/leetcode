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

//其实只需要两次for循环即可
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())    return false;
        vector<int> nums(26, 0);
        for(int i = 0; i < s.size(); i++){
            nums[s[i] - 'a'] += 1;
            nums[t[i] - 'a'] -= 1;
        }
        for(int i = 0; i < 26; i++){
            if(nums[i]){
                return false;
            }
        }
        return true;
    }
};

//其实我觉得官方的暴力解法更好，其实也和上面差不多，都是两个for循环
//官方的是在遍历t的时候，就判断是否有元素的个数小于0
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())    return false;
        unordered_map<char, int> hash;
        for(int i = 0; i < s.size(); i++){
            hash[s[i]] += 1;
        }

        for(int i = 0; i < s.size(); i++){
            hash[t[i]] -= 1;
            if(hash[t[i]] < 0){
                return false;
            }
        }
        return true;
    }
};

//方法二：排序
//思路：可以对两个字符串排序，如果相等则说明两个字符串符合条件
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())    return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
