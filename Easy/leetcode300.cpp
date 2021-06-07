/*
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 * 子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
 */
//方法一：动态规划
//思路：首先也是分割问题和定义状态，这里的状态 方程就是dp[i] = max(dp[i]) + 1，其中i < j且nums[i] < nums[j]
//但是这样时间复杂度比较高，不过官方解法竟然也是这样的。。。
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = 1;
        for(int i = 1; i < n; i++){
            int maxlength = 0;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    maxlength = max(maxlength, dp[j]);
                }
            }
            dp[i] = maxlength + 1;
        }
        sort(dp.begin(), dp.end());
        return dp[n-1];
    }
};

//方法二:贪心+最小二乘
//思路：虽然方法和官方的一样，但是思路我觉得不一样，我觉得该方法实际上是遍历数组中的所有值，然后计算出的递增子序列，得到其中最长的长度
//用一个数组来存放递增子序列即可，首先对于第一个元素，以它为结尾的最长子序列就是它自己本身，所以先将这个元素加入到数组中
//然后遍历后面的元素，例如对于第二个元素，将它与递增子序列的数组中的最后一个元素进行比较，实际上也就是第一个元素，如果大于数组最后一个元素，则将其加入递增子序列的数组
//如果小于，则在递增子序列数组中找到第一个比它大的元素进行替换，后面的步骤和这个也是一样的。
//替换的过程实际上就是计算所有子序列的过程
//最后子序列数组的长度就是最长递增子序列的长度
//因为子序列肯定是递增的，所以在替换过程中可以使用最小二乘法，下面使用的是lower_bound函数，也可以自己使用这个函数，以达到最小二乘搜索的目的
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sq;
        sq.push_back(nums[0]);
        for(int i = 1; i < n; i++){
            if(nums[i] > sq.back()){
                sq.push_back(nums[i]);
            }
            else{
                sq[lower_bound(sq.begin(), sq.end(), nums[i]) - sq.begin()] = nums[i];
            }
        }
        return sq.size();
    }
};

//下面是自己实现lower_bound
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sq;
        sq.push_back(nums[0]);
        for(int i = 1; i < n; i++){
            if(nums[i] > sq.back()){
                sq.push_back(nums[i]);
            }
            else{
                //sq[lower_bound(sq.begin(), sq.end(), nums[i]) - sq.begin()] = nums[i];
                int l = 0, r = sq.size() - 1;
                while(l < r){
                    int mid = (l + r) / 2;
                    if(sq[mid] > nums[i]){
                        r = mid - 1;
                    }
                    else if(sq[mid] < nums[i]){
                        l = mid + 1;
                    }
                    else{
                        break;
                    }
                }
                if(sq[(l + r) / 2] < nums[i]){
                    sq[(l + r) / 2 + 1] = nums[i];
                }
                else{
                    sq[(l + r) / 2] = nums[i];
                }
                
            }
        }
        return sq.size();
    }
};
