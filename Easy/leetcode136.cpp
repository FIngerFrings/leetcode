/*
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 */
//方法一：使用哈希表记录出现次数
//思路：略
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> q;
        for(int num : nums){
            q[num] += 1;
        }

        for(int num : nums){
            if(q[num] == 1){
                return num;
            }
        }
        return -1;
    }
};

//方法二：异或
//思路：将数组中的所有数进行异或处理，相同的数异或为0，所以最后的结果就是只出现依次的元素
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int k : nums){
            ans ^= k;
        }
        return ans;
    }
};
