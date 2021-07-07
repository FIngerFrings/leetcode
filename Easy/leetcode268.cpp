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

//可以使用高斯求和
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = nums.size() * (nums.size() + 1) / 2;
        for(int i : nums){
            sum -= i;
        }
        return sum;
    }
};

//方法二：数组
//使用数组记录出现过的数组
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> q(nums.size() + 1);
        for(int i : nums){
            q[i] = 1;
        }
        for(int i = 0; i <= nums.size(); i++){
            if(q[i] == 0){
                return i;
            }
        }
        return -1;
    }
};

//方法三：排序
//思路：可以先将数组进行排序，然后将看缺了哪一个
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums[0] != 0){
            return 0;
        }
        if(nums[nums.size() - 1] != nums.size()){
            return nums.size();
        }
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] - nums[i-1] == 1){
                continue;
            }
            return i;
        }
        return -1;
    }
};

//方法四：位运算
//思路：异或相同的数两次相当于没有异或，所以可以异或一次0~n，再异或所有nums中的数，最后可以得到缺少的数
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = nums.size();
        for(int i = 0; i < nums.size(); i++){
            missing ^= i ^ nums[i];
        }
        return missing;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = 0;
        for(int i = 0; i < nums.size(); i++){
            missing ^= i ^ nums[i];
        }
        return missing ^ nums.size();
    }
};
