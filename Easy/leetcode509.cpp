/* 斐波那契数，通常用 F(n) 表示，形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
 * F(0) = 0，F(1) = 1, F(n) = F(n - 1) + F(n - 2)，其中 n > 1
 */
//方法一，递归，不解释
class Solution {
public:
    int fib(int n) {
        if(n < 2){
            return n;
        }
        else{
            return fib(n-2) + fib(n-1);
        }
    }
};

class Solution {
public:
    int fib(int n) {
        if(n < 2)   return n;
        return fib(n - 1) + fib(n - 2);
    }
};


//方法二，动态规划
class Solution {
public:
    int fib(int n) {
        if(n < 2){
            return n;
        }
        int *nums = new int[n + 1];
        nums[0] = 0;
        nums[1] = 1;
        for(int i = 2; i <= n; i++){
            nums[i] = nums[i-1] + nums[i-2];
        }
        return nums[n];
    }
};

class Solution {
public:
    int fib(int n) {
        if(n < 2){
            return n;
        }
        int p = 0, q = 0, r = 1;
        for(int i = 2; i <= n; i++){
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
};

//两种动态规划其实原理是相同的

//方法三：记忆化搜索
//思路还是递归+动态规划，用一个数组来存放之前计算过的结果
//但是这里我觉得记忆化搜索反而比较复杂，不过速度确实快
class Solution {
public:
    vector<int> count;
    int dp(int n){
        if(count[n] != INT_MIN){
            return count[n];
        }
        else{
            count[n] = dp(n - 1) + dp(n - 2);
        }
        return count[n];
    }
    int fib(int n) {
        count.resize(n + 1, INT_MIN);
        if(n < 2)   return n;
        count[0] = 0;
        count[1] = 1;
        return dp(n);
    }
};
