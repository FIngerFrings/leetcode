/* 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。 */
//方法一：动态规划
//思路：每根柱子处所能装下的水的高度为它左边最长和右边最长的柱子中的较小值减去当前柱子的高度（包括它自己）
//因此我们只要求出每个坐标处往左和往右的最高柱子高度，分别用leftmax和rightmax记录左边和右边的最高柱子
//然后使用动态规划求出leftmax和rightmax，最后遍历数组求出每个座标处所能装的水，最后返回和
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())  return 0;
        int n = height.size();
        vector<int> ans(n);
        vector<int> leftmax(n);
        vector<int> rightmax(n);
        leftmax[0] = height[0];
        rightmax[n-1] = height[n-1];
        for(int i = 1; i < n; i++){
            leftmax[i] = max(leftmax[i-1], height[i]);
        }
        for(int i = n - 2; i >= 0; i--){
            rightmax[i] = max(rightmax[i+1], height[i]);
        }

        for(int i = 0; i < n; i++){
            ans[i] = min(leftmax[i], rightmax[i]) - height[i];
        }
        
        return accumulate(ans.begin(), ans.end(), 0);
    }
};

//代码随想录动态规划
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);
        maxLeft[0] = height[0];
        maxRight[n-1] = height[n-1];
        for(int i = 1; i < n; i++){
            maxLeft[i] = max(height[i], maxLeft[i-1]);
        }
        for(int i = n-2; i >= 0; i--){
            maxRight[i] = max(height[i], maxRight[i+1]);
        }
        for(int i = 0; i < n; i++){
            int h = min(maxLeft[i], maxRight[i]) - height[i];
            if(h > 0) ans += h;
        }
        return ans;
    }
};

//方法二：单调栈
//思路：emmmmm其实我还并不是特别理解这道题单调栈的解法，可以取官方解答看看
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> stk;
        int ans = 0;
        for(int i = 0; i < n; i++){
            while(!stk.empty() && height[i] > height[stk.top()]){
                auto k = stk.top();
                stk.pop();
                if(stk.empty()){
                    break;
                }
                int left = stk.top();
                int curr_width = i - left - 1;
                int curr_height = min(height[left], height[i]) - height[k];
                ans += curr_width * curr_height;
            }
            stk.push(i);
        }
        return ans;
    }
};

//代码随想录单调栈
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2) return 0;
        int n = height.size();
        stack<int> stk;
        stk.push(0);
        int ans = 0;
        for(int i = 1; i < n; i++){
            if(!stk.empty() && height[i] < height[stk.top()]){
                stk.push(i);
            }
            else if(!stk.empty() && height[i] == height[stk.top()]){
                stk.pop();
                stk.push(i);
            }
            else{
                while(!stk.empty() && height[i] > height[stk.top()]){
                    int mid = stk.top();
                    stk.pop();
                    if(!stk.empty()){
                        int h = min(height[i], height[stk.top()]) - height[mid];
                        int w = i - stk.top() - 1;
                        ans += h * w;
                    }
                }
                stk.push(i);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2) return 0;
        int n = height.size();
        stack<int> stk;
        stk.push(0);
        int ans = 0;
        for(int i = 1; i < n; i++){
            while(!stk.empty() && height[i] > height[stk.top()]){
                int mid = stk.top();
                stk.pop();
                if(!stk.empty()){
                    int h = min(height[i], height[stk.top()]) - height[mid];
                    int w = i - stk.top() - 1;
                    ans += h * w;
                }
            }
            stk.push(i);
        }
        return ans;
    }
};

//方法四：双指针
//思路：还是不太懂双指针在这里的原理
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int leftmax = 0, rightmax = 0;
        int ans = 0;
        while(left < right){
            leftmax = max(leftmax, height[left]);
            rightmax = max(rightmax, height[right]);
            if(height[left] < height[right]){
                ans += leftmax - height[left];
                left++;
            }
            else{
                ans += rightmax - height[right];
                right--;
            }
        }
        return ans;
    }
};

//双指针，超时
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        for(int i = 0; i < n; i++){
            if(i == 0 || i == n-1) continue;
            int rHeight = height[i];
            int lHeight = height[i];
            for(int r = i + 1; r < n; r++){
                if(height[r] > rHeight) rHeight = height[r];
            }

            for(int l = i - 1; l >= 0; l--){
                if(height[l] > lHeight) lHeight = height[l];
            }

            int h = min(lHeight, rHeight) - height[i];
            if(h > 0) ans += h;
        }
        return ans;
    }
};
