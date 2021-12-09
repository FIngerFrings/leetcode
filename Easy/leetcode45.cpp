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
//思路：思想就一句话：每次在上次能跳到的范围（end）内选择一个能跳的最远的位置（也就是能跳到max_far位置的点）作为下次的起跳点 ！
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
