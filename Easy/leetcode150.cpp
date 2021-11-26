/*
 * 根据 逆波兰表示法，求表达式的值。
 * 有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
 */
//方法一：栈
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(string s : tokens){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                if(s == "+"){
                    stk.push(num1 + num2);
                }
                else if(s == "-"){
                    stk.push(num2 - num1);
                }
                else if(s == "*"){
                    stk.push(num1 * num2);
                }
                else{
                    stk.push(num2 / num1);
                }
            }
            else{
                int temp = 0;
                bool flag = false;
                for(int i = 0; i < s.size(); i++){
                    if(s[i] == '-'){
                        flag = true;
                        continue;
                    }
                    temp *= 10;
                    temp += (s[i] - '0');
                }
                if(flag){
                    temp *= -1;
                }
                stk.push(temp);
            }
        }
        int ans = stk.top();
        return ans;
    }
};
