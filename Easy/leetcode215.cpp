/* 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。*/
/*方法1：使用堆排序的方法，首先利用数组创建堆，然后依次弹出前面k-1个值，最后将最大值放到数组最后，然后取出*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(begin(nums), end(nums));
        for(int i = 0; i < k-1; i++){
            pop_heap(begin(nums), end(nums));
            nums.pop_back();
        }
        pop_heap(begin(nums), end(nums));
        return nums[nums.size()-1];
    }
};
