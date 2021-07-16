/*
 * 给定两个字符串 s 和 t，判断它们是否是同构的。
 * 如果 s 中的字符可以按某种映射关系替换得到 t  ，那么这两个字符串是同构的。
 * 每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。
 */
//方法一：暴力
//思路：是用哈希表记录映射关系
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())    return false;
        unordered_map<char, char> hash;
        for(int i = 0; i < s.size(); i++){
            if(hash.count(s[i])){
                if(hash[s[i]] != t[i]){
                    return false;
                }
            }
            else{
                for(auto [c, k] : hash){
                    if(k == t[i]){
                        return false;
                    }
                }
                hash[s[i]] = t[i];
            }
        }
        return true;
    }
};

//官方解法同样是是用哈希表，但是使用了两个哈希表，分别表示s到t的映射和t到s的映射
//这样就不需要在每次添加新元素之前都遍历一遍哈希表
//但是相应的消耗空间更多了
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())    return false;
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;

        for(int i = 0; i < s.size(); i++){
            if(s2t.count(s[i])){
                if(s2t[s[i]] != t[i]){
                    return false;
                }
            }
            else{
                if(t2s.count(t[i])){
                    return false;
                }
                else{
                    s2t[s[i]] = t[i];
                    t2s[t[i]] = s[i];
                }
            }
        }
        return true;
    }
};
