/*
 *给定两个字符串 s 和 t，它们只包含小写字母。
 *字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
 *请找出在 t 中被添加的字母。
*/
//方法一，计数，通过初始化一个vector容器，最大容量为26，默认值为1，然后对s进行遍历，将对应的vector+1，之后再对t遍历，将对应的vector-1，如果小于0，说明是多出来的
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> p(26, 0); //vector的初始化，设定最大容量，并均初始化为0
        for(int i = 0; i < s.size(); i++){
            p[s[i] - 'a']++;    //s[i]-'a'可以得到字母在字母表中的位置
        }
        for(int i = 0; i < t.size(); i++){
            p[t[i] - 'a']--;
            if(p[t[i] - 'a'] < 0){
                return t[i];
            }
        }
        return ' ';
        
    }
};

//方法二：求和，通过将s的字符串求和以及t的字符串求和，然后相减可以得到重复的字符
class Solution {
public:
    char findTheDifference(string s, string t) {
        int as = 0, at = 0;
        for(int i = 0; i < s.size(); i++){
            as += s[i];
        }
        for(char ch : t){
            at += ch;
        }
        return at - as;
    }
};

//方法三：位运算不是特别懂
