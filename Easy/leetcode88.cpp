/* 
 * 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1 的空间大小等于 m + n，这样它就有足够的空间保存来自 nums2 的元素。
 */
//方法一：直接合并后排序
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = 0; i < n; i++){
            nums1[m + i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};

//方法二：双指针
//思路：遍历两个数组，按大小插入另一个数组，然后将这个数组复制给nums1
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0)  return;
        vector<int> ans;
        int p1 = 0, p2 = 0;
        while(p1 < m || p2 < n){
            if(p1 == m){
                ans.push_back(nums2[p2]);
                ++p2;
            }
            else if(p2 == n){
                ans.push_back(nums1[p1]);
                ++p1;
            }
            else if(nums1[p1] < nums2[p2]){
                ans.push_back(nums1[p1]);
                ++p1;
            }
            else{
                ans.push_back(nums2[p2]);
                ++p2;
            }
        }
        for(int i = 0; i < m + n; i++){
            nums1[i] = ans[i];
        }
    }
};

//方法三：逆向双指针
//思路：可以直接从后往前遍历，先填较大的数
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1, p = m + n - 1;
        while(p >= 0){
            if(p2 == -1){
                nums1[p] = nums1[p1];
                --p;
                --p1;
            }
            else if(p1 == -1){
                nums1[p] = nums2[p2];
                --p;
                --p2;
            }
            else if(nums1[p1] > nums2[p2]){
                nums1[p] = nums1[p1];
                --p;
                --p1;
            }
            else{
                nums1[p] = nums2[p2];
                --p;
                --p2;
            }
        }
    }
};
