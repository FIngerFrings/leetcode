/* 给定一个二叉树，检查它是否是镜像对称的。 */
//方法一：递归
//思路：判断一个树是否对称等价于判断左右子树是否对称。笔者一般习惯将判断两个子树是否相等或对称类型的题的解法叫做“四步法”：（1）如果两个子树都为空指针，则它们相等或对称
//（2）如果两个子树只有一个为空指针，则它们不相等或不对称（3）如果两个子树根节点的值不相等，则它们不相等或不对称（4）根据相等或对称要求，进行递归处理。
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
    bool isSymmetric(TreeNode* root) {
        return root ? symmetric(root->left, root->right) : true;
    }

    bool symmetric(TreeNode* left, TreeNode* right){
        if(!left && !right) return true;
        if(!left || !right) return false;
        if(left->val != right->val) return false;
        return symmetric(left->left, right->right) && symmetric(left->right, right->left);
    }
};
