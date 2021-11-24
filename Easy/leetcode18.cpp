/*
 * 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
 * 0 <= a, b, c, d < n
 * a、b、c 和 d 互不相同
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 * 你可以按 任意顺序 返回答案 。
 */
//方法一：排序+双指针
//思路：同三数之和
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            for(int j = i + 1; j < n; j++){
                if(j > i + 1 && nums[j] == nums[j-1]){
                    continue;
                }
                int l = n - 1;
                for(int k = j + 1; k < n; k++){
                    if(k > j + 1 && nums[k] == nums[k-1]){
                        continue;
                    }
                    
                    while(k < l && (long long)nums[i] + nums[j] + nums[k] + nums[l] > target){
                        --l;
                    }

                    if(k == l){
                        break;
                    }

                    if((long long)nums[i] + nums[j] + nums[k] + nums[l] == target){
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    }
                }
            }
        }
        return ans;
    }
};
