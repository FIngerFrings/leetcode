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

//方法二：排序
//思路：排完序后的数组，对于只出现1次的元素，其前后元素肯定和它不同，头和尾元素要单独讨论
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        if(nums[0] != nums[1]){
            ans.push_back(nums[0]);
        }
        if(nums[n - 1] != nums[n - 2]){
            ans.push_back(nums[n-1]);
        }
        for(int i = 1; i < n - 1; i++){
            if(ans.size() == 2){
                return ans;
            }

            if(nums[i-1] != nums[i] && nums[i] != nums[i + 1]){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

//方法四：位运算
//思路：如果只有1个数字是只出现1次的，那么可以将所有数异或，最后得到的结果就是那个只出现1次的数
//但是这里有两个数是只出现1次的，我们可以将他们分开放在两个数组中，同时相同的数组会出现在同一个数组中
//这样我们就分成了两个数组，每个数组异或最后就可以得到所要求的两个数字
//那怎样划分呢？我们将所有数组异或得到的结果就是a和b异或的结果（a和b就是那两个只出现1次的数字）
//异或的结果中二进制位为1，说明a和b在这一位不同，我们可以将所有数字中，这位为1的划分为1组，为0的划分为另一组，这样就可以根据要求划分两个数组
//最后两个数组分别异或，分别可以得到那个出现一次的数字
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum = 0;
        for(int num : nums){
            sum ^= num;
        }
        int div = 1;
        while((div & sum) == 0){
            div <<= 1;
        }
        int a = 0;
        int b = 0;
        for(int num : nums){
            if((num & div) == 0){
                a ^= num;
            }
            else{
                b ^= num;
            }
        }
        return vector<int>{a, b};
    }
};
