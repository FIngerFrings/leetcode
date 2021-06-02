/* 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。*/
//方法一：回溯法
//思路：就和回溯法的思路一样，这道题可以理解为要想找出所有可能的全排列，就先设置一个个数为n的空数组，然后依次填入可能的数值
//在具体实现中可以看到有个for循环，就是依次将后面的还没填入的数填入，然后再递归考虑之后的情况，考虑完后还要换回来
class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, int first, int length){
        if(first == length){
            ans.push_back(nums);
            return;
        }

        for(int i = first; i < length; i++){
            swap(nums[i], nums[first]);
            backtrack(nums, first+1, length);
            swap(nums[i], nums[first]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0, nums.size());
        return ans;
    }
};
