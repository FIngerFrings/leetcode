/* 给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。你需要给出所有可能的组合的结果。有效的运算符号包含 +, - 以及 * 。*/
//方法一：分治法
//思路：对于表达式中的任意一个符号，可以将括号加到其两边的表达式上，所以使用递归的方法，求出其左边和右边表达式的值，然后根据当前的符号得到结果
//如果不懂就自己意会
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        int n = expression.size();
        for(int i = 0; i < n; i++){
            char input = expression[i];
            if(input == '-' || input == '+' || input == '*'){
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));
                for(const int &l : left){
                    for(const int &r : right){
                        switch (input){
                            case '-':   ans.push_back(l-r); break;
                            case '+':   ans.push_back(l+r); break;
                            case '*':   ans.push_back(l*r); break;
                        }
                    }
                }
            }
        }
        if(ans.empty()) ans.push_back(stoi(expression));
        return ans;
    }
};
