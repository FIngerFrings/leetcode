/*给定一个整数数组，判断是否存在重复元素。
 *如果存在一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。
 */
//方法一：自己的做法，在一开始的注释部分为暴力解法，结果超时，该方法与答案的哈希表方法一样
//之后用哈希表，因为哈希表查找速度快，首先是判断当前元素是否存在哈希表中，如果有说明重复，返回false，否则将其插入哈希表，键为当前元素，值为1
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // for(int i = 0; i < nums.size(); i++){
        //     for(int j = i+1; j < nums.size(); j++){
        //         if(nums[i] == nums[j]){
        //             return true;
        //         }
        //     }
        // }
        // return false;
        unordered_map<int, int> hx;
        for(int i = 0; i < nums.size(); i++){
            if(hx.count(nums[i])){
                return true;
            }
            else{
                hx[nums[i]] = 1;
            }
        }
        return false;
    }
};
//方法二，利用排序，首先对nums进行排序，之后遍历nums，如果有重复的元素，则会在相邻位置，所以只要判断相邻位置是否重复，就可以判断整个数组是否重复
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end()); //begin返回数组第一个元素的地址，end返回最后一个元素+1的地址，sort对这个范围进行排序
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] == nums[i+1])
                return true;
        }
        return false;
    }
};
