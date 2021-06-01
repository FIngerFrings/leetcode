/* 
 * 给你一个整数数组nums ，数组中的元素互不相同。返回该数组所有可能的子集（幂集）。
 * 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 */
//方法一：迭代法实现子集枚举
//思路：原序列中的每个数字ai的状态可能有两种，即在子集中和不在子集中，我们用1表示在子集中，0表示不在子集中，那么每一个子集可以对应一个长度为n的0/1序列，第i位表示ai是否在子集中
//假设给的数组有n个元素，则可以用n位二进制表示这个数组，ai存在子集中则二进制数中对应位就为1，否则为0，可以发现，0/1序列对应的二进制数正好从0到2^n-1。
//我们可以按照这个0/1序列在原集合中取数，就能取出所有的子集了
class Solution {
public:
    vector<int> t;
    vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        for(int mask = 0; mask < (1 << n); mask++){
            t.clear();        //记得要清理t
            for(int i = 0; i < n; i++){
                if(mask & (1 << i)){    //这种按位与的方法要记住
                    t.push_back(nums[i]);
                }
            }
            result.push_back(t);
        }
        return result;
    }
};
//这种方法真的很巧妙
