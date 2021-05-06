/* 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。*/
//二分查找不做多的介绍
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int  l = 0, r = nums.size() - 1, pivot = (l + r) / 2;
        while(l <= r){
            if(nums[pivot] == target){
                return pivot;
            }
            else if(nums[pivot] > target){
                r = pivot - 1;              //需要注意的是r或者l可以不是pivot，因为pivot已经不会是target了
            }
            else{
                l = pivot + 1;
            }
            pivot = (l + r) / 2;
        }
        return -1;
    }
};
