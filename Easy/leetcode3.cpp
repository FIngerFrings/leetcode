/* 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。 */
//方法一：滑动窗口
//思路：实际上就是计算从每个元素开始的最长子串长度，然后取其中的最大值
//使用哈希表记录是否有重复元素
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> q;
        int rk = -1, ans = 0;
        for(int i = 0; i < n; i++){
            if(i != 0){
                q.erase(s[i-1]);
            }

            while(rk + 1 < n && !q.count(s[rk + 1])){
                q.insert(s[rk + 1]);
                ++rk;
            }
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};
