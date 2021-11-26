/*
 * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
 * 返回滑动窗口中的最大值。
 */
//方法一：自己实现单调队列
//思路：单调队列自己实现，实际上就是定义一个单调递减的队列，每次push元素时把队列中所有比它小的元素弹出，然后再把它压进去
//然后每个窗口取当时单调队列中的最前面的值也就是最大值
class Solution {
public:
    class MyQueue{
    public:
        deque<int> q;
        void push(int x){
            while(!q.empty() && q.back() < x){
                q.pop_back();
            }
            q.push_back(x);
        }

        void pop(int x){
            if(!q.empty() && q.front() == x){
                q.pop_front();
            }
        }

        int front(){
            return q.front();
        }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue myQ;
        for(int i = 0; i < k; i++){
            myQ.push(nums[i]);
        }
        vector<int> ans;
        ans.push_back(myQ.front());
        for(int i = k; i < nums.size(); i++){
            myQ.pop(nums[i-k]);
            myQ.push(nums[i]);
            ans.push_back(myQ.front());
        }
        return ans;
    }
};
