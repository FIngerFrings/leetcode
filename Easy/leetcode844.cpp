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

//方法二：双指针
//思路：因为退格键只会删掉它前面的一个非退格键字符，所以我们从后面开始使用双指针遍历两个字符串
//遇到退格键则skip+1，当遇到字符时，判断skip是否为0，不是0则代表这个字符是要被删除的
//所以首先移动到不需要删除的字符位置，然后对比此时两个字符串所不需要删除的字符是否相等，如果不等则直接返回false
//否则继续遍历下去
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        int sSkip = 0, tSkip = 0;
        while(i >= 0 || j >= 0){
            while(i >= 0){
                if(s[i] == '#'){
                    ++sSkip;
                    --i;
                }
                else if (sSkip > 0){
                    --i;
                    --sSkip;
                }
                else{
                    break;
                }
            }

            while(j >= 0){
                if (t[j] == '#') {
                    ++tSkip;
                    --j;
                }
                else if (tSkip > 0){
                    --tSkip;
                    --j;
                }
                else{
                    break;
                }
            }

            if(i >= 0 && j >= 0){
                if(s[i] != t[j]){
                    return false;
                }
            }
            else if(i >= 0 || j >= 0){
                return false;
            }
            --i;
            --j;
        }
        return true;
    }
};
