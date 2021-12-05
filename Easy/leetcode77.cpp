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
        //这个判断条件是没想到的，可以减少计算次数
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

//代码随想录回溯
class Solution {
public:
    void backtracking(vector<vector<int>> &ans, vector<int> &nums, int n, int k, int pos){
        if(nums.size() == k){
            ans.push_back(nums);
            return;
        }

        for(int i = pos; i <= n; i++){
            nums.push_back(i);
            backtracking(ans, nums, n, k, i + 1);
            nums.pop_back();
        }

        return;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> nums;
        backtracking(ans, nums, n, k, 1);
        return ans;
    }
};

//回溯优化
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void backtracking(int n, int k, int cur){
        if(path.size() == k){
            ans.push_back(path);
            return;
        }

        for(int i = cur; i <= n - (k - path.size()) + 1; i++){
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
        return;
    }

    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return ans;
    }
};

//方法二：非递归（字典序法）实现组合型枚举，
//思路：实际上就和leetcode78中的mask解法一样，只不过这里因为限定了k个数，所以mask并不能像leetcode78中一样直接+1，而是有一定规律的
//规律如下：表示数组的二进制数的最低位为1时，如果末尾有t个连续的1，则直接将倒数第t位的1和倒数第t+1位的0替换
//如果最低位为0，假设末尾有t个连续的0，这t个连续的0前面有m个连续的1，则将倒数第t+m位的1和倒数t+m+1位的0对换，然后将后面连续的1全部移动到最低位
//以上就是mask的增加方式。在实际实现中，我们实际上是从低到高的找第一个j，使得t[j]+1 != t[j+1]，这说明t[j]和t[j+1]之间是有0的，因此我们就可以将t[j]+1，然后后面连续的1移动到最后
//在本题中，我们使用t来临时保存子集，其中最重要的一环就是如何判断全部枚举完了，我们使用的是将t的第k位保存为n+1，当通过寻找发现第一个j=k时，就说明到最后了
class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;
    
    vector<vector<int>> combine(int n, int k) {
        //1. 首先将前k位放进t中
        for(int i = 1; i <= k; i++){
            t.emplace_back(i);
        }
        
        //2. 将n+1保存在t的第k位，方便判断循环的终止条件
        t.emplace_back(n+1);
        int j = 0;
        while(j < k){
            //3. 将t的前k位插入ans
            ans.emplace_back(t.begin(), t.begin()+k);
            
            //记得将j复位
            j = 0;
            //将mask移动到下一位
            while(j < k && t[j]+1 == t[j+1]){
                t[j] = j+1;
                j++;
            }

            ++t[j];
        }
        return ans;
    }
};
