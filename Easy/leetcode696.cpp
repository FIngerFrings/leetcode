/* 
 * 给定一个字符串 s，计算具有相同数量 0 和 1 的非空（连续）子字符串的数量，并且这些子字符串中的所有 0 和所有 1 都是连续的。
 * 重复出现的子串要计算它们出现的次数。
 */
//方法一：我也不知道应该叫什么方法，中心扩展？？？
//思路：遍历s，在遍历s的过程中，如果发现前后两个字符不同，说明其中1个为0，1个为1
//之后向两边扩展，计算有多少符合条件的子串
class Solution {
public: 
    int getcount(string s, int i){
        int count = 1;
        int l = i, r = i + 1;
        while(l - 1 >= 0 && r + 1 < s.size() && s[l - 1] == s[l] && s[r] == s[r + 1]){
            --l;
            ++r;
            ++count;
        }
        return count;
    }

    int countBinarySubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] != s[i + 1]){
                count += getcount(s, i);
            }
        }
        return count;
    }
};

//方法二：按字符分组
//思路：可以计算每个连续的相同字符的个数，然后最后遍历个数
class Solution {
public:
    int countBinarySubstrings(string s) {
        int ptr = 0;
        int n = s.size();
        vector<int> counts;
        while(ptr < n){
            char c = s[ptr];
            int count = 0;
            while(ptr < n && c == s[ptr]){
                ++ptr;
                ++count;
            }
            counts.push_back(count);
        }
        int ans = 0;
        for(int i = 1; i < counts.size(); i++){
            ans += min(counts[i], counts[i-1]);
        }
        return ans;
    }
};

//节省空间的按字符分组
class Solution {
public:
    int countBinarySubstrings(string s) {
        int ptr = 0;
        int n = s.size();
        int ans = 0;
        int pre = 0;
        while(ptr < n){
            char c = s[ptr];
            int count = 0;
            while(ptr < n && c == s[ptr]){
                ++ptr;
                ++count;
            }
            ans += min(count, pre);
            pre = count;
        }
        return ans;
    }
};

//pdf上的解法，思路其实和按字符分组相同
class Solution {
public:
    int countBinarySubstrings(string s) {
        int pre = 0;
        int curr = 1;
        int count = 0;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i-1]){
                ++curr;
            }
            else{
                pre = curr;
                curr = 1;
            }
            if(pre >= curr){
                count++;
            }
        }
        return count;

    }
};
