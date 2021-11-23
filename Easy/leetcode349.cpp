/* 给定两个数组，编写一个函数来计算它们的交集。 */
//方法一：哈希表
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> iSet;
        vector<int> ans;
        for(int num : nums1){
            iSet.insert(num);
        }

        for(int num : nums2){
            if(iSet.count(num) > 0){
                ans.push_back(num);
                iSet.erase(num);
            }
        }
        return ans;
    }
};

//下面是代码随想录的方法，比较高级
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> iSet1(nums1.begin(), nums1.end());
        unordered_set<int> iSet2;
        for(int i : nums2){
            if(iSet1.find(i) != iSet1.end()){
                iSet2.insert(i);
            }
        }
        return vector<int>(iSet2.begin(), iSet2.end());
    }
};

//方法二：排序+双指针
//首先对两个数组进行排序，然后两个指针分别指向两个数组头，在遍历两个数组的过程中，如果两个指针指向的数相等
//则判断这个数之前是否有添加过，如果没有就加入返回数组中，之后两个指针都向后移动
//如果两个数不相等，则将较小的那个指针向后移动
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int l = 0, r = 0;
        vector<int> ans;
        while(l < m && r < n){
            int i = nums1[l], j = nums2[r];
            if(i == j){
                if(ans.empty() || i != ans.back()){
                    ans.push_back(i);
                }
                ++l;
                ++r;
            }
            else if(i < j){
                ++l;
            }
            else{
                ++r;
            }
        }
        return ans;
    }
};
