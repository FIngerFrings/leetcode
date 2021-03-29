/*
 *给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 *有效字符串需满足：
 *左括号必须用相同类型的右括号闭合。
 *左括号必须以正确的顺序闭合。
*/
//方法，因为后进去的字符要先出去，所以使用栈，而哈希表可以快速查询，所以搭配上哈希表
//如果字符串大小为奇数，则一定为false
//在本题中，右括号是不能进入栈的，因为右括号前面一定会有一个左括号，所以如果碰上一个没有左括号的右括号，则一定是错误的
//对于需要快速查找的内容，可以使用哈希表
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;  //定义栈
        unordered_map<char, char> q = { //定义哈希表
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        if(s.size() % 2 == 1){
            return false;
        }
        for(int i = 0; i < s.size(); i++){
            if(q.count(s[i])){
                if(stk.empty() || stk.top() != q[s[i]]){
                    return false;
                }
                stk.pop();
            }else{
                stk.push(s[i]);
            }
        }
        return stk.empty();
    }
};

//方法二：使用栈，原理是先算出nums2中每个元素的下一个最大值，将其存放在哈希表中，之后在哈希表中查找nums1中每个元素的下一个最大值，这里对nums2使用了前序遍历
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> q;
        vector<int> p;
        stack<int> stk;
        for(int i = 0; i < nums2.size(); i++){
            while(!stk.empty() && stk.top() < nums2[i]){
                //q.insert(pair<int, int>(stk.top(), nums2[i]));
                q[stk.top()] = nums2[i];
                stk.pop();
            }
            stk.push(nums2[i]);
        }
        for(int i = 0; i < nums1.size(); i++){
            if(q.count(nums1[i])){
                p.push_back(q[nums1[i]]);
            }
            else{
                p.push_back(-1);
            }
        }
        return p;
    }
};

//方法三，方法同上，但这里对nums2是逆序遍历，如果栈为空，说明右边没有元素，则将-1插入哈希表
//如果栈不为空，且当前元素大于栈顶元素，则将栈顶元素弹出，因为对于前面的元素，栈顶元素绝对不是下一个最大的数，所以可以直接弹出
//每次都需要把当前元素压入栈中，一开始的while循环确保了从栈顶到栈底会是从大到小的顺序
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hx;
        vector<int> p;
        stack<int> stk;
        for(int i = nums2.size()-1; i >= 0; i--){
            while(!stk.empty() && nums2[i] > stk.top()){
                stk.pop();
            }
            hx[nums2[i]] = stk.empty()?-1:stk.top();    //利用三元操作符插入元素的方法记下来
            stk.push(nums2[i]);
        }

        for(int i = 0; i < nums1.size(); i++){
            p.push_back(hx[nums1[i]]);
        }
        return p;
    }
};
