/*
 * 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
 * 在 S 上反复执行重复项删除操作，直到无法继续删除。
 * 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
 */
//方法一：栈
//思路：很明显要用栈，但是如果直接使用栈则会超时，所以用string
class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        for(int i = 0; i < s.size(); i++){
            if(!ans.empty() && ans.back() == s[i]){
                ans.pop_back();
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};

//直接使用stack，超时
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for(char c : s){
            if(!stk.empty() && stk.top() == c){
                stk.pop();
            }
            else{
                stk.push(c);
            }
        }
        string ans = "";
        while(!stk.empty()){
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};
//代码随想录的栈没有超时。。。
class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        for (char s : S) {
            if (st.empty() || s != st.top()) {
                st.push(s);
            } else {
                st.pop(); // s 与 st.top()相等的情况
            }
        }
        string result = "";
        while (!st.empty()) { // 将栈中元素放到result字符串汇总
            result += st.top();
            st.pop();
        }
        reverse (result.begin(), result.end()); // 此时字符串需要反转一下
        return result;

    }
};
