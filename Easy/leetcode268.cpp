/* 给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。 */
//方法一：求和
//思路：先求出0到n的和，然后用数组中的数减去，最后的结果就是少的那个数
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i <= nums.size(); i++){
            sum += i;
        }

        for(int k : nums){
            sum -= k;
        }
        return sum;
    }
};
//和上面一种方法一样，不过代码比较简洁
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ret = 0;
        for(int i = 0; i < n; i++){
            ret += i - nums[i];
        }
        return ret + n;
    }
};
