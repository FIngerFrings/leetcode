/* 给定一个整数，将其转化为7进制，并以字符串形式输出。 */
//方法一：进制转换
//思路：记住就好。。。我也不知道为什么
class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)  return "0";
        string ans;
        int isnegative = (num < 0) ? 1 : 0;
        if(isnegative)  num = -num;
        while(num){
            int a = num / 7;
            int b = num % 7;
            ans = to_string(b) + ans;
            num = a;
        }
        if(isnegative)  ans = '-' + ans;
        return ans;
    }
};
