/* 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。*/
//方法一：回溯法
//思路：和之前的回溯法一样，都是测试数组中某个元素在子集中和不在子集中的情况，然后不断递归
//只是需要注意的是结束条件是子集的大小为k的时候。下面已经解释了为什么第三个if语句不需要
//为了节省时间，当t.size()加上后面所有的元素都不够k个的时候，可以直接返回了
class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    void backtacking(int curr, int n, int k){
        if(t.size() + (n - curr + 1) < k){
            return;
        }
        if(t.size() == k){
            ans.push_back(t);
            return;
        }
        
        //实际上这个if判断语句不需要，因为如果当curr=n+1的时候，肯定不会出现t.size()大于k的情况，因为当t.size()=k的时候就会直接返回
        //同时，也不会出现t.size()小于k的情况，因为这种情况会直接被第一个if语句截胡
        if(curr == n+1){
            return;
        }

        t.push_back(curr);
        backtacking(curr+1, n, k);
        t.pop_back();
        backtacking(curr+1, n, k);

    }

    vector<vector<int>> combine(int n, int k) {
        backtacking(1, n, k);
        return ans;
    }
};
