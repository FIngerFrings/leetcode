/*
 * 给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。
 */
//方法一：使用哈希表记录每个数出现的次数
//思路：同题目
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int ,int> q;
        for(int k : nums){
            q[k] += 1;
        }
        vector<int> ans;
        for(int k : nums){
            if(q[k] == 1){
                ans.push_back(k);
            }
        }
        return ans;
    }
};
