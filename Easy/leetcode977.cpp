/* 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。 */
//方法一：暴力
//思路：先原地平方，后使用sort排序，不建议用该方法
//官方竟然也有这种解法。。。
//该方法没有利用到数组原本已经排序这个性质
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};

//方法二：双指针
//思路：设定两个指针分别指向数组开头和结尾，然后比较两个数的平方，将较大的数放在要返回的数组的最后
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0, j = n - 1, pos = n - 1; i <= j;){
            if(nums[i] * nums[i] > nums[j] * nums[j]){
                ans[pos--] = nums[i] * nums[i];
                ++i;
            }
            else{
                ans[pos--] = nums[j] * nums[j];
                --j;
            }
        }
        return ans;
    }
};
