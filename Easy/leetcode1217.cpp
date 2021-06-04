/*
 * 数轴上放置了一些筹码，每个筹码的位置存在数组 chips 当中。
 * 你可以对 任何筹码 执行下面两种操作之一（不限操作次数，0 次也可以）：
 * 将第 i 个筹码向左或者右移动 2 个单位，代价为 0。
 * 将第 i 个筹码向左或者右移动 1 个单位，代价为 1。
 * 最开始的时候，同一位置上也可能放着两个或者更多的筹码。
 * 返回将所有筹码移动到同一位置（任意位置）上所需要的最小代价。
 */

//方法一：贪心算法
//思路：首先需要注意的是，position[i]是第i个筹码的位置。
//本题可以使用贪心算法，从题目可以看出，将筹码移动2个单位是不需要代价的，说明奇数位置的筹码移动到奇数位置不需要代价，偶数位置的筹码移动带偶数位置也不需要代价
//根据贪心算法，我们应该优先移动2个单位，等没办法移动后再移动1个单位
//因此，可以首先将所有奇数位置的筹码移动到某个奇数位置i，将所有偶数位置的筹码移动到某个偶数位置i+1，然后计算两个位置上哪个位置的筹码较少
//将筹码较少的一方移动到筹码较多的一方，这样才能让代价最小
//本题实质上并不需要移动，而只是计算奇数位置的筹码比较多还是偶数位置的筹码比较多，然后返回两者中较小的那个的筹码个数
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n = position.size();
        int odd = 0, even = 0;
        for(int i = 0; i < n; i++){
            if(position[i] % 2 == 0){
                even++;
            }
            else{
                odd++;
            }
        }
        return min(even, odd);
    }
};
