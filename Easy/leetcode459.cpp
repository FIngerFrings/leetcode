/* 给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。 */
//方法一：KMP
//思路：利用next数组
class Solution {
public:
    void getNext(vector<int> &next, string t){
        int j = 0;
        next[0] = j;
        for(int i = 1; i < t.size(); i++){
            while(j > 0 && t[i] != t[j]){
                j = next[j-1];
            }

            if(t[i] == t[j]){
                ++j;
            }

            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        if(len == 0){
            return false;
        }
        vector<int> next(len);
        getNext(next, s);
        if(next[len - 1] != 0 && (len % (len - next[len - 1]) == 0)){
            return true;
        }
        return false;
    }
};
