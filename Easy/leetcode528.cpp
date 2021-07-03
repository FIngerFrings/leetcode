/*
 * 给定一个正整数数组 w ，其中 w[i] 代表下标 i 的权重（下标从 0 开始），请写一个函数 pickIndex ，它可以随机地获取下标 i，选取下标 i 的概率与 w[i] 成正比。
 *例如，对于 w = [1, 3]，挑选下标 0 的概率为 1 / (1 + 3) = 0.25 （即，25%），而选取下标 1 的概率为 3 / (1 + 3)  = 0.75（即，75%）。
 * 也就是说，选取下标 i 的概率为 w[i] / sum(w) 。
 */
//方法一：我也不知道什么方法
//思路：我们可以先计算前缀和（即到每个位置为止之前所有数字的和），这个结果对于正整数数组是单调递增的。每当需要采样时，我们可以先随机产生一个数字，然后使用二分
//法查找其在前缀和中的位置，以模拟加权采样的过程。这里的二分法可以用 lower_bound 实现。
class Solution {
    vector<int> sum;
public:
    Solution(vector<int>& w) {
        sum = w;
        for(int i = 1; i < sum.size(); i++){
            sum[i] = sum[i-1] + sum[i];
        }
    }
    
    int pickIndex() {
        int pos = rand() % sum.back() + 1;
        int l = 0, r = sum.size() - 1, ans;
        while(l <= r){
            int mid = (l + r) / 2;
            if(sum[mid] >= pos){
                r = mid - 1;
                ans = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
