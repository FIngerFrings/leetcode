/*
 * 给你一个非负整数数组 nums ，你最初位于数组的第一个位置。
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
 * 假设你总是可以到达数组的最后一个位置。
 */
//方法一：回溯
//思路：找出所有情况，选择其中最小的
//超时
 class Solution {
    int ans;

    void backtracking(vector<int>& nums, int cur, int n){
        if(cur >= nums.size() - 1){
            ans = min(ans, n);
            return;
        }

        for(int i = 1; i <= nums[cur]; i++){
            backtracking(nums, cur + i, n + 1);
        }
        return;
    }

public:
    int jump(vector<int>& nums) {
        ans = nums.size();
        backtracking(nums, 0, 0);
        return ans;
    }
};

//方法二：代码随想录，回溯
//思路：思想就一句话：每次在上次能跳到的范围（end）内选择一个能跳的最远的位置（也就是能跳到max_far位置的点）作为下次的起跳点
class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int curDistance = 0;
        int nextDistance = 0;
        for(int i = 0; i < nums.size(); i++){
            nextDistance = max(nums[i] + i, nextDistance);
            if(i == curDistance){
                if(curDistance != nums.size() - 1){
                    ++ans;
                    curDistance = nextDistance;
                    if(nextDistance >= nums.size() - 1) break;
                }
                else break;
            }
        }
        return ans;
    }
};

//其实代码随想录贪心方法一里面不需要判断curDistance是否是在最后一个位置，因为能在这种情况只有数组大小为1时才可能出现，否则都会在上一次更新时直接退出
//此时如果没有判断数组大小是否等于1，会出错
//所有if(nums.size() == 1)    return 0;和if(curDistance != nums.size() - 1)只用一个就行
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1)    return 0;
        int ans = 0;
        int curDistance = 0;
        int nextDistance = 0;
        for(int i = 0; i < nums.size(); i++){
            nextDistance = max(nums[i] + i, nextDistance);
            if(i == curDistance){
                ++ans;
                curDistance = nextDistance;
                if(nextDistance >= nums.size() - 1) break;
            }
        }
        return ans;
    }
};

//贪心方法二
//其实思路还是和方法一相同，这里for循环只到nums.size() - 1是因为，防止出现curDistance刚好是最后一个元素，然后又多算了一次
//如果for循环到最后一个元素，则如果说curDistance刚好到达最后一个位置，则结果会多1
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1)    return 0;
        int ans = 0;
        int curDistance = 0;
        int nextDistance = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            nextDistance = max(nums[i] + i, nextDistance);
            if(i == curDistance){
                curDistance = nextDistance;
                ++ans;
            }
        }
        return ans;
    }
};
//所以还是贪心1比较好理解
