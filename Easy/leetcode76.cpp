/* 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。*/
//方法一：双指针
//思路：使用双指针滑动窗口，不断将右指针向右移动，如果窗口内包含了所有t中的字符，则可以尝试缩短长度，左移l，前提是要让窗口内包含所有t内的字符
//需要注意的是t内可能会有重复字符，因此要统计t内字符的数量
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> nums;
        unordered_map<char, bool> isOk;
        for(char str : t){
            ++nums[str];
            isOk[str] = true;
        }

        int n = s.size();
        int l = 0, min_size = n + 1, ansl = -1;
        int cnt = 0;
        for(int r = 0; r < n; r++){
            if(isOk[s[r]]){
                if(--nums[s[r]] >= 0){
                    ++cnt;
                }
                while(cnt == t.size()){
                    if(r - l + 1 < min_size){
                        ansl = l;
                        min_size = r - l + 1;
                    }
                    if(isOk[s[l]] && ++nums[s[l]] > 0){
                        --cnt;
                    }
                    ++l;
                }
            }
        }
        return min_size > n ? string() : s.substr(ansl, min_size);

    }
};

//自己写的滑动窗口
class Solution {
public:
    string minWindow(string s, string t) {
        int minl = 0;
        int l = 0;
        int len = s.size()+1, k = 0;
        unordered_map<char, int> hash;
        for(char c : t){
            ++hash[c];
        }
        for(int r = 0; r < s.size(); r++){
            if(hash.find(s[r]) != hash.end() && hash[s[r]]-- > 0){
                ++k;
            }

            while(k == t.size()){
                if(r - l + 1 < len){
                    minl = l;
                    len = r - l + 1;
                }

                if(hash.find(s[l]) != hash.end() && ++hash[s[l]] > 0){
                    --k;
                }
                ++l;
            }
        }
        return len > s.size() ? "" : s.substr(minl, len);
    }
};
