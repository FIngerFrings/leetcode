/*
 * 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
 * 如果剩余字符少于 k 个，则将剩余字符全部反转。
 * 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 */
//方法一：双指针
//思路：每次将i跳转到需要反转的区间头，然后使用双指针交换区间前k个字符
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for(int i = 0; i < n; i += 2 * k){
            int l = i, r = i + k - 1;
            if(r >= n){
                r = n - 1;
            }
            while(l < r){
                swap(s[l], s[r]);
                ++l;
                --r;
            }
        }

        return s;
    }
};
