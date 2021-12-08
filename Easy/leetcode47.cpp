/* 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。 */
//方法一：回溯法
//思路：和之前的回溯法思想一样，不过这里是创建了一个数组，然后遍历数组中没有被插入的元素插入
//问题的关键在于数组中会有重复元素，所以得到的结果也会有重复的数组
//可以创建数组记录元素是否有被插入，且对原数组进行排序，这样重复的元素就可以放在一起
//如果nums[i] == nums[i-1]说明碰到了重复元素，同时如果vis[i-1] == 0，说明在相同的位置，前面重复的元素已经插入过了，自己就不要插入了
//如果vis[i-1] == 1，说明这个位置前面的元素还没查如果，就可以插入
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vis;
    vector<int> t;

    void backtrack(vector<int>& nums, int curr, int n){
        if(curr == n){
            ans.push_back(t);
            return;
        }

        for(int i = 0; i < n; i++){
            if(vis[i] == 1 || (i > 0 && nums[i] == nums[i-1] && vis[i-1] == 0)){
                continue;
            }

            vis[i] = 1;
            t.push_back(nums[i]);
            backtrack(nums, curr + 1, n);
            t.pop_back();
            vis[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vis.resize(n);
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, n);
        return ans;
    }
};

//代码随想录回溯
class Solution {
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> vis;

    void backtracking(vector<int>& nums){
        if(path.size() == nums.size()){
            ans.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if((i > 0 && nums[i] == nums[i-1] && !vis[i-1]) || vis[i]){
                continue;
            }

            path.push_back(nums[i]);
            vis[i] = true;
            backtracking(nums);
            vis[i] = false;
            path.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ans.clear();
        path.clear();
        vis.resize(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums);
        return ans;
    }
};
