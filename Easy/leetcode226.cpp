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
