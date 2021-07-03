/*
 * 给你一个整数数组 nums ，设计算法来打乱一个没有重复元素的数组。
 * 实现 Solution class:
 * Solution(int[] nums) 使用整数数组 nums 初始化对象
 * int[] reset() 重设数组到它的初始状态并返回
 * int[] shuffle() 返回数组随机打乱后的结果
 */

//方法一：Fisher-Yates 洗牌算法
//思路：需要注意的只有洗牌的方法，实际上就是对换元素，分为正向和反向
//反向
class Solution {
    vector<int> origin;
public:
    Solution(vector<int>& nums) {
        origin = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if(origin.empty())  return {};
        vector<int> shuffled(origin);
        int n = origin.size();
        for(int i = n-1; i >= 0; i--){
            swap(shuffled[i], shuffled[rand() % (i+1)]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

//正向
class Solution {
    vector<int> origin;
public:
    Solution(vector<int>& nums) {
        origin = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if(origin.empty())  return {};
        vector<int> shuffled(origin);
        int n = origin.size();
        for(int i = 0; i < n; i++){
            int pos = rand() % (n - i);
            swap(shuffled[i], shuffled[i + pos]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
