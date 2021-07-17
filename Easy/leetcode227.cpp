/*
 * 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
 * 整数除法仅保留整数部分。
 */
//方法一：栈
//思路：不知道为什么要栈
//不过基本就是先将其中的乘和除计算，前面是减号的就将数字的负数加入数组，最后计算数组的和
class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        char presign = '+';
        vector<int> nums;
        int num = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != ' ' && s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/'){
              //因为数字并不是个数，所以要用num记录，我一开始以为数组都是个位数
                num = num * 10 + (s[i] - '0');
            }
          //因为要照顾最后一个i，所以这里并没有使用else if，因为如果到了最后一个数字，也要先记录数字是多少
          //而且对上一个符号的处理是要到下一个符号才进行
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i == n - 1){
                switch(presign){
                    case '+':
                        nums.push_back(num);
                        break;
                    case '-':
                        nums.push_back(-num);
                        break;
                    case '*':
                        nums.back() *= num;
                        break;
                    case '/':
                        nums.back() /= num;
                        break;
                }
                presign = s[i];
                num = 0;
            }
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};
