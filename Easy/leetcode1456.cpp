/* 给你字符串 s 和整数 k 。
 * 请返回字符串 s 中长度为 k 的单个子字符串中可能包含的最大元音字母数。
 * 英文中的 元音字母 为（a, e, i, o, u）。
 */
//方法一，暴力解法，但是显示超时，但是逻辑是没有错的
class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        if(n == 0 || k > n){
            return 0;
        }
        int maxnum = 0;
        for(int i = k-1; i < n; i++){
            int num = 0;
            for(int j = 0; j < k; j++){
                if(s[i-j] == 'a' || s[i-j] == 'e' || s[i-j] == 'i' || s[i-j] == 'o' || s[i-j] == 'u'){
                    num++;
                }
            }
            maxnum = (maxnum > num) ? maxnum : num;
        }
        return maxnum;
    }
};

//方法二，滑动窗口
//我觉得这种才是真的滑动窗口，整个窗口的大小不变，然后滑动窗口
//先找出前k个数中元音字母的个数，然后再往后滑动，如果没滑动前窗口的第一个字母是元音，则滑动后个数要-1，如果新加入的那个字母是元音，则还要+1
//这个思路很好
class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {
        int n = s.size();
        if(n == 0){
            return 0;
        }
        int vowel_count = 0;
        for(int i = 0; i < k; i++){
            vowel_count += isVowel(s[i]);
        }

        int ans = vowel_count;
        for(int i = k; i < n; i++){
            vowel_count += isVowel(s[i]) - isVowel(s[i-k]);
            ans = max(ans, vowel_count);
        }
        return ans;
    }
};
