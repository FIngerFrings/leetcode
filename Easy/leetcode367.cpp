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
