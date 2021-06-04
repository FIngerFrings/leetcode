/* 
 * 给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 判断你是否能够到达最后一个下标。
 */
//方法一：贪心算法
//思路：计算数组中每个元素能到达的最远距离，如果在能到达的范围内的元素能到达最后一个下标，则返回true。通过遍历，如果发现数组中的某个下标到达不了，则说明后面的下标也到达不了
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxposition = 0;
        for(int i = 0; i < n; i++){
            if(i <= maxposition){
                maxposition = max(maxposition, nums[i] + i);
                if(maxposition >= n-1){
                    return true;
                }
            }
            else{
                return false;
            }
        }
        return false;
    }
};
