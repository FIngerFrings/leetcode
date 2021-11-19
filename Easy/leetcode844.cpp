/*
 * 给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，请你判断二者是否相等。# 代表退格字符。
 * 如果相等，返回 true ；否则，返回 false 。
 * 注意：如果对空文本输入退格字符，文本继续为空。
 */
//方法一：重构字符串
//思路：将需要删除的字符删除后，比较两个字符串
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }

    string build(string s){
        string ans;
        for(char str : s){
            if(str != '#'){
                ans.push_back(str);
            }
            else if(!ans.empty()){
                ans.pop_back();
            }
        }
        return ans;
    }
};
