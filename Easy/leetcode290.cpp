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
