/*
 * 每个非负整数 N 都有其二进制表示。例如， 5 可以被表示为二进制 "101"，11 可以用二进制 "1011" 表示，依此类推。注意，除 N = 0 外，任何二进制表示中都不含前导零。
 * 二进制的反码表示是将每个 1 改为 0 且每个 0 变为 1。例如，二进制数 "101" 的二进制反码为 "010"。
 * 给你一个十进制数 N，请你返回其二进制表示的反码所对应的十进制整数。
 */
//方法一：数组
//思路：用数组存放二进制数
class Solution {
public:
    int bitwiseComplement(int n) {
        vector<int> ans(31);
        int k = 0;
        int p = 1;
        int ret = 0;
        while(n){
            ans[k++] = n % 2;
            n /= 2;
        }

        for(int i = 0; i < k; i++){
            if(ans[i] == 0){
                ans[i] = 1;
            }
            else{
                ans[i] = 0;
            }
            ret += p * ans[i];
            p <<= 1;
        }

        return ret;
    }
};
