/* 
 * 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
 * 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
 */
//方法一：回溯
//思路：和子集问题的思路相同，不过需要判断是否重复
class Solution {
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> vis;

    void backtracking(vector<int>& nums, int l){
        ans.push_back(path);
        if(l >= nums.size())    return;

        for(int i = l; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1] && !vis[i-1]){
                continue;
            }
            path.push_back(nums[i]);
            vis[i] = true;
            backtracking(nums, i + 1);
            path.pop_back();
            vis[i] = false;
        }
        return;
    }
        
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        vis.resize(nums.size(), false);
        backtracking(nums, 0);
        return ans;
    }
};

//不需要数组来记录是否访问过的回溯
class Solution {
    vector<vector<int>> ans;
    vector<int> path;

    void backtracking(vector<int>& nums, int l){
        ans.push_back(path);
        if(l >= nums.size())    return;

        for(int i = l; i < nums.size(); i++){
            if(i > l && nums[i] == nums[i-1]){
                continue;
            }
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
        return;
    }
        
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return ans;
    }
};
