/*
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
 * 注意：答案中不可以包含重复的三元组。
 */
//方法一：排序 + 双指针
//思路：实际上就是确定一个数，然后再去后面的数组寻找满足条件的两个数，这里需要注意的是如何确保无重复
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            int k = n - 1;
            for(int j = i + 1; j < n; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]){
                    continue;
                }

                while(j < k && nums[i] + nums[j] + nums[k] > 0){
                    --k;
                }

                if(j == k){
                    continue;
                }

                if(nums[i] + nums[j] + nums[k] == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        return ans;
    }
};

//代码随想录的排序+双指针
//思路和上面一样，但是代码比较容易懂
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return vector<vector<int>>{};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int l = i + 1, r = n - 1;
            while(l < r){
                if(nums[i] + nums[l] + nums[r] == 0){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l+1]) ++l;
                    while(l < r && nums[r] == nums[r-1]) --r;
                    ++l;
                    --r;
                }
                else if(nums[i] + nums[l] + nums[r] > 0){
                    --r;
                }
                else{
                    ++l;
                }
            }
        }
        return ans;
    }
};
