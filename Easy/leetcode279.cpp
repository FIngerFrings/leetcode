/* 
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 * 给你一个整数 n ，返回和为 n 的完全平方数的 最少数量 。
 * 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。
 */
//方法一：暴力法
//思路：一个直观的解决方案是使用暴力枚举法，我们枚举所有可能的组合，并找到完全平方数的个数最小的一个。
//整个解法基于以下式子：numSquare(n) = min(numSquare(n-k)+1) k属于square numbers
//不过这个方法会超时。首先就是创建一个数组，里面存放了所有小于n的完全平方数，因为是使用for循环产生的，所以如果n是个完全平方数，则n就是数组最后一个元素
//如果n是个完全平方数，则直接返回1。否则就进入递归。
//对于每一个进入递归的数，都会有一个minnum作为这个数的最小完全平方和，然后遍历square数组中的完全平方数，然后计算n-k的最小完全平方数和，计算所有k得到的结果，选择其中最小的值并+1
//得到的结果就是当前这个数的最小完全平方数和
//下面的程序应该是没毛病的，不过因为超时所以得不到验证
class Solution {
public:
    vector<int> square;
  
    int minSquare(int n){
        int minnum = INT_MAX;
        for(int k : square){
            if(n - k < 0){
                break;
            }
            else if(n == k){
                return 1;
            }
            else{
                minnum = min(minnum, minSquare(n-k)+1);
            }
        }
        return minnum;
    }
  
    int numSquares(int n) {
        for(int i = 1; i * i <= n; i++){
            square.push_back(i*i);
        }
        if(square.back() == n){
            return 1;
        }
        return minSquare(n);
    }
};
