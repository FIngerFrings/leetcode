/*
 * 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
 * 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
 */
//方法一：哈希表
//思路：先把s中的所有单词取出来，然后依次对应pattern中的字母
//使用哈希表记录对应关系
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int pre = 0;
        vector<string> words;
        int i;
        for(i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                string word = s.substr(pre, i - pre);
                words.push_back(word);
                pre = i + 1;
            }
        }
        words.push_back(s.substr(pre, i - pre));
        int num = words.size();
        if(pattern.size() != num)    return false;
        unordered_map<string, char> s2p;
        unordered_map<char, string> p2s;
        for(int j = 0; j < num; j++){
            char temp = pattern[j];
            if(s2p.count(words[j])){
                if(s2p[words[j]] != temp){
                    return false;
                }
            }
            else{
                if(p2s.count(temp)){
                    return false;
                }
                else{
                    s2p[words[j]] = temp;
                    p2s[temp] = words[j];
                }
            }
        }
        return true;
    }
};

//官方的解法，思想其实和我的相同，但是代码实现起来不同
//它是遍历pattern（理论上确实遍历pattern会比较好，因为pattern数量比较少）
//然后再去s中遍历
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> s2p;
        unordered_map<char, string> p2s;
        int pre = 0;
        int n = s.size();
        for(auto c : pattern){
            //这个判断是为了当pattern中字符的个数大于s中单词的个数的情况
            if(pre >= n){
                return false;
            }
            int curr = pre;
            while(curr < n && s[curr] != ' ')   ++curr;
            string temp = s.substr(pre, curr - pre);
            if(s2p.count(temp) && s2p[temp] != c)   return false;
            if(p2s.count(c) && p2s[c] != temp)  return false;
            s2p[temp] = c;
            p2s[c] = temp;
            pre = curr + 1;
        }
        //最后判断pre>=n是为了判断n是为了当s中单词个数大于pre中字符个数的情况
        return pre >= n;
    }
};
