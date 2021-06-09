/*
 * 给你一个长度为 n 的整数数组，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。
 * 我们是这样定义一个非递减数列的： 对于数组中任意的 i (0 <= i <= n-2)，总满足 nums[i] <= nums[i + 1]。
 */
//方法一:这应该是贪心
//思路：如果在遍历数组的过程中发现一个nums[i] > nums[i+1]，则有两种方法可以修改，一种是将nums[i+1]减少到nums[i+1]，一种是将num[i+1]增加到nums[i]
//可以分别试这两种方法，如果其中一种有序，则返回true
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)   return true;
        for(int i = 0; i < n-1; i++){
            if(nums[i] > nums[i+1]){
                int x = nums[i];
                int y = nums[i+1];
                nums[i] = y;
                if(is_sorted(nums.begin(), nums.end())){
                    return true;
                }
                nums[i] = x;
                nums[i+1] = x;
                return is_sorted(nums.begin(), nums.end());
            }
        }
        return true;
    }
};
