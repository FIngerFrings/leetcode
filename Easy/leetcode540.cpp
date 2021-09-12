// 给定一个只包含整数的有序数组，每个元素都会出现两次，唯有一个数只会出现一次，找出这个数。 //
//方法一：加法
//思路：略
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i % 2 == 0){
                sum += nums[i];
            }
            else{
                sum -= nums[i];
            }
        }
        return sum >= 0 ? sum : -sum;
    }
};

//方法二：暴力法
//思路：略
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i+=2){
            if(nums[i] != nums[i+1]){
                return nums[i];
            }
        }
        return nums.back();
    }
};
