/*
 * 给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。
 * （当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）
 */
//方法一：暴力
//思路：递减，判断数据是否是递增的
class Solution {
    bool isValid(int num){
        int max = 10;
        while(num){
            int t = num % 10;
            if(max >= t) max = t;
            else return false;
            num /= 10;
        }
        return true;
    }
public:
    int monotoneIncreasingDigits(int n) {
        for(int i = n; i >= 0; i--){
            if(isValid(i))  return i;
        }
        return 0;
    }
};

//方法二：贪心
//思路：一旦出现strNum[i - 1] > strNum[i]的情况（非单调递增），首先想让strNum[i - 1]--，然后strNum[i]给为9
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string nums = to_string(n);
        int flag = nums.size();
        for(int i = nums.size() - 1; i > 0; i--){
            if(nums[i-1] > nums[i]){
                flag = i;
                nums[i-1]--;
            }
        }

        for(int i = flag; i < nums.size(); i++){
            nums[i] = '9';
        }
        return stoi(nums);
    }
};
