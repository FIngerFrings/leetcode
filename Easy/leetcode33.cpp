/* 
 * 整数数组 nums 按升序排列，数组中的值 互不相同 。
 * 在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，
 * 使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
 * 给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
 */
//方法一：二分查找
//思路：对于一个原本有序的数组，他将下标k以及后面的所有元素都搬移到了前面，形成了一种局部有序的情况，即数组分为两部分，两个部分都分别有序，
//但是整体却不是有序的，这种情况下同样也能使用二分查找。同一般的二分查找相同，也是定义左右两个下标l和r，然后取中间的下标mid看是否和目标值相同，
//如果相同则直接返回中间值。如果不同，则判断l对应的值是否小于mid对应的值，如果小于，则说明从l到mid这一段的数组是有序的，相应的另一边就是无序的，
//同时判断目标值是否在这一区间，如果在这一区间，则继续对这一区间做二分查找，否则就在另一区间做二分查找，直到找到目标值。
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
