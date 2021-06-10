/* 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 。*/
//方法一：双指针
//思路：先列出所有小于c的平方数，然后使用双指针遍历这个平方数
//如果使用int则会溢出，所以这里使用long
class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 0)  return true;    
        long int i = 0;     //如果溢出了可以使用long
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

//官方给出的双指针，原理大体相同，但是比较简洁
class Solution {
public:
    bool judgeSquareSum(int c) {
        long l = 0, r = (int)sqrt(c);           //如果下次遇到这种题可以使用sqrt
        while(l <= r){
            long sum = l*l + r*r;
            if(sum == c){
                return true;
            }
            else if(sum < c){
                ++l;
            }
            else{
                --r;
            }
        }
        return false;
    }
};

//方法二：sqrt解法
//思路：可以先固定一个数，然后用c-i*i之后再sqrt，如果这个数是一个整数，则返回true
class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long i = 0; i * i <= c; i++){
            double j = sqrt(c - i * i);
            if(j == int(j)){        //可以用这个方法判断一个数是否是整数
                return true;
            }
        }
        return false;
    }
};
