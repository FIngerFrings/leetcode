/* 
 * 给定一个已按照 升序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target 。
 * 函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。numbers 的下标 从 1 开始计数 ，所以答案数组应当满足 1 <= answer[0] < answer[1] <= numbers.length 。
 * 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
 */
//方法一：暴力解法，超出了时间限制
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0, r = 1;
        vector<int> ans;
        while(l < n-1){
            if(numbers[l] + numbers[r] == target){
                ans.push_back(l+1);
                ans.push_back(r+1);
                return ans;
            }
            else if(r == n-1){
                l++;
                r = l+1;                
            }
            else{
                r++;
            }
        }
        return ans;
    }
};

//方法二：双指针
//思路：略
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0, r = n-1;
        vector<int> ans;
        while(l < r){
            if(numbers[l] + numbers[r] == target){
                ans.push_back(l+1);
                ans.push_back(r+1);
                return ans;
            }
            else if(numbers[l] + numbers[r] < target){
                l++;
            }
            else{
                r--;
            }
        }
        return {};
    }
};

//方法三：二分查找
//思路：首先固定较小的数，然后使用二分查找搜索右边的数
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i = 0; i < n; i++){
            int l = i+1, r = n - 1;
            while(l <= r){
                int mid = (l + r) / 2;
                if(numbers[mid] == target - numbers[i]){
                    return {i+1, mid+1};
                }
                else if(numbers[mid] < target - numbers[i]){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
        }
        return {-1, -1};
    }
};
