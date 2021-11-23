/*
 * 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 * 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
 */
//方法一：滑动窗口+哈希表
//思路：先记录p中出现的字符以及每个字符出现的次数，然后使用滑动窗口看窗口内是否为p的异位串
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        unordered_map<char, int> pMap;
        unordered_set<char> pSet;
        for(char c : p){
            ++pMap[c];
            pSet.insert(c);
        }

        int k = 0, l = 0, r = 0;
        while(r < n){
            if(pSet.count(s[r]) > 0 && --pMap[s[r]] >= 0){
                ++k;
            }
            ++r;
        }
        vector<int> ans;
        if(k == n){
            ans.push_back(0);
        }
        while(r < m){
            if(s[l] == s[r] && k == n){
                ans.push_back(++l);
            }
            else{
                if(pSet.count(s[l]) > 0 && ++pMap[s[l]] > 0){
                    --k;
                }
                ++l;
                if(pSet.count(s[r]) > 0 && --pMap[s[r]] >= 0){
                    ++k;
                }
                if(k == n){
                    ans.push_back(l);
                }
            }
            ++r;
        }
        return ans;
    }
};
