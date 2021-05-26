//leetcode209
/* 给定一个含有 n 个正整数的数组和一个正整数 target 。找出该数组中满足其和 ≥ target 的长度最小的 
 * 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
 */

//自己的方法，使用滑动窗口（双指针），自己领会
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int length = 0;     //子数组长度
        int l = 0, r = 0, sum = nums[0];
        while(l < nums.size()){
            if(sum >= target){
                if(length == 0){
                    length = r - l + 1;
                }
                else{
                    length = (length < (r - l + 1)) ? length : (r - l + 1);
                }
                sum -= nums[l];
                ++l;
            }
            else{
                if(r == nums.size() - 1){
                    sum -= nums[l];
                    l++;
                }
                else{
                    r++;
                    sum += nums[r];
                }
            }
        }
        return length;
    }
};
