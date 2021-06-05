/* 
 * 你这个学期必须选修 numCourses 门课程，记为 0 到  numCourses - 1 。
 * 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
 * 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
 * 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
 */
//这道题的思路实际上和210一样，只是输出改变了，因此解法大致流程都一样，只不过这里把他输出变一下就行
//方法一：拓扑排序+DFS
class Solution {
public:
    vector<vector<int>> edges;
    vector<int> visit;
    bool valid = true;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visit.resize(numCourses);
        for(auto &info : prerequisites){
            edges[info[1]].push_back(info[0]);
        }

        for(int i = 0; i < numCourses && valid; i++){
            if(visit[i] == 0){
                dfs(i);
            }
        }

        return valid;
    }

    void dfs(int i){
        visit[i] = 1;
        for(int j : edges[i]){
            if(visit[j] == 1){
                valid = false;
                return;
            }
            else if(visit[j] == 0){
                dfs(j);
            }
        }
        visit[i] = 2;
    }
};

 
