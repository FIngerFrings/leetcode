/*
 * 在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。
 * 由于它是水平的，所以纵坐标并不重要，因此只要知道开始和结束的横坐标就足够了。开始坐标总是小于结束坐标。
 * 一支弓箭可以沿着 x 轴从不同点完全垂直地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。
 * 可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。
 * 给你一个数组 points ，其中 points [i] = [xstart,xend] ，返回引爆所有气球所必须射出的最小弓箭数。
 */
//方法一：贪心
//思路：其实和435相同，你需要从左往右考虑，你为了射爆结束位置最左的这个气球，你可以从这个气球的起始位置和终止位置之间的位置射它
//为了能一箭射爆最多的气球，最好是在这个气球的终止位置射，射完这箭后，就将所有重叠的气球去掉，然后去寻找下一个终止位置最左的气球
//所以实际上就是在寻找最多的不重叠的区间，为什么这里是最多，然后我们求的却是最少呢
//因为最后留下来的这些区间是必须要射的，其他的区间还可能能顺带射掉
//其实和435不同的地方在于重叠的定义
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n < 2)   return n;
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        });
        int total = 1;
        int prev = points[0][1];
        for(int i = 1; i < n; i++){
            if(points[i][0] > prev){
                total++;
                prev = points[i][1];
            }
        }
        return total;
    }
};
