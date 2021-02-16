//给定一个二进制数组， 计算其中最大连续 1 的个数。
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0, count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                count++;
            } else {
                maxCount = max(maxCount, count);  //比较两个值的大小可以用max函数，而不是用if
                count = 0;
            }
        }
        maxCount = max(maxCount, count);  //我的做法是for循环每次都更新最大值，而这里是最后再更新
        return maxCount;
    }
};

//基本上思路与我的相同
//以下是我的做法

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxsize = 0;
        int size = 0;
        int numssize = nums.size();
        for(int i = 0; i < numssize; i++){
            if(nums[i] == 1){
                size++;
            }
            else{
                if(maxsize < size){
                    maxsize = size;
                }
                size = 0;
            }
            if(maxsize < size){
                    maxsize = size;
                }
        }
        return maxsize;
    }
};
