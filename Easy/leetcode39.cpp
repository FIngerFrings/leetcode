/* 
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * candidates 中的数字可以无限制重复被选取。
 */

//方法一：回溯
//思路：一个元素只有两种状态，选或者不选，如果rest大于当前元素，说明可以选，则将其加入数组中，然后继续迭代，之后将其弹出
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> t;

    void backtrack(vector<int>& candidates, int n, int curr, int rest){
        if(curr == n){
            return;
        }
        if(rest == 0){
            ans.push_back(t);
            return;
        }

        backtrack(candidates, n, curr + 1, rest);

        if(rest - candidates[curr] >= 0){
            t.push_back(candidates[curr]);
            backtrack(candidates, n, curr, rest - candidates[curr]);
            t.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        backtrack(candidates, n, 0, target);
        return ans;
    }
};
