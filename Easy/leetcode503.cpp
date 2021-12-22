/*
 * 给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组遍历顺序，
 * 这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。
 */
//方法一：单调栈
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> stk;
        stk.push(0);
        for(int i = 1; i < n; i++){
            while(!stk.empty() && nums[i] > nums[stk.top()]){
                ans[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }

        int i = 0;
        while(!stk.empty() && i < n){
            if(nums[i] > nums[stk.top()]){
                ans[stk.top()] = nums[i];
                stk.pop();
            }
            else{
                ++i;
            }
        }
        return ans;
    }
};

//比上面单调栈更简洁
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> stk;
        stk.push(0);
        for(int i = 1; i < n * 2; i++){
            while(!stk.empty() && nums[i % n] > nums[stk.top()]){
                ans[stk.top()] = nums[i % n];
                stk.pop();
            }
            stk.push(i % n);
        }
        return ans;
    }
};
