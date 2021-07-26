/*
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 本题中，一棵高度平衡二叉树定义为：
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
 */
//方法一：递归
//思路：和求数的最大深度一样，求出左子树和右子树的深度，然后判断是否是平衡二叉树
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
    int flag = true;

    int getheight(TreeNode *root){
        if(root == nullptr) return 0;
        int leftheight = getheight(root->left);
        int rightheight = getheight(root->right);
        int d = leftheight - rightheight;
        if(d > 1 || d < -1){
            flag = false;
        }
        return max(leftheight, rightheight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        getheight(root);
        return flag;
    }
};

//其实可以在递归过程中判断是否是平衡二叉树，如果不是则返回-1，且如果发现前面已经返回-1了，则说明不符合平衡二叉树，则直接返回-1
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
    int getheight(TreeNode *root){
        if(root == nullptr) return 0;
        int leftheight = getheight(root->left);
        int rightheight = getheight(root->right);
        if(leftheight == -1 || rightheight == -1 || abs(leftheight - rightheight) > 1){
            return -1;
        }
        return max(leftheight, rightheight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return getheight(root) != -1;
    }
};
