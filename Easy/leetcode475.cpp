/*
 * 冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。
 * 在加热器的加热半径范围内的每个房屋都可以获得供暖。
 * 现在，给出位于一条水平线上的房屋 houses 和供暖器 heaters 的位置，请你找出并返回可以覆盖所有房屋的最小加热半径。
 * 说明：所有供暖器都遵循你的半径标准，加热的半径也一样。
 */
//方法一：二分查找
//思路：实际上就是从最大值和最小值之间找出一个数
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int m = houses.size(), n = heaters.size();
        int l = 0, r = max(heaters[n-1] - houses[0], houses[m-1] - heaters[0]), ans = r + 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(check(houses, heaters, mid)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }

    bool check(vector<int>& houses, vector<int>& heaters, int mid){
        int i = 0;
        for(int j = 0; j < houses.size(); j++){
            while(i < heaters.size() && (houses[j] < heaters[i] - mid || houses[j] > heaters[i] + mid)){
                ++i;
            }
            if(i == heaters.size()) return false;
        }
        return true;
    }
};
