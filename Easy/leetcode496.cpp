/*
 *给你两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。
 *请你找出 nums1 中每个元素在 nums2 中的下一个比其大的值。
 *nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 -1 。
*/
//方法一：硬解，但是时间复杂度高
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> q;
        for(int i = 0; i < nums1.size(); i++){
            int max = -1;
            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    for(int k = j+1; k < nums2.size(); k++){
                        if(nums2[k] > nums2[j]){
                            max = nums2[k];
                            break;
                        }
                    }
                }
            }
            q.push_back(max);
        }
        return q;
    }
};

//方法二：思路为
