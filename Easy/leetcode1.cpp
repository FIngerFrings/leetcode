/* 
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 * 你可以按任意顺序返回答案。
 */
//方法一：暴力法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> q;
        for(int i = 0; i < nums.size(); i++){
            q[nums[i]] = i;
        }
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        vector<int> ans(2, -1);
        while(l < r){
            if(nums[l] + nums[r] == target){
                ans[0] = q[nums[l]];
                ans[1] = q[nums[r]];
                return ans;
            }
            else if(nums[l] + nums[r] < target){
                ++l;
            }
            else{
                --r;
            }
        }
        return ans;
    }
};

//方法二：哈希表
//思路：遍历数组，查看哈希表中是否存在target-nums[i],存在则直接返回两个下标，不存在则将其加入哈希表并继续遍历
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for(int i = 0; i < nums.size(); i++){
            auto it = hashtable.find(target - nums[i]);
            if(it != hashtable.end()){
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};
