/* 
 * 假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。
 * 每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。
 * 请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。
 */
//方法一：贪心
//思路：自己写的，首先对people进行排序，排序原则为身高高的在前面，如果身高一样，则k小的在前面
//构造返回数组，遍历people，将people[i][j]插入到返回数组下标为[j]的位置
//因为后面都是比当前元素小的，所以就算插入到前面也不会对当前元素有影响
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b){
            return  a[0] == b[0] ? a[1] < b[1] : a[0] > b[0]; 
        });

        vector<vector<int>> ans(n);
        ans[0] = people[0];
        for(int i = 1; i < n; i++){ 
            for(int j = n - 1; j >= people[i][1] + 1; j--){
                ans[j] = ans[j-1];
            }
            ans[people[i][1]] = people[i]; 
        }
        return ans;
    }
};
//使用insert插入
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
        });
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            ans.insert(ans.begin() + people[i][1], people[i]);
        }
        return ans;
    }
};

//同样也是贪心，不过排序从小到大
//思路其实和上面的大同小异，首先对people排序，顺序为身高小的在前面，k大的在前面
//然后遍历people，people[i][1]实际上就是当前空着的位置中的下标
//本质还是因为先放身高小的人并不会影响身高高的人
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        vector<vector<int>> ans(n);
        for(int i = 0; i < n; i++){
            int spaces = people[i][1] + 1;
            for(int j = 0; j < n; j++){
                if(ans[j].empty()){
                    spaces--;
                    if(spaces == 0){
                        ans[j] = people[i];
                    }
                }
            }
        }
        return ans;
    }
};
