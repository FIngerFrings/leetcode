/*
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * candidates 中的每个数字在每个组合中只能使用一次。
 */
//方法一：回溯法
//思路：自己做的回溯，对于1个元素，只有选择和不选择两种状态，问题的关键在于如何处理重复元素
//这里的处理方法和40题一样，也是用一个数组来存放这个元素是否被选择，在一开始同样也需要对数组进行排序，对于重复的元素
//如果满足curr > 0 && candidates[curr] == candidates[curr - 1] && !vis[curr-1]说明前面重复的元素已经处理过了，这里不再需要处理了
//所以直接跳到下一个元素上
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> t;
    vector<int> vis;
    void backtrack(vector<int>& candidates, int curr, int n, int target){
        if(accumulate(t.begin(), t.end(), 0) == target){
            ans.push_back(t);
            return;
        }

        if(accumulate(t.begin(), t.end(), 0) > target){
            return;
        }

        if(curr == n){
            return;
        }

        if(curr > 0 && candidates[curr] == candidates[curr - 1] && !vis[curr-1]){
            backtrack(candidates, curr + 1, n, target);
            return;
        }
        vis[curr] = 1;
        t.push_back(candidates[curr]);
        backtrack(candidates, curr + 1, n, target);
        t.pop_back();
        vis[curr] = 0;
        backtrack(candidates, curr + 1, n, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vis.resize(n);
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, n, target);
        return ans;
    }
};

//回溯
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> vis;

    void backtracking(vector<int> &candidates, int target, int sum, int cur){
        if(sum > target)    return;
        if(sum == target){
            ans.push_back(path);
            return;
        }

        for(int i = cur; i < candidates.size(); i++){
            if(i > 0 && candidates[i] == candidates[i-1] && !vis[i-1]){
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            vis[i] = true;
            backtracking(candidates, target, sum, i + 1);
            sum -= candidates[i];
            path.pop_back();
            vis[i] = false;
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vis.resize(candidates.size());
        backtracking(candidates, target, 0, 0);
        return ans;    
    }
};

//回溯+剪枝
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> vis;

    void backtracking(vector<int> &candidates, int target, int sum, int cur){
        if(sum > target)    return;
        if(sum == target){
            ans.push_back(path);
            return;
        }

        for(int i = cur; i < candidates.size() && sum + candidates[i] <= target; i++){
            if(i > 0 && candidates[i] == candidates[i-1] && !vis[i-1]){
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            vis[i] = true;
            backtracking(candidates, target, sum, i + 1);
            sum -= candidates[i];
            path.pop_back();
            vis[i] = false;
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vis.resize(candidates.size());
        backtracking(candidates, target, 0, 0);
        return ans;    
    }
};

//回溯+剪枝+不需要vis，直接通过cur判断是否重复
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void backtracking(vector<int> &candidates, int target, int sum, int cur){
        if(sum > target)    return;
        if(sum == target){
            ans.push_back(path);
            return;
        }

        for(int i = cur; i < candidates.size() && sum + candidates[i] <= target; i++){
            if(i > cur && candidates[i] == candidates[i-1]){
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i + 1);
            sum -= candidates[i];
            path.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return ans;    
    }
};
