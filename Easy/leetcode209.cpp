//leetcode209
/* 给定一个含有 n 个正整数的数组和一个正整数 target 。找出该数组中满足其和 ≥ target 的长度最小的 
 * 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
 */

//自己的方法，使用滑动窗口（双指针），自己领会
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int length = 0;     //子数组长度
        int l = 0, r = 0, sum = nums[0];
        while(l < nums.size()){
            if(sum >= target){
                if(length == 0){
                    length = r - l + 1;
                }
                else{
                    length = (length < (r - l + 1)) ? length : (r - l + 1);
                }
                sum -= nums[l];
                ++l;
            }
            else{
                if(r == nums.size() - 1){
                    sum -= nums[l];
                    l++;
                }
                else{
                    r++;
                    sum += nums[r];
                }
            }
        }
        return length;
    }
};

//方法二 暴力解法，使用两个for循环
//需要注意的一个地方是，可以使用INT_MAX作为长度初值，这样就不用像方法一一样还要判断以下length是否为0
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum >= s) {
                    ans = min(ans, j - i + 1);
                    break;          //找到从i下标开始符合条件的数组后就不用继续下去了，因为数组都是正数，所以再往下加也都是正数
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

//方法一的改进，同样也是滑动窗口
//官方解法，原理和方法一一样，但是更好
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        int length = INT_MAX;
        int l = 0, r = 0, sum = 0;
        while(r < n){           //没想到这种两个while循环的形式，实际上确实可以每次循环都可以增加r，如果满足条件，可以再减少l
            sum += nums[r];
            while(sum >= target){
                length = (length < (r - l + 1) ? length : (r - l + 1));
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return (length == INT_MAX) ? 0 : length;
    }
};

//双指针，但是没上面的好，实际上并不需要判断l是否小于n
//其实可以改成for循环。。。
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int ans = n + 1, sum = 0;
        while(l < n && r < n){
            sum += nums[r];
            while(sum >= target){
                ans = min(ans, r - l + 1);
                sum -= nums[l];
                ++l;
            }
            if(r < n){
                ++r;
            }
        }
        return ans > n ? 0 : ans;
    }
};

//上面双指针（滑动窗口）方法的时间复杂度为n，因为每个元素都只会被操作两次
