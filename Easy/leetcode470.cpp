/*
 * 已有方法 rand7 可生成 1 到 7 范围内的均匀随机整数，试写一个方法 rand10 生成 1 到 10 范围内的均匀随机整数。
 *不要使用系统的 Math.random()  方法。
 */
//方法一：拒绝采样
//思路：我们可以利用两个rand7生成49个数，但是我们只需用到其中的40个数，如果采样得到41到49之间的数，我们可以丢弃，继续采样
//将采样得到的数（1~40）我们把他们映射到1~10
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int row;
        int col;
        int idx;
        do{
            row = rand7();
            col = rand7();
            idx = row + (col - 1) * 7;
        }while(idx > 40);
        return (idx - 1) % 10 + 1;
    }
};
//从理论上讲我们可以直接将大于10的数丢弃，但是这样比较费时
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int row;
        int col;
        int idx;
        do{
            row = rand7();
            col = rand7();
            idx = row + (col - 1) * 7;
        }while(idx > 10);
        return idx;
    }
};
