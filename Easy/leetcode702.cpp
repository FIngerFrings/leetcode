/* 
 * 给出一个字符串数组words组成的一本英语词典。从中找出最长的一个单词，该单词是由words词典中其他单词逐步添加一个字母组成。若其中有多个可行的答案，则返回答案中字典序最小的单词。
 * 若无答案，则返回空字符串。
 */
 
//方法一：我觉得属于一种暴力解法
//思路：首先将words排序，这样长度短的就会在前面，然后用set保存字符串（应该也可以用map）
//遍历数组，对于长度为1的字符串，直接插入。对于长度大于1的字符串，判断它的前缀是否在set中，如果不在则不符合条件，否则插入set中。
//同时需要判断当前字符串和res，如果长度大于它，则修改res为当前字符串。如果相等，则判断两个字符串的大小
class Solution {
public:
    string longestWord(vector<string>& words) {
        set<string> q;
        sort(words.begin(), words.end());
        string res = "";    //因为若无答案，则返回空字符串，所以可以先定义一个空字符串去和其他字符串比较
        for(string word : words){
            if(word.size() == 1 || (word.size() > 1 && q.count(word.substr(0, word.size()-1)) == 1)){
                q.insert(word);
                if(res.size() < word.size() || (res.size() == word.size() && res > word)){
                    res = word;
                }
            }
        }
        return res;
    }
};
