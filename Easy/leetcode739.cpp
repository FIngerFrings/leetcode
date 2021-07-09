/*
 * 请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0 来代替。
 * 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是  [1, 1, 4, 2, 1, 1, 0, 0]。
 * 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100]  范围内的整数。
 */
//方法一：暴力法（超时）
//思路：略
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        for(int i = 0; i < n - 1; i++){
            for(int j = i; j < n; j++){
                if(temperatures[j] > temperatures[i]){
                    ans[i] = j - i;
                    break;
                }
            }
        }
        return ans;
    }
};
//官方的暴力解法，可以通过，其实思路确实是暴力
//因为温度范围为30~100，所以我们可以创建一个大小为101的数组用来记录每个数组第一次出现的位置
//这个数组叫next，初值都为INT_MAX，我们从后往前遍历数组，并从temperatures[i]开始遍历next数组，找到其中的最小值，如果遍历完后最小值不是INT_MAX
//说明在它后面有比他大的元素，将其记录在ans数组中，并更新next数组中temperatures[i]的值为i
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        vector<int> next(101, INT_MAX);
        for(int i = n - 1; i >= 0; i--){
            int min_len = INT_MAX;
            for(int j = temperatures[i] + 1; j <= 100; j++){
                min_len = min(min_len, next[j]);
            }
            if(min_len != INT_MAX){
                ans[i] = min_len - i;
            }
            next[temperatures[i]] = i;
        }
        return ans;
    }
};

//方法二：栈
//思路:因为最后一个元素的值肯定是0，所以不用考虑它并先把他压入栈中，然后从倒数第二个开始从后往前遍历数组，如果当前元素小于栈顶元素，则说明栈顶元素是距离当前元素最近的大于它的元素
//所以可以得到ans[i]的值，如果栈顶元素小于当前元素，则将它弹出，查看下一个元素是否大于当前元素。循环查找栈中是否有符合条件的元素，如果栈为空，则说明后面没有比当前元素大的元素
//因此值为0，查找完后要把当前元素压入栈中，用于后面的元素进行比较
//实际上我觉得是一种变向的暴力算法，只是去掉了一些不用的值
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<pair<int, int>> q;
        q.push({n-1, temperatures[n-1]});
        for(int i = n - 2; i >= 0; i--){
            while(!q.empty()){
                auto [j, n] = q.top();
                if(n > temperatures[i]){
                    ans[i] = j - i;
                    break;
                }
                else{
                    q.pop();
                }
            }
            q.push({i, temperatures[i]});
        }
        return ans;
    }
};
