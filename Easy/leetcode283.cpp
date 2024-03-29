//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序
//方法一：双指针
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
/*
 * 使用双指针，左指针指向当前已经处理好的序列的尾部，右指针指向待处理序列的头部。
 * 右指针不断向右移动，每次右指针指向非零数，则将左右指针对应的数交换，同时左指针右移。
 * 注意到以下性质：
 * 左指针左边均为非零数；
 * 右指针左边直到左指针处均为零。
 * 因此每次交换，都是将左指针的零与右指针的非零数交换，且非零数的相对顺序并未改变。
*/
//实际上与我的做法类似，我的做法中count实际上就是左指针，但答案比较好，不需要比较left和right
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        while (right < n) {
            if (nums[right]) {
                swap(nums[left], nums[right]);  //交换两个数可以用swap函数
                left++;
            }
            right++;    //只要遇到0，则right和left就会分开
        }
    }
};

//类似26的双指针
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                nums[l] = nums[i];
                ++l;
            }
        }
        for(int i = l; i < nums.size(); i++){
            nums[i] = 0;
        }
    }
};

//使用swap后就不用再遍历一次
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i], nums[l]);
                ++l;
            }
        }
    }
};
