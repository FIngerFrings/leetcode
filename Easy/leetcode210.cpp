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

//方法二：拓扑排序+BFS
//思路：方法一的深度优先搜索是一种「逆向思维」：最先被放入栈中的节点是在拓扑排序中最后面的节点。我们也可以使用正向思维，顺序地生成拓扑排序，这种方法也更加直观。
//我们考虑拓扑排序中最前面的节点，该节点一定不会有任何入边，也就是它没有任何的先修课程要求。
//当我们将一个节点加入答案中后，我们就可以移除它的所有出边，代表着它的相邻节点少了一门先修课程的要求。
//如果某个相邻节点变成了「没有任何入边的节点」，那么就代表着这门课可以开始学习了。
//按照这样的流程，我们不断地将没有入边的节点加入答案，直到答案中包含所有的节点（得到了一种拓扑排序）或者不存在没有入边的节点（图中包含环）。
//实际上也是和之前的BFS一样，使用while循环+队列，关键就是要记录每个节点的入度，当入度为0时，说明可以学习这门课了，因此也就可以加入队列
//同时将其他与它相连的节点的入度-1，如果有满足入度为0的节点，同样加入队列中
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> indeg(numCourses);
        vector<int> ans;
        for(auto &info : prerequisites){
            edges[info[1]].push_back(info[0]);
            indeg[info[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int j : edges[node]){
                indeg[j]--;
                if(indeg[j] == 0){
                    q.push(j);
                }
            }
        }

        if(ans.size() != numCourses){
            return {};
        }
        return ans;


    }
};
