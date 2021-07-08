/* 给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。 */
//方法一：数组
//思路：用数组记录每个元素出现的个数，看最后1~n中哪些元素没出现
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> mem(n + 1);
        for(int k : nums){
            ++mem[k];
        }

        for(int i = 1; i <= n; i++){
            if(mem[i] == 0){
                ans.push_back(i);
            }
        }

        return ans;
    }
};

//用哈希表记录每个元素出现的次数，最后遍历1~n，哈希表中没有的就是没出现的元素
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> q;
        for(int num : nums){
            q[num]++;
        }
        for(int i = 1; i <= n; i++){
            if(q.count(i) == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

//方法二：原地修改
//思路：遍历数组中的每个元素，加入遍历到i，则将nums[i-1]变成-nums[i-1]，最后再遍历一次数组，如果nums[i]大于0，则说明i+1没有出现过
//需要注意的是因为会改变数组中的数，所以pos要取abs(k)+1
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int k : nums){
            int pos = abs(k) - 1;
            if(nums[pos] > 0){
                nums[pos] = -nums[pos];
            }
        }

        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
