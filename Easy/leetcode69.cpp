/* 
 * 实现 int sqrt(int x) 函数。
 * 计算并返回 x 的平方根，其中 x 是非负整数。
 * 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
 */
//实际上就是在0到x-1范围内，寻找一个数ans使得ans*ans第一个小于等于x，所以可以用二分查找的方法

//方法一：暴力
//思路：通过while循环得到i
class Solution {
public:
    int mySqrt(int x) {
        long i = 1;
        while(i * i <= x){
            ++i;
        }
        return i * i == x ? i : i - 1;
    }
};

//方法二：二分查找
//思路：在1到x内二分查找
//代码随想录二分法
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while(l <= r){
            long long mid = l + (r - l) / 2;
            if(mid * mid == x){
                return mid;
            }
            else if(mid * mid > x){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return r;
    }
};

//方法三：牛顿迭代法
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)  return 0;
        double C = x, x0 = x;
        while(true){
            double xi = 0.5 * (x0 + C / x0);
            if(fabs(xi - x0) <= 1e-7){
                break;
            }
            x0 = xi;
        }
        return (int)x0;
    }
};

//方法四：袖珍计算器
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int ans = exp(0.5 * log(x));
        return (long long)(ans + 1) * (ans + 1) <= x ? ans + 1 : ans;
    }
};
