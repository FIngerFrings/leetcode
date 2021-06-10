/* 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 。*/
//方法一：双指针
//思路：先列出所有小于c的平方数，然后使用双指针遍历这个平方数
//如果使用int则会溢出，所以这里使用long
class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 0)  return true;
        long int i = 0;
        vector<long int> square;
        while(i*i <= c){
            square.push_back(i*i);
            ++i;
        }
        int n = square.size();
        int l = 0, r = n - 1;
        while(l <= r){
            if(square[l] + square[r] == c){
                return true;
            }
            else if(square[l] + square[r] < c){
                ++l;
            }
            else{
                --r;
            }
        }
        return false;
    }
};
