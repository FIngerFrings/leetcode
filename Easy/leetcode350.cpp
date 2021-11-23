/* 给定两个数组，编写一个函数来计算它们的交集。 */
//方法一：哈希表
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;
        for(int i : nums1){
            hash[i]++;
        }
        vector<int> ans;
        for(int i : nums2){
            if(--hash[i] >= 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

//方法二：排序+双指针
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int l = 0, r = 0;
        vector<int> ans;
        while(l < nums1.size() && r < nums2.size()){
            if(nums1[l] == nums2[r]){
                ans.push_back(nums1[l]);
                ++l;
                ++r;
            }
            else if(nums1[l] < nums2[r]){
                ++l;
            }
            else{
                ++r;
            }
        }
        return ans;
    }
};
