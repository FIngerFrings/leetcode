/*
 * 数组arr是[0, 1, ..., arr.length - 1]的一种排列，我们将这个数组分割成几个“块”，并将这些块分别进行排序。之后再连接起来，使得连接的结果和按升序排序后的原数组相同。
 * 我们最多能将数组分成多少块？
 */
//方法一：emmmm不太知道叫什么方法
//思路：说实话我自己都没太弄懂。。。
//巧了，就是pdf上的方法，从左往右遍历，同时记录当前的最大值，每当当前最大值等于数组位置时，我们可以多一次分割。
//为什么可以通过这个算法解决问题呢？如果当前最大值大于数组位置，则说明右边一定有小于数组位置的数字，需要把它也加入待排序的子数组；又因为数组只包含不重复的 0 到 n，所以
//当前最大值一定不会小于数组位置。所以每当当前最大值等于数组位置时，假设为 p，我们可以成功完成一次分割，并且其与上一次分割位置 q 之间的值一定是 q + 1 到 p 的所有数字。
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        if(n == 1)  return 1;
        int maxi = arr[0];
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] > maxi){
                maxi = arr[i];
            }

            if(maxi == i){
                ++ans;
            }
        }
        return ans;
    }
};
//方法和上面一样，不过代码更简洁
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int curr_max = 0;
        int ans = 0;
        for(int i = 0; i < arr.size(); i++){
            curr_max = max(curr_max, arr[i]);
            if(curr_max == i){
                ++ans;
            }
        }
        return ans;
    }
};
