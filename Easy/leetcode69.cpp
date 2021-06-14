/* 
 * 实现 int sqrt(int x) 函数。
 * 计算并返回 x 的平方根，其中 x 是非负整数。
 * 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
 */

//方法一：自己写的while循环
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
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)  return 0;
        long l = 1, r = x;
        while(l <= r){
            long mid = (l + r) / 2;
            long long num = mid * mid;
            if(num == x){
                return mid;
            }
            else if(num < x){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return l * l < x ? l : l - 1;
    }
};

//官方的二分查找，这种方法要记下来
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};

//方法二：牛顿迭代法
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
