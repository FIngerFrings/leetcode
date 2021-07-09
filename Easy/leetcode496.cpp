/*
 *给你两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。
 *请你找出 nums1 中每个元素在 nums2 中的下一个比其大的值。
 *nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 -1 。
*/
//方法一：硬解，但是时间复杂度高
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> q;
        for(int i = 0; i < nums1.size(); i++){
            int max = -1;
            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    for(int k = j+1; k < nums2.size(); k++){
                        if(nums2[k] > nums2[j]){
                            max = nums2[k];
                            break;
                        }
                    }
                }
            }
            q.push_back(max);
        }
        return q;
    }
};

//方法二：思路为先将nums2中每个数的下一个最大元素算出，然后放进哈希表中，之后遍历nums1，得到nums1中每个值对应的下一个最大值
//该方法对nums2执行先序遍历，如果栈为空，说明是第一个元素，则压入栈中，否则将该元素与栈顶元素进行比较，如果大则将栈顶元素取出并存放进哈希表中，否则将当前元素压入栈中
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hx;
        stack<int> stk;
        vector<int> p;
        for(int i = 0; i < nums2.size(); i++){
            while(!stk.empty() && nums2[i] > stk.top()){
                hx[stk.top()] = nums2[i];
                stk.pop();
            }
            stk.push(nums2[i]);
        }
        while(!stk.empty()){
            hx[stk.top()] = -1;
            stk.pop();
        }
        for(int i = 0; i < nums1.size(); i++){
            p.push_back(hx[nums1[i]]);
        }
        return p;
    }
};

//方法三是对方法二的变形，这里对nums2进行后序遍历
//for循环中的while循环实际上就是让栈顶元素为当前元素的下一个最大值，如果为空，说明当前元素后面没有比它大的数了，之后利用三元运算符，得到当前元素的下一个最大值，如果栈为空，说明后面没有比它大的值，则返回-1，如果不为空，则返回栈顶元素
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hx;
        stack<int> stk;
        vector<int> p;
        for(int i = nums2.size()-1; i >= 0; i--){
            while(!stk.empty() && nums2[i] > stk.top()){
                stk.pop();
            }
            hx[nums2[i]] = stk.empty() ? -1 : stk.top();
            stk.push(nums2[i]);
        }

        for(int i = 0; i < nums1.size(); i++){
            p.push_back(hx[nums1[i]]);
        }
        return p;
    }
};

//在leetcode20里面看到的，好像是不小心在那边也写了一遍
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

