/* 
 * 假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。
 * 对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。
 * 如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
 */
//方法一：排序+贪心
//思路：因为饥饿度最小的孩子最容易吃饱，所以我们先考虑这个孩子。为了尽量使得剩下的饼干可以满足饥饿度更大的孩子，所以我们应该把大于等于这个孩子饥饿度的、且大小最小的饼干给这
//个孩子。满足了这个孩子之后，我们采取同样的策略，考虑剩下孩子里饥饿度最小的孩子，直到没有满足条件的饼干存在。
//简而言之，这里的贪心策略是，给剩余孩子里最小饥饿度的孩子分配最小的能饱腹的饼干。
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0, num = 0;
        while(i < g.size() && j < s.size()){
            if(g[i] <= s[j]){
                ++i;
                ++num;
            }
            ++j;
        }
        return num;
    }
};

//不需要num变量保存小孩个数，可以直接返回i
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        while(i < g.size() && j < s.size()){
            if(g[i] <= s[j]){
                ++i;
            }
            ++j;
        }
        return i;
    }
};
//这道题算是一道经典的贪心算法，贪心算法的思想在于每一次都选择局部最优的选择，在这一题中就是对于某个小孩，
//我们选择能满足其要求的最小的饼干，所以首先需要对小孩和饼干进行排序，先分配要求和大小比较小的小孩和饼干。
//总结：这道题你主要需要知道的一个点就是：为了能让尽可能多的孩子获得饼干，应该要给胃口小的孩子分配尽可能小同时又能满足其胃口的饼干

//上面是先喂饱小的，也可以先喂饱大的
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        for(int i = g.size() - 1, j = s.size() - 1; i >= 0 && j >= 0; i--){
            if(s[j] >= g[i]){
                ++ans;
                --j;
            }
        }
        return ans;
    }
};
