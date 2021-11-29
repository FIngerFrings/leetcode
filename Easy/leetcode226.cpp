/*
 *  翻转一棵二叉树。
 */
//方法一：递归
//思想：每次遍历到一个节点的时候交换他的左右子树
//这种方法应该是自顶向下
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
    void reverseTree(TreeNode *root){
        if(!root)   return;
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        reverseTree(root->left);
        reverseTree(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        reverseTree(root);
        return root;
    }
};

//下面这种方法是自底向上
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)   return nullptr;
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);
        root->right = left;
        root->left = right;
        return root;
    }
};

//实际上就是遍历树，然后交换每个节点的左右节点
//层序遍历
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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        if(root == nullptr) return nullptr;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto node = q.front();
                q.pop();
                swap(node->right, node->left);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return root;
    }
};
//DFS
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
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> stk;
        if(root == nullptr) return nullptr;
        stk.push(root);
        while(!stk.empty()){
            auto node = stk.top();
            stk.pop();
            swap(node->left, node->right);
            if(node->right) stk.push(node->right);
            if(node->left) stk.push(node->left); 
        }
        return root;
    }
};
