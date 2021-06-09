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


//方法二：最开始想的贪心，但是没做出来，下面是官方解法
//思路：这道题一开始确实想的不是用n和n+1比较，而是想的n和n-1比较
//和上面同样的思想，如果出现了n大于n+1的情况，只有两种改变方法，一种是将n变成n+1，另一种是将n+1变成n
//如果n=0，那么只能把它变成n=1。如果n不为0，如果n+1大于n-1，可以将n变成n-1.但我们可以不用实现，只需要将num+1即可，因为后面的比较不需要n这个位置了
//如果n+1小于n-1，则只能将n+1变成n，如果后面再出现n大于n+1的情况，直接返回false就行
//如果最后遍历完了，说明num并没有大于1，则可以返回true
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)   return true;
        int num = 0;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] > nums[i+1]){
                num++;
                if(num > 1) return false;
                if(i > 0 && nums[i+1] < nums[i-1])  nums[i+1] = nums[i];
            }
        }
        return true;
    }
};
