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

//二分查找
//思路：通过二分查找找到第一个等于target的下标和最后一个等于target的下标
class Solution {
public:
    int binary_search(vector<int>& nums, int target, bool lower){
        int l = 0, r = nums.size() - 1, ans = nums.size();
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] > target || (lower && nums[mid] >= target)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = binary_search(nums, target, true);
        int r = binary_search(nums, target, false) - 1;
        if(l <= r && nums[l] == target && nums[r] == target){
            return {l, r};
        }
        return {-1, -1};
    }
};

//二分查找规范解法
class Solution {
public:
    int find_left(vector<int> &nums, int target){
        int l = 0, r = nums.size() - 1;
        int left = -2;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
                left = r;
            }
        }
        return left;
    }

    int find_right(vector<int> &nums, int target){
        int l = 0, r = nums.size() - 1;
        int right = -2;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] > target){
                r = mid - 1;
            }
            else{
                l = mid + 1;
                right = l;
            }
        }
        return right;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = find_left(nums, target);
        int right = find_right(nums, target);
        if(left == -2 || right == -2){
            return {-1, -1};
        }
        else if(right - left > 1){
            return {left + 1, right - 1};
        }
        else{
            return {-1, -1};
        }
    }
};
