/*
 * 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。
 */
//方法一：递归
//思路：在递归过程中查找最长直径，就是判断当前最长直径和左子树右子树深度和的大小
//但感觉写的还是不够好
//pdf上的解题过程和我一样。。。
//官方的解答也和我一样。。。
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
    int maxlength = 0;

    int getlength(TreeNode *root){
        if(root == nullptr) return 0;
        int right = getlength(root->right);
        int left = getlength(root->left);
        maxlength = max(maxlength, right + left);
        return max(right, left) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        getlength(root);
        return maxlength;
    }
};
