/*
 * 如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列 。第一个差（如果存在的话）可能是正数或负数。仅有一个元素或者含两个不等元素的序列也视作摆动序列。
 * 例如， [1, 7, 4, 9, 2, 5] 是一个 摆动序列 ，因为差值 (6, -3, 5, -7, 3) 是正负交替出现的。
 * 相反，[1, 4, 7, 2, 5] 和 [1, 7, 4, 5, 5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。
 * 子序列 可以通过从原始序列中删除一些（也可以不删除）元素来获得，剩下的元素保持其原始顺序。
 * 给你一个整数数组 nums ，返回 nums 中作为 摆动序列 的 最长子序列的长度 。
 */
//方法一：动态规划
//思路：dp[i][0]表示前i个元素中以某一元素结尾且最后上升的最长子序列长度，dp[i][1]表示前i个元素中以某一元素结尾且最后下降的最长子序列长度
//因为1个元素既可以是结尾上升子序列，也可以是结尾下降子序列，所以dp[0][0]和dp[0][1]都是1
//在遍历过程中，如果nums[i] > nums[i-1]，则其对前面的最长结尾下降子序列不会有影响
//但是最长结尾上升子序列可能有两种情况，具体的这里也说不清，详见官方解答
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return 1;
        if(n == 2)  return nums[0] != nums[1] ? 2 : 1;
        vector<vector<int>> dp(n, vector<int>(2, 1));
        dp[0][0] = 1;
        dp[0][1] = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                dp[i][0] = max(dp[i-1][0], dp[i-1][1] + 1);
                dp[i][1] = dp[i-1][1];
            }
            else if(nums[i] < nums[i-1]){
                dp[i][1] = max(dp[i-1][1], dp[i-1][0] + 1);
                dp[i][0] = dp[i-1][0];
            }
            else{
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1];
            }
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};

//压缩空间的动态规划
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return 1;
        if(n == 2)  return nums[0] != nums[1] ? 2 : 1;
        int down = 1;
        int up = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                up = max(up, down + 1);
            }
            else if(nums[i] < nums[i-1]){
                down = max(down, up + 1);
            }
        }
        return max(up, down);
    }
};

//方法二：贪心算法
//思路：实际上我们只需要计算有多少个峰和谷就可以算法最长子序列了
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)   return n;
        int prediff = nums[1] - nums[0];
        int ret = prediff != 0 ? 2 : 1;
        for(int i = 2; i < n; i++){
            int diff = nums[i] - nums[i-1];
            if((diff > 0 && prediff <= 0) || (diff < 0 && prediff >= 0)){
                ++ret;
                prediff = diff;
            }
        }
        return ret;
    }
};
