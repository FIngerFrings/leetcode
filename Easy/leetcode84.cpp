/* 
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 */
//方法一：暴力
//思路：找出所有的矩阵，计算其中的最大值
//确定两边，然后寻找最大矩形
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int minheight = INT_MAX;
            for(int j = i; j < n; j++){
                minheight = min(minheight, heights[j]);
                ans = max(ans, (j - i + 1) * minheight);
            }
        }
        return ans;
    }
};
//同样是暴力，但和上面不一样，这里是确定高度，然后寻找最大矩形
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        for(int mid = 0; mid < n; mid++){
            int curr_height = heights[mid];
            int l = mid, r = mid;
            while(l - 1 >= 0 && heights[l - 1] >= heights[mid]){
                --l;
            }
            while(r + 1 < n && heights[r + 1] >= heights[mid]){
                ++r;
            }
            ans = max(ans, (r - l + 1) * curr_height);
        }
        return ans;
    }
};
