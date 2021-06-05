/* 
 * 现在你总共有 n 门课需要选，记为 0 到 n-1。
 * 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
 * 给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。
 * 可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。
 */
//方法一：拓扑排序+DFS
//思路：将所有课程看成一张有向图，边尾是需要提前学习的课程，设置三个数组，第一个用来存放每个节点可以到达的节点，也就是学习了这门课后可以学习哪些课（实际上可能并不一定能学，因为可能还需要学习其他课程）
//第二个数组用来存放某个节点是否搜索过，0=为搜索，1=搜索中，2=已完成。
//第三个数组用来存放输出的顺序
//基本的思路就是对于一个节点，如果它所有能够到达的节点都已经搜索过了，就可以将它放到第三个数组中。
//所以可以先使用深度优先算法，递归到没有出度的节点时，就可以将这个节点加入栈中，并将它设置为搜索过，所有还在递归的节点，也就是还有子节点没有搜索完的节点都设置成搜索中
//如果一个正在搜索中的节点也找到了一个正在搜索中的节点，那么说明存在环，就直接return就行了
//根据上面的规则，栈的顺序是反的，所以最后需要反转一下
class Solution {
public:
    vector<vector<int>> edges;  //存储有向图，里面存储了学习完某门课后才能学习哪些课
    vector<int> visit;      //标记每个节点的状态，0=为搜索，1=搜索中，2=已完成
    bool valid = true;      //判断是否有环
    vector<int> ans;        //用数组来模拟栈
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        visit.resize(numCourses);
        edges.resize(numCourses);
        for(auto &info : prerequisites){
            edges[info[1]].push_back(info[0]);
        }
        //每次挑选一个未搜索的节点，开始进行深度优先搜索
        for(int i = 0; i < numCourses && valid; i++){
            if(visit[i] == 0){
                dfs(i);
            }
        }
        //如果存在环，则返回空数组
        if(!valid){
            ans.clear();
            return ans;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void dfs(int i){
        visit[i] = 1;
        for(int j : edges[i]){
            if(visit[j] == 0){
                dfs(j);
                if(!valid){
                    return;
                }
            }
            else if(visit[j] == 1){
                valid = false;
                return;
            }
        }
        visit[i] = 2;
        ans.push_back(i);
    }
};
