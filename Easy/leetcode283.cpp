//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序
//自己的做法，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                nums[count] = nums[i];
                if(count != i){
                    nums[i] = 0;
                }
                count++;
            }
        }
    }
};

//答案
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        while (right < n) {
            if (nums[right]) {
                swap(nums[left], nums[right]);  //交换两个数可以用swap函数
                left++;
            }
            right++;
        }
    }
};
