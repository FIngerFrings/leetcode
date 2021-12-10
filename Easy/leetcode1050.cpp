/*
 * 给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：
 * 选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
 * 重复这个过程恰好 k 次。可以多次选择同一个下标 i 。
 * 以这种方式修改数组后，返回数组 可能的最大和 。
 */
//方法一：排序+贪心
//思路：每次都选择最小的数反转
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        while(k--){
            sort(nums.begin(), nums.end());
            nums[0] = -nums[0];
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};

//贪心
//思路：按绝对值从大到小排序，然后遍历数组，负数变为正数，如果全部负数都变为了正数，k还大于0，则改变最小的数
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), [](const int& a, const int& b){
            return abs(a) > abs(b);
        });
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0 && k > 0){
                nums[i] = -nums[i];
                --k;
            }
        }

        if(k % 2 != 0)  nums[nums.size() - 1] = -nums[nums.size() - 1];
        int ans = 0;
        for(int num : nums) ans += num;
        return ans;
    }
};
