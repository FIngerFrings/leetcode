//leetcode687
/* 给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。*/
//该方法使用递归和深度优先算法
//总的来说就是递归，计算每个结点的左结点的最长同值路径和右结点的最长同值路径，然后再比较当前结点和左右结点是否相等，相等就+1
//需要注意的是这里的路径是可以经过根结点的
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
    int res = 0;

    int dfs(TreeNode *curr){
        if(curr == nullptr){
            return 0;
        }
        int left = 0;
        int right = 0;
        int leftlongest = dfs(curr->left);
        int rightlongest = dfs(curr->right);
        if(curr->left != nullptr && curr->val == curr->left->val){
            left += leftlongest + 1;
        }
        if(curr->right != nullptr && curr->val == curr->right->val){
            right += rightlongest + 1;
        }
        res = max(res, right + left);
        return max(right, left);
    }

public:
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return res;
    }
};
