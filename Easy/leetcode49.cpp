/*
 * 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
 * 字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母都恰好只用一次。
 */
//方法一：排序
//思路：将所有字符串排序，异位词排序后的结果应该是相同的，将排序后的字符串作为键，字符串数组作为值，对于排序后相同的字符串，将其插入到相同的字符串数组中
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for(string &str : strs){
            string key = str;
            sort(key.begin(), key.end());
            hash[key].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto it : hash){
            ans.push_back(it.second);
        }
        return ans;
    }
};
