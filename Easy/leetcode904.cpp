/*
 * 在一排树中，第 i 棵树产生 tree[i] 型的水果。
 * 你可以从你选择的任何树开始，然后重复执行以下步骤：
 * 把这棵树上的水果放进你的篮子里。如果你做不到，就停下来。
 * 移动到当前树右侧的下一棵树。如果右边没有树，就停下来。
 * 请注意，在选择一颗树后，你没有任何选择：你必须执行步骤 1，然后执行步骤 2，然后返回步骤 1，然后执行步骤 2，依此类推，直至停止。
 * 你有两个篮子，每个篮子可以携带任何数量的水果，但你希望每个篮子只携带一种类型的水果。
 * 用这个程序你能收集的水果树的最大总量是多少？
 */
//方法一：滑动窗口
//思路：利用哈希表记录当前收集的水果种类和数量，使用滑动窗口，如果滑动窗口内水果种类大于2时，则将滑动窗口的起始位置往右移动，直到水果种类减少
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> hash;
        int n = fruits.size();
        int ans = 0, len = 0;
        int l = 0;
        for(int r = 0; r < n; r++){
            ++len;
            hash[fruits[r]]++;
            while(hash.size() > 2){
                --hash[fruits[l]];
                if(hash[fruits[l]] == 0){
                    hash.erase(fruits[l]);
                }
                ++l;
                --len;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};
