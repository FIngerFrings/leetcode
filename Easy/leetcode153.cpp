/* 
 * 已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,2,4,5,6,7] 在变化后可能得到：
 * 若旋转 4 次，则可以得到 [4,5,6,7,0,1,2]
 * 若旋转 7 次，则可以得到 [0,1,2,4,5,6,7]
 * 注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。
 * 给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。
 */

//方法一：遍历数组，暴力法
//没有用到数组的局部升序特性
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return -1;
        int minnum = INT_MAX;
        for(int i = 0; i < n; i++){
            minnum = min(nums[i], minnum);
        }
        return minnum;
    }
};

//方法二：排序
//思路：排序后第一个就是最小的数
class Solution {
public:
    int findMin(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[0];
    }
};

//方法三：二分查找
//思路：思路同leetcode81。对于这样一个数组，可以分为两部分，整个数组局部有序。使用二分查找，如果最小值
//官方的二分查找比较好
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return nums[0];
        int l = 0, r = n - 1, ans = INT_MAX;
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[l] <= nums[mid] && nums[mid] <= nums[r]){
                ans = min(ans, nums[l]);
                break;
            }
            else if(nums[l] <= nums[mid]){
                ans = min(ans, nums[l]);
                l = mid + 1;
            }
            else{
                ans = min(ans, nums[mid]);
                r = mid - 1;
            }
        }
        return ans;
    }
};

//官方二分查找
//思路：思路同二分查找，也是定义l和r，然后对比mid，如果mid小于r，说明最小值在mid的左半边。如果mid大于r，说明最小值在mid右半边
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return nums[0];
        int l = 0, r = n - 1;
        while(l < r){
            int mid = (l + r) / 2;
            if(nums[mid] < nums[r]){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return nums[l];
    }
};
