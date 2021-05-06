/* leetcode35 搜索插入位置 */
/* 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。你可以假设数组中无重复元素。*/
//归根到底就是二分查找，需要注意的是多出来了一个条件，如果没有找到，则找出它的位置在哪
//因为如果使用二分查找没有找到该元素，则最后插入的位置要么就是pivot前面或者它后面
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pivot, l = 0, r = nums.size() - 1;
        while(l <= r){
            pivot = (l + r) / 2;
            if(nums[pivot] == target){
                return pivot;
            }
            else if(nums[pivot] > target){
                r = pivot - 1;
            }
            else{
                l = pivot + 1;
            }
        }
        return (nums[pivot] > target) ? pivot : pivot + 1;
    }
};
//官方的解法虽然也是二分查找，但是实际上比我们的更简单，它将两个问题结合到了一起
//考虑这个插入的位置pos，它成立的条件为：nums[pos−1]<target≤nums[pos] 其中 nums 代表排序数组。由于如果存在这个目标值，
//我们返回的索引也是pos因此我们可以将两个条件合并得出最后的目标：「在一个有序数组中找第一个大于等于 \textit{target}target 的下标」。
//问题转化到这里，直接套用二分法即可，即不断用二分法逼近查找第一个大于等于 \textit{target}target 的下标 。
//下文给出的代码是笔者习惯的二分写法，ans 初值设置为数组长度可以省略边界条件的判断，因为存在一种情况是target 大于数组中的所有数，
//此时需要插入到数组长度的位置。
//看上面的官方解释可能会不明白pos的选择，这是因为如果最后没有找到target，则target占据的位置应该是比它大的那个数的位置，所以实际上也就是要找出大于等于target的位置
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1, ans = n;
        while (left <= right) {
            int mid = ((right - left) >> 1) + left; //>> 1 相当于 / 2
            if (target <= nums[mid]) {
                ans = mid;          //ans 初值设置为数组长度可以省略边界条件的判断，因为存在一种情况是target 大于数组中的所有数
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
