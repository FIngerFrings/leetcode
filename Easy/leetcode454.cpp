/*
 * 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：
 * 0 <= i, j, k, l < n
 * nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 */
//方法一：分组+哈希表
//思路：将nums1和nums2分为一组，nums3和nums4分为一组，然后计算nums1+nums2的所有可能情况，并用哈希表记录，之后再去计算nums3和nums4的所有情况，看是否能与nums1+nums2的结果相加为零
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> hash;
        int ans = 0;
        for(int i : nums1){
            for(int j : nums2){
                ++hash[i + j];
            }
        }

        for(int i : nums3){
            for(int j : nums4){
                if(hash.count(-i-j)){
                    ans += hash[-i-j];
                }
            }
        }
        return ans;
    }
};
