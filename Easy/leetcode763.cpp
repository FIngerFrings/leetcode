/* 字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。*/
//方法一：贪心
//思路：我们可以记录每个字母出现的最后位置，之后遍历字符串，寻找每个片段可能的最小结束下标
//我们可以先定义两个变量，分别是开始下标和结束下标，初始化为0.在遍历的过程中，如果我们发现更大的结束下标，则更新结束下标
//并判断当前是否已经到了结束下标，如果到了结束下标，说明已经到了一个片段，可以重新开始一个片段，并将结果插入数组中
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        if(n == 0)   return {};
        unordered_map<char, int> q;
        for(int i = 0; i < n; i++){
            q[s[i]] = i;
        }
        int l = 0, r = 0;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            r = max(r, q[s[i]]);
            if(i == r){
                ans.push_back(r - l + 1);
                l = r + 1;
                r = l;
            }
        }
        return ans;
    }
};
//这道题贪心的地方在于每次都选择可能的最短片段。并且在处理数组前，统计一遍信息（如频率、个数、第一次出现位置、最后一次出现位置等）可能可以使题目难度大幅降低。  

//代码随想录贪心，更好一点
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> nums(26, 0);
        for(int i = 0; i < s.size(); i++){
            nums[s[i]-'a'] = i;
        }
        vector<int> ans;
        int l = 0, r = 0;
        for(int i = 0; i < s.size(); i++){
            r = max(r, nums[s[i]-'a']);
            if(i == r){
                ans.push_back(r - l + 1);
                l = i + 1;
            }   
        }
        return ans;
    }
};
