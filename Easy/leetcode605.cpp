/* 
 * 假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
 * 给你一个整数数组  flowerbed 表示花坛，由若干 0 和 1 组成，其中 0 表示没种植花，1 表示种植了花。另有一个数 n ，能否在不打破种植规则的情况下种入 n 朵花？
 * 能则返回 true ，不能则返回 false。
 */

//方法一：贪心
//思路：实际上就是求出最多能种多少花，如果大于等于n，则返回true，否则false
//可以将花坛分为一个一个的区间，设第一朵有花的下标为i，最后一朵有花的下标为j，则对于前面i朵花，最多可以种植(i + 1) / 2
//最后m-j-1个位置，最多可以种植(m-j-1-1+1) / 2朵花，然后将中间的部分分成多个小区间，区间头和尾都种了花，对于中间j-i+1个位置，最多可以种(j-i-2) / 2朵花
//然后全部加起来就得到最多能种多少花
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        if(m < n)  return false;
        int total = 0;
        int pre = -1;
        for(int i = 0; i < m; i++){
            if(flowerbed[i] == 1){
                if(pre < 0){
                    total += i/2;
                }
                else{
                    total += (i - pre - 2) / 2;
                }
                pre = i;
            }
        }
        if(pre < 0){
            total += (m + 1) / 2;
        }
        else{
            total += (m - pre - 1) / 2;
        }

        return total >= n;
    }
};

//当记录的个数已经达到n时就可以直接返回true
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        if(m < n)  return false;
        int total = 0;
        int pre = -1;
        for(int i = 0; i < m; i++){
            if(flowerbed[i] == 1){
                if(pre < 0){
                    total += i/2;
                }
                else{
                    total += (i - pre - 2) / 2;
                }
                pre = i;
                if(total >= n){
                    return true;
                }
            }
        }
        if(pre < 0){
            total += (m + 1) / 2;
        }
        else{
            total += (m - pre - 1) / 2;
        }

        return total >= n;
    }
};
