/* 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。 */
//方法一：回溯
//通过回溯找出所有k个数的组合，然后判断和是否等于n
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> nums;

    void backtracking(int n, int k, int cur){
        if(nums.size() == k){
            int sum = accumulate(nums.begin(), nums.end(), 0);
            if(sum == n){
                ans.push_back(nums);
            }
            return;
        }

        for(int i = cur; i <= 9 - (k - nums.size()) + 1; i++){
            nums.push_back(i);
            backtracking(n, k, i + 1);
            nums.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(n, k, 1);
        return ans;
    }
};

//代码随想录回溯
//每次传递函数的时候把和也传递进去
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> nums;

    void backtracking(int n, int k, int cur, int sum){
        if(nums.size() == k){
            if(sum == n){
                ans.push_back(nums);
            }
            return;
        }

        for(int i = cur; i <= 9 - (k - nums.size()) + 1; i++){
            sum += i;
            nums.push_back(i);
            backtracking(n, k, i + 1, sum);
            nums.pop_back();
            sum -= i;
        }
        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(n, k, 1, 0);
        return ans;
    }
};

//加了一个条件剪枝
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> nums;

    void backtracking(int n, int k, int cur, int sum){
        if(sum > n) return;
        if(nums.size() == k){
            if(sum == n){
                ans.push_back(nums);
            }
            return;
        }

        for(int i = cur; i <= 9 - (k - nums.size()) + 1; i++){
            sum += i;
            nums.push_back(i);
            backtracking(n, k, i + 1, sum);
            nums.pop_back();
            sum -= i;
        }
        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(n, k, 1, 0);
        return ans;
    }
};
