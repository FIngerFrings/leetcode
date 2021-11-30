/*
 * 给定一个 N 叉树，找到其最大深度。
 * 最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
 * N 叉树输入按层序遍历序列化表示，每组子节点由空值分隔（请参见示例）。
 */
//方法一：层序遍历
//思路：按层遍历N叉树，每遍历一层将结果+1，最后可以得到深度
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr) return 0;
        int ans = 0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            ++ans;
            while(n--){
                auto node = q.front();
                q.pop();
                for(auto temp : node->children){
                    if(temp != nullptr){
                        q.push(temp);
                    }
                }
            }
        }
        return ans;
    }
};

//方法二：二叉树深度前序遍历+递归改编
//思路：类似于二叉树深度前序遍历+递归，计算出所有子节点的深度，取其中最大值+1即当前节点的深度
class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr) return 0;
        int ans = 0;
        for(auto node : root->children){
            ans = max(ans, maxDepth(node));
        }
        return ans + 1;
    }
};

//方法三：二叉树深度后序遍历+递归改编
//思路：类似于二叉树深度后序遍历+递归，记录每个节点的所在深度，然后选取其中的最大值
class Solution {
public:
    int ans;

    void maxDepthHelper(Node* root, int depth){
        ans = max(ans, depth);
        
        for(auto node : root->children){
            if(node != nullptr){
                maxDepthHelper(node, depth + 1);
            }
        }
        return;
    }

    int maxDepth(Node* root) {
        if(root == nullptr) return 0;
        ans = 0;
        maxDepthHelper(root, 1);
        return ans;
    }
};
