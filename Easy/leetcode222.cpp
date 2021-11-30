/* 给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。 */
//方法一：遍历
//思路：遍历就不再赘述了，可以通过前中后序遍历（迭代+递归）、层序遍历访问每一个节点并计算出结果，但是这样没用用到完全二叉树的性质
//在这里还是写一种递归方法，因为这是我一开始没想到的，就是计算左子树节点和右子树节点并相加，最后+1加上当前节点
//属于后序遍历+递归
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
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
//方法二：完全二叉树+递归
//思路：对于一个节点所形成的树，首先去判断它是否是满二叉树，如果是则可以直接得到节点个数。如果不是则递归计算其左子树节点数以及右子树节点数，相加并加上1
//在递归过程中肯定会遇到一颗满二叉树（单独一个节点也是一颗满二叉树）
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        int leftheight = 0, rightheight = 0;
        while(left){
            left = left->left;
            leftheight++;
        }

        while(right){
            right = right->right;
            rightheight++;
        }

        if(leftheight == rightheight){
            return (2 << leftheight) - 1;
        }

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
