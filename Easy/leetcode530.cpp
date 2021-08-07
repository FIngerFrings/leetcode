/* 给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。 */
//方法一：中序遍历
//思路：通过中序遍历找到最小差值
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
    int minsub = INT_MAX;
    TreeNode *pre = nullptr;
    void midordered(TreeNode *root){
        if(!root)   return;
        midordered(root->left);
        if(!pre){
            pre = root;
        }
        else{
            minsub = min(root->val - pre->val, minsub);
            pre = root;
        }
        midordered(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        midordered(root);
        return minsub;
    }
};

//还有一种moris遍历这里就省略了
