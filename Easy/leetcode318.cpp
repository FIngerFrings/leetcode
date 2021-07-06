/*
 * 给定一个字符串数组 words，找到 length(word[i]) * length(word[j]) 的最大值，并且这两个单词不含有公共字母。你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。
 */
//方法一：暴力解法
//思路：略
class Solution {
public:
    bool issame(string word1, string word2){
        for(char a : word1){
            for(char b : word2){
                if(a == b){
                    return false;
                }
            }
        }
        return true;
    }

    int maxProduct(vector<string>& words) {
        int maxlen = 0;
        int n = words.size();
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(issame(words[i], words[j])){
                    int len = words[i].size() * words[j].size();
                    maxlen = max(maxlen, len);
                }
            }
        }    
        return maxlen;
    }
};

//方法二：哈希表+位运算
//思路：怎样快速判断两个字母串是否含有重复数字呢？可以为每个字母串建立一个长度为 26 的二进制数字，
//每个位置表示是否存在该字母。如果两个字母串含有重复数字，那它们的二进制表示的按位与不为 0。
//同时，我们可以建立一个哈希表来存储字母串（在数组的位置）到二进制数字的映射关系，方便查找调用
class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> hash;
        int ans = 0;
        for(string word : words){
            int mask = 0;
            int n = word.size();
            for(char c : word){
                mask |= 1 << (c - 'a');
            }
            hash[mask] = max(hash[mask], n);
            for(auto &[h_mask, h_size] : hash){
                if(!(h_mask & mask)){
                    ans = max(ans, h_size * n);
                }
            }
        }
        return ans;
    }
};
