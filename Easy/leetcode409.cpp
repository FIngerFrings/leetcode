/*
 * 给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
 * 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
 */
//方法一：哈希表
//思路：使用哈希表记录字符出现的次数，其中出现次数为偶数次的可以全部加到回文串中
//回文串可以另外加一个单个字符当作回文中心
//官方解法也和我差不多
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> hash;
        for(int i = 0; i < s.size(); i++){
            hash[s[i]] += 1;
        }
        bool flag = false;
        int ans = 0;
        for(auto [c, i] : hash){
            if(i % 2){
                ans += i - 1;
                flag = true;
            }
            else{
                ans += i;
            }
        }
        ans += (flag) ? 1 : 0;
        return ans;
    }
};
