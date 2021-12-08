/*
 * 给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
 * 数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。
 */
//方法一：回溯
//思路：和子集问题其实一样，不过每次递归需要创建一个哈希表记录哪些数字已经访问过
class Solution {
    vector<vector<int>> ans;
    vector<int> path;

    void backtracking(vector<int> &nums, int l){
        if(path.size() >= 2){
            ans.push_back(path);
        }

        if(l >= nums.size())    return;

        unordered_set<int> uset;
        for(int i = l; i < nums.size(); i++){
            if((!path.empty() && nums[i] < path.back()) || uset.find(nums[i]) != uset.end()){
                continue;
            }

            path.push_back(nums[i]);
            uset.insert(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        ans.clear();
        path.clear();
        backtracking(nums, 0);
        return ans;
    }
};
