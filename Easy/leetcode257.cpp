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

//递归
//思路：实际上就是遍历所有节点，当某个节点没有左右字节点时就将path压入ans中
//实际上是一种回溯
class Solution {
public:
    vector<string> ans;
    void binaryTreePathsHelper(TreeNode *root, string path){
        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(path + to_string(root->val));
            return;
        }

        if(root->left){
            binaryTreePathsHelper(root->left, path + to_string(root->val) + "->");
        }

        if(root->right){
            binaryTreePathsHelper(root->right, path + to_string(root->val) + "->");
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string path = "";
        binaryTreePathsHelper(root, path);
        return ans;
    }
};

//方法二：队列迭代
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
//栈迭代
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr) return {};
        vector<string> ans;
        string path = "";
        stack<TreeNode *> q1;
        stack<string> q2;
        q1.push(root);
        q2.push(to_string(root->val));
        while(!q1.empty()){
            auto node = q1.top();
            q1.pop();
            auto path = q2.top();
            q2.pop();
            if(node->left == nullptr && node->right == nullptr){
                ans.push_back(path);
            }

            if(node->left){
                q1.push(node->left);
                q2.push(path + "->" + to_string(node->left->val));
            }

            if(node->right){
                q1.push(node->right);
                q2.push(path + "->" + to_string(node->right->val));
            }
        }
        return ans;
    }
};
