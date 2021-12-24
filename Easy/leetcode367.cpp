/* 给定一个 正整数 num ，编写一个函数，如果 num 是一个完全平方数，则返回 true ，否则返回 false 。 */
//方法一：二分查找
//思路：其实和69一样，不过如果在循环过程中没找到则返回false
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        while(l <= r){
            long long mid = l + (r - l) / 2;
            if(mid * mid == num) return true;
            else if(mid * mid > num) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};

//方法二：内置函数
class Solution {
public:
    bool isPerfectSquare(int num) {
        int ans = sqrt(num);
        return ans * ans == num;
    }
};

//方法三：暴力
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long x = 1;
        while(x * x <= num){
            if(x * x == num){
                return true;
            }
            ++x;
        }
        return false;
    }
};

//方法四：牛顿迭代法
class Solution {
public:
    bool isPerfectSquare(int num) {
        double c = num, x0 = num;
        while(true){
            double xi = 0.5 * (x0 + c / x0);
            if(abs(xi - x0) <= 1e-7){
                break;
            }
            x0 = xi;
        }
        x0 = (long long)x0;
        return x0 * x0 == num;
    }
};
