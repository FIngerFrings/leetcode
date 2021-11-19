/*
 * 给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
 * 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
 */
//方法一：双指针
//思路：实际上就是定义两个指针，r用于去寻找与r-1不同的值，这个值就是一个新的值，l指向需要交换的值
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return 0;
        int l = 1, r = 1;
        while(r < n){
            if(nums[r] != nums[r - 1]){
                nums[l] = nums[r];
                ++l;
            }
            ++r;
        }
        return l;
    }
};
