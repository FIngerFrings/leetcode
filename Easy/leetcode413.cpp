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

//方法三:动态规划
//思路：如果nums[i] - nums[i-1] == nums[i-1] - nums[i-2]，则以nums[i]结尾的等差队列个数为以nums[i-1]结尾的等差队列个数+1
//否则为0
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)   return 0;
        vector<int> dp(n);
        for(int i = 2; i < n; i++){
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
                dp[i] = dp[i-1] + 1;
            }
            else{
                dp[i] = 0;
            }
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};

//压缩空间后的dp
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)   return 0;
        int pre1 = 0, curr;
        int sum = 0;
        for(int i = 2; i < n; i++){
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
                curr = pre1 + 1;
                pre1 = curr;
            }
            else{
                pre1 = 0;
            }
            sum += pre1;
        }
        return sum;
    }
};

//方法四：递归
//递归：从数组最后递归到前面，其实基本思路和动态规划差不多，只不过方向不一样
class Solution {
public:
    int sum = 0;
    int numberOfArithmeticSlices(vector<int>& nums) {
        Slices(nums, nums.size()-1);
        return sum;
    }

    int Slices(vector<int>& nums, int i){
        if(i < 2)   return 0;
        int temp = 0;
        //如果满足递归，则以当前元素结尾的等差数列个数为前一个元素的个数+1
        //否则为0，但还是需要继续递归下去
        if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
            temp = 1 + Slices(nums, i-1);
            sum += temp;
        }
        else{
            Slices(nums, i-1);
        }
        return temp;
    }
};
