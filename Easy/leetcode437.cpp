/*
 * 给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
 * 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
 */
//方法一：递归
//思路：递归每个节点时，需要分情况考虑：（1）如果选取该节点加入路径，则之后必须继续加入连续节点，或停止加入节点（2）如果不选取该节点加入路径，则对其左右节点进行重新进行考虑。
//因此一个方便的方法是我们创建一个辅函数，专门用来计算连续加入节点的路径。
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
    int pathSum(TreeNode* root, int targetSum) {
        return root ? pathSumStartWithRoot(root, targetSum) + pathSum(root->right, targetSum) + pathSum(root->left, targetSum) : 0;
    }

    int pathSumStartWithRoot(TreeNode *root, int targetSum){
        if(root == nullptr) return 0;
        int count = root->val == targetSum ? 1 : 0;
        count += pathSumStartWithRoot(root->left, targetSum - root->val);
        count += pathSumStartWithRoot(root->right, targetSum - root->val);
        return count;
    }
};
