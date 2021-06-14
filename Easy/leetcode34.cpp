/* 
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。 
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 */
//方法一：暴力解法
//思路：略
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)  return {-1, -1};
        int l = -1, r = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                if(l == -1){
                    l = i;
                }
                r = i;
            }
        }
        return {l, r};
    }
};

//方法二：双指针
//思路：略
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)  return {-1, -1};
        int l = 0, r = n - 1;
        while(l <= r){
            if(nums[l] == target && nums[r] == target){
                break;
            }
            else{
                if(nums[l] != target){
                    ++l;
                }
                if(nums[r] != target){
                    --r;
                }
            }
        }
        vector<int> q;
        if(l > r){
            q = {-1, -1};
        }
        else{
            q = {l, r};
        }
        return q;
    }
};
