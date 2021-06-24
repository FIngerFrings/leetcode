/*
 * 树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，一个任何没有简单环路的连通图都是一棵树。
 * 给你一棵包含 n 个节点的树，标记为 0 到 n - 1 。给定数字 n 和一个有 n - 1 条无向边的 edges 列表（每一个边都是一对标签），其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条无向边。
 * 可选择树中任何一个节点作为根。当选择节点 x 作为根节点时，设结果树的高度为 h 。在所有可能的树中，具有最小高度的树（即，min(h)）被称为 最小高度树 。
 * 请你找到所有的 最小高度树 并按 任意顺序 返回它们的根节点标签列表。
 * 树的 高度 是指根节点和叶子节点之间最长向下路径上边的数量。
 */

//方法一：暴力BFS
//思路：创建无向图，然后对每个元素进行BFS求高度，选择其中最小的
// 对每一个点进行BFS求高度
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        // 根据边表edges 创建无向邻接图(数组)
        vector<vector<int>> adjList(n);
        for (int i=0; i < edges.size(); ++i) {
            int v1 = edges[i][0];
            int v2 = edges[i][1];
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1);
        }

        // 从每个顶点依次层序遍历，记录最小层数的顶点
        int minDepth = 10000;
        vector<int> ans;

        for (int i=0; i < n; ++i) {
            int depth = BFS(adjList, i);  
            
            if (depth > minDepth) continue;

            if (depth == minDepth) {
                ans.push_back(i);
            }
            else {
                ans.clear();
                ans.push_back(i);
                minDepth = depth;
            }
        }

        return ans;
    }

    // 标准的BFS广度优先搜索模板，返回最大深度
    int BFS(const vector<vector<int>>& graph, int start) {
        int size = graph.size();
        if (start >= size) return -1;

        vector<char> visited(size, false);
        queue<int> Q;
        Q.push(start);
        visited[start] = true;

        int depth = 0;

        while (Q.size()) {
            int n = Q.size();
            ++depth;
            while (n--) {
                int cur = Q.front(); Q.pop();

                for (auto adj : graph[cur]) {
                    if (visited[adj]) continue;
                    visited[adj] = true;

                    Q.push(adj);
                }

            }
        }
        return depth;
    }
};
