/*
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 * 说明: 叶子节点是指没有子节点的节点。
 */
//方法一：DFS
//思路：略
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string> ans;

    void dfs(TreeNode* root, string paths){
        if(root != nullptr){
            paths += to_string(root->val);
            if(root->left == nullptr && root->right == nullptr){
                ans.push_back(paths);
            }
            else{
                paths += "->";
                dfs(root->left, paths);
                dfs(root->right, paths);
            }
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};

//方法二：BFS
//思路：略，重点是使用两个queue
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> node_queue;
        queue<string> val_queue;
        node_queue.push(root);
        val_queue.push(to_string(root->val));
        while(!node_queue.empty()){
            auto node = node_queue.front();
            auto path = val_queue.front();
            node_queue.pop();
            val_queue.pop();
            if(node->left == nullptr && node->right == nullptr){
                ans.push_back(path);
            }
            else{
                if(node->left != nullptr){
                    node_queue.push(node->left);
                    val_queue.push(path + "->" + to_string(node->left->val));
                }

                if(node->right != nullptr){
                    node_queue.push(node->right);
                    val_queue.push(path + "->" + to_string(node->right->val));
                }
            }
            
        }
        return ans;
    }
};
