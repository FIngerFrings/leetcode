/* 
 * 给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
 * 提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。
 * 说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
 * 进阶：
 * 你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
 */
//方法一：除法
//思路：首先想到的就是算出所有数的乘积，然后除以nums[i]
//但是对于有0的情况，这种方法不能用
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sum = 1;
        for(int k : nums){
            sum *= k;
        }

        vector<int> ans(nums.size(), sum);
        for(int i = 0; i < nums.size(); i++){
            ans[i] /= nums[i];
        }
        return ans;
    }
};

//方法二：暴力法
//思路：遍历两遍数组，超时
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j == i)  continue;
                if(nums[j] == 0){
                    ans[i] = 0;
                    break;
                }
                ans[i] *= nums[j];
            }
        }
        return ans;
    }
};

//方法三：三次for循环
//思路：用right[i]记录nums[i]右边所有数的乘积，用left[i]记录nums[i]左边所有数的乘积
//最后将两个数组相乘即可得到结果
//不过时间复杂度比较高
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> right(n, 1);
        vector<int> left(n, 1);
        vector<int> ans(n);
        for(int i = 1; i < n; i++){
            left[i] = left[i-1] * nums[i-1];
        }

        for(int i = n-2; i >= 0; i--){
            right[i] = right[i+1] * nums[i+1];
        }

        for(int i = 0; i < n; i++){
            ans[i] = right[i] * left[i];
        }

        return ans;

    }
};

//实际上只需要两次for循环即可，得到right后就能计算ans了
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> right(n, 1);
        vector<int> left(n, 1);
        vector<int> ans(n);
        for(int i = 1; i < n; i++){
            left[i] = left[i-1] * nums[i-1];
        }

        for(int i = n-2; i >= 0; i--){
            right[i] = right[i+1] * nums[i+1];
            ans[i] = right[i] * left[i];
        }
        ans[n-1] = left[n-1];
        return ans;

    }
};

//思路和前面一样，不过空间复杂度更低
//只需要一个数组即可，使用R记录右边的乘积
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = 1;
        for(int i = 1; i < n; i++){
            ans[i] = ans[i-1] * nums[i-1];
        }

        int R = nums[n-1];
        for(int i = n - 2; i >= 0; i--){
            ans[i] *= R;
            R *= nums[i];
        }
        return ans;
    }
};

