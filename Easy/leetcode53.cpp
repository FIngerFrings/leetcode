/* 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。*/
//方法一，暴力解法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        int maxnum = INT_MIN;
        for(int i = 0; i < n; i++){
            int sum = 0;
            int max = INT_MIN;
            for(int j = i; j < n; j++){
                sum += nums[j];
                if(sum > max){
                    max = sum;
                }
            }
            if(max > maxnum){
                maxnum = max;
            }
        }
        return maxnum;
    }
};

//方法二，动态规划
//假设 \textit{nums}nums 数组的长度是 nn，下标从 0 到 n-1。我们用 f(i)代表以第 i 个数结尾的「连续子数组的最大和」
//因此我们只需要求出每个位置的 f(i)，然后返回 f数组中的最大值即可。那么我们如何求 f(i) 呢？我们可以考虑 nums[i] 
//单独成为一段还是加入f(i−1) 对应的那一段，这取决于nums[i] 和 f(i-1) + nums[i] 的大小，我们希望获得一个比较大的，于是可以写出这样的动态规划转移方程：
//f(i)=max(f(i-1)+nums[i]), nums[i])
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxans = nums[0];
        for(const auto &x : nums){
            pre = max(pre + x, x);
            maxans = max(maxans, pre);
        }
        return maxans;
    }
};

//方法三，分治
//具体的还是去看官方解释，太多了
class Solution {
public:
    struct Status {
        int lSum, rSum, mSum, iSum;
    };

    Status pushUp(Status l, Status r) {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return (Status) {lSum, rSum, mSum, iSum};
    };

    Status get(vector<int> &a, int l, int r) {
        if (l == r) {
            return (Status) {a[l], a[l], a[l], a[l]};
        }
        int m = (l + r) >> 1;
        Status lSub = get(a, l, m);
        Status rSub = get(a, m + 1, r);
        return pushUp(lSub, rSub);
    }

    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};
