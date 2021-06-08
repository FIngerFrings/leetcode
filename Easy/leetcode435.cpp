/* 给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。*/
//方法一：贪心
//在选择要保留区间时，区间的结尾十分重要：选择的区间结尾越小，余留给其它区间的空间就越大，就越能保留更多的区间。因此，我们采取的贪心策略为，优先保留结尾小且不相交的区间。
//具体实现方法为，先把区间按照结尾的大小进行增序排序，每次选择结尾最小且和前一个选择的区间不重叠的区间。
//首先需要明确的一点就是，对于两个有重叠部分区间，必然要去掉一个。因此就像下面实现的一样，只要有重叠的区间，total就+1.
//就像上面所说的，一个区间的结尾越小，留给其他区间的空间就更大
//其实上面这种说法不太好，我们可以先考虑最左边的区间，对于最左边的区间，它的区间尾肯定是最小的，因为这样可以留给其他区间更大的空间。
//而选取了最小的区间尾后，区间头实际上并不需要考虑了，因为对于相同的区间尾，区间头是什么都一样，反正都不会和它有重叠了
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n < 2)  return 0;
        int total = 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        });
        int pre = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] < pre){
                total++;
            }
            else{
                pre = intervals[i][1];
            }
            
        }
        return total;
    }
};

//同上面的思路，只是这里选择了反过来想，用最大的区间头代替最小的区间尾
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n < 2)  return 0;
        int total = 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0] > b[0];
        });
        int pre = intervals[0][0];
        for(int i = 1; i < n; i++){
            if(intervals[i][1] > pre){
                total++;
            }
            else{
                pre = intervals[i][0];
            }
        }
        return total;
    }
};
