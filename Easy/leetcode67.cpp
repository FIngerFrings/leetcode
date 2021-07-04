/*
 * 给你两个二进制字符串，返回它们的和（用二进制表示）。
 * 输入为 非空 字符串且只包含数字 1 和 0。
 */
//方法一：模拟二进制计算
//思路：就是模拟二进制计算
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        string ans = "";
        int add = 0;
        while(i >= 0 || j >= 0 || add != 0){
            int x = (i >= 0) ? (a[i] - '0') : 0;
            int y = (j >= 0) ? (b[j] - '0') : 0;
            int result = x + y + add;
            ans.push_back(result % 2 + '0');
            add = result / 2;
            --i;
            --j;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//方法二：位运算
//思路：这里就不详细介绍位运算的原理了，可以看官方解法，但是要知道位运算怎么算的
