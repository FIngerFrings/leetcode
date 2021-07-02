/* 统计所有小于非负整数 n 的质数的数量。 */
//方法一：暴力解法
//思路：我们可以遍历所有小于n的数是否是质数，而判断一个数是否是质数，可以遍历2到i-1，查看是否可以整除i。但是这样做会超时
class Solution {
public:
    bool isz(int a){
        for(int i = 2; i < a; i++){
            if(a % i == 0)  return false;
        }
        return true;
    }
    int countPrimes(int n) {
        if(n < 3)   return 0;
        int num = 0;
        for(int i = 2; i < n; i++){
            if(isz(i))  ++num;
        }
        return num;
    }
};

//考虑到如果 y 是 x 的因数，那么 x / y 也必然是 x 的因数，因此我们只要校验 y 或者 x / y 即可。
//而如果我们每次选择校验两者中的较小数，则不难发现较小数一定落在 [2, 根号x] 区间中，因此我们只需要枚举  [2, 根号x]  中的所有数即可
class Solution {
public:
    bool isz(int a){
        int h = sqrt(a);
        for(int i = 2; i <= h; i++){
            if(a % i == 0)  return false;
        }
        return true;
    }
    int countPrimes(int n) {
        if(n < 3)   return 0;
        int num = 0;
        for(int i = 2; i < n; i++){
            if(isz(i))  ++num;
        }
        return num;
    }
};

//方法二：埃氏筛法
//思路：如果一个数不是质数，则它的倍数一定不是质数
//如果一个数是质数，则它的倍数一定不是质数，所以我们可以遍历所有小于n的数
//同时遍历它所有小于n的倍数，最后可以得到有多少质数
class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrimes(n, 1);
        int ans = 0;
        for(int i = 2; i < n; i++){
            if(isPrimes[i]){
                ans += 1;
                if((long) i * i < n){
                    for(long j = i * i; j < n; j += i){
                        isPrimes[j] = 0;
                    }
                }
            }
        }
        return ans;
    }
};
