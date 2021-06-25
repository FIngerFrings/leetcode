/*
 * 数组 A 包含 N 个数，且索引从0开始。数组 A 的一个子数组划分为数组 (P, Q)，P 与 Q 是整数且满足 0<=P<Q<N 。
 * 如果满足以下条件，则称子数组(P, Q)为等差数组：
 * 元素 A[P], A[p + 1], ..., A[Q - 1], A[Q] 是等差的。并且 P + 1 < Q 。
 * 函数要返回数组 A 中所有为等差数组的子数组个数。
 */
//方法一：暴力解法
//思路：将所有子数组列出来并判断是否是等差数列，如果是则数量+1
class Solution {
public:
    bool isSlices(vector<int>& nums, int i, int j){
        if(j - i < 2)   return false;
        for(int k = i + 1; k <= j; k++){
            if((nums[k] - nums[k-1]) != (nums[i+1] - nums[i])){
                return false;
            }
        }   
        return true;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)   return 0;
        int num = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(isSlices(nums, i, j)){
                    ++num;
                }
            }
        }
        return num;
    }
};

//方法二：优雅的暴力解法
//思路：上面的暴力解法有很多重复的判断，例如当判断完区间(s, e)是否是等差数列后，当要判断(s, e + 1)时需要重新遍历一遍，然而实际上只需要判断e+1和e的差是否和前面相等即可
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int num = 0;
        for(int i = 0; i < n - 2; i++){
            int d = nums[i + 1] - nums[i];
            for(int j = i + 2; j < n; j++){
                if(nums[j] - nums[j-1] == d){
                    ++num;
                }
                else{
                    break;
                }
            }
        }
        return num;
    }
};
