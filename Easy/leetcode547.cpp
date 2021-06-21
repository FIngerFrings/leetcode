/* 
 * 有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。
 * 省份是一组直接或间接相连的城市，组内不含其他没有相连的城市。
 * 给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。
 * 返回矩阵中 省份 的数量。
 */
//方法一：并查集
//思路：就是并查集的思想，将相邻的城市加入到同一个集合中，最后返回集合个数
//以下方法和lletcode200的并查集解法相同，但实际上并不需要另外再定义一个类
class UnionFind{
public:
    UnionFind(int n){
        count = 0;
        for(int i = 0; i < n; i++){
            parent.push_back(i);
            rank.push_back(0);
            count++;
        }
    }

    void unit(int i, int j){
        int rootx = find(i);
        int rooty = find(j);

        if(rootx == rooty){
            return;
        }

        if(rank[rootx] < rank[rooty]){
            swap(rootx, rooty);
        }

        parent[rooty] = rootx;
        count--;
        if(rank[rootx] == rank[rooty]){
            rank[rootx]++;
        }
    }

    int find(int i){
        if(parent[i] != i){
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    int getcount(void){
        return count;
    }
private:
    vector<int> parent;
    vector<int> rank;
    int count;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        if(!n)  return 0;
        
        UnionFind q(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j){
                    continue;
                }
                if(isConnected[i][j] == 1){
                    q.unit(i, j);
                }
            }
        }
        return q.getcount();
    }
};
//官方解法如下，确实不需要像上面那样重新定义一个类
class Solution {
public:
    int Find(vector<int>& parent, int index) {
        if (parent[index] != index) {
            parent[index] = Find(parent, parent[index]);
        }
        return parent[index];
    }

    void Union(vector<int>& parent, int index1, int index2) {
        parent[Find(parent, index1)] = Find(parent, index2);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = isConnected.size();
        vector<int> parent(provinces);
        for (int i = 0; i < provinces; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < provinces; i++) {
            for (int j = i + 1; j < provinces; j++) {
                if (isConnected[i][j] == 1) {
                    Union(parent, i, j);
                }
            }
        }
        int circles = 0;
        for (int i = 0; i < provinces; i++) {
            if (parent[i] == i) {
                circles++;
            }
        }
        return circles;
    }
};

//方法二：深度优先算法
//思路：采用深度优先算法，建立一个数组用来存放某个城市是否被访问过，之后遍历所有城市，对于一个没有被访问过的城市，访问所有与它相邻的城市，并访问与这些城市相邻的城市
//这样就能将所有相邻的城市访问一遍，在访问的同时，记录有多少省份
//这实际上就是记忆化搜索了
class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int> &visited, int i){
        int n = isConnected.size();
        for(int j = 0; j < n; j++){
            if(isConnected[i][j] == 1 && visited[j] == 0){
                visited[j] = 1;
                dfs(isConnected, visited, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        if(!n)  return 0;
        int num = 0;
        vector<int> visited(n);     //vector这样的初始化方式是一开始没想到的
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                num++;
                visited[i] = 1;
                dfs(isConnected, visited, i);
            }
        }
        return num;
    }
};

//第二遍写的时候自己写的dfs
class Solution {
public:
    vector<int> dp;
    void dfs(vector<vector<int>>& isConnected, int i, int n){
        for(int j = 0; j < n; j++){     //这里需要从0开始，不然当i=n-1时会出错
            if(isConnected[i][j] == 1 && dp[j] == 1){
                dp[j] = 0;
                dfs(isConnected, j, n);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int num = 0;
        dp.resize(n, 1);
        for(int i = 0; i < n; i++){
            if(dp[i] == 1){
                ++num;
                dp[i] = 0;
                dfs(isConnected, i, n);
            }
        }
        return num;
    }
};

//用栈实现深度优先算法
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int num = 0;
        vector<int> dp(n);
        for(int i = 0; i < n; i++){
            if(dp[i] == 0){
                ++num;
                stack<int> q;
                q.push(i);
                dp[i] = 1;
                while(!q.empty()){
                    auto j = q.top();
                    q.pop();
                    for(int k = 0; k < n; k++){
                        if(isConnected[j][k] == 1 && dp[k] == 0){
                            dp[k] = 1;
                            q.push(k);
                        }
                    }
                }
            }
        }
        return num;
    }
};

//方法三：广度优先算法
//思路同样是使用while和队列实现
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        if(!n)  return 0;
        int num = 0;
        vector<int> visited(n);
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                num++;
                visited[i] = 1;
                q.push(i);
                while(!q.empty()){
                    auto node = q.front();
                    q.pop();
                    for(int j = 0; j < n; j++){
                        if(visited[j] == 0 && isConnected[node][j] == 1){
                            visited[j] = 1;
                            q.push(j);
                        }
                    }
                }

            }
        }
        return num;
    }
};
