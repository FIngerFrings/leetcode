/* 给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。*/
//方法一：贪心
//在选择要保留区间时，区间的结尾十分重要：选择的区间结尾越小，余留给其它区间的空间就越大，就越能保留更多的区间。因此，我们采取的贪心策略为，优先保留结尾小且不相交的区间。
//具体实现方法为，先把区间按照结尾的大小进行增序排序，每次选择结尾最小且和前一个选择的区间不重叠的区间。
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
