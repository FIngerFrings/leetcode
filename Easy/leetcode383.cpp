/*
 * 为了不在赎金信中暴露字迹，从杂志上搜索各个需要的字母，组成单词来表达意思。
 * 给你一个赎金信 (ransomNote) 字符串和一个杂志(magazine)字符串，判断 ransomNote 能不能由 magazines 里面的字符构成。
 * 如果可以构成，返回 true ；否则返回 false 。
 * magazine 中的每个字符只能在 ransomNote 中使用一次。
 */
//方法一：哈希表
//思路：略
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mSet;
        for(char c : magazine){
            mSet[c]++;
        }

        for(char c : ransomNote){
            if(--mSet[c] < 0){
                return false;
            }
        }
        return true;

    }
};

//用数组当哈希表
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> words(26);
        for(char c : magazine){
            ++words[c-'a'];
        }

        for(char c : ransomNote){
            if(--words[c-'a'] < 0) return false;
        }
        return true;
    }
};
