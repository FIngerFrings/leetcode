/*
 * 给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。
 * 树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。
 */
//方法一：层序遍历
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
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr) return{};
        vector<vector<int>> ans;
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            while(n--){
                auto node = q.front();
                q.pop();
                temp.push_back(node->val);
                for(auto p : node->children){
                    if(p != nullptr) q.push(p);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
