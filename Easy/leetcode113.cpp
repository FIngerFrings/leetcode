/* 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。 */
//方法一：递归
//思路：在递归的过程中记录目标和以及路径
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
    vector<vector<int>> ans;

    void pathSumHelper(TreeNode* root, int targetSum, vector<int> path){
        if(root->left == nullptr && root->right == nullptr){
            if(targetSum - root->val == 0){
                path.push_back(root->val);
                ans.push_back(path);
            }
            return;
        }

        path.push_back(root->val);
        if(root->left)  pathSumHelper(root->left, targetSum - root->val, path);
        if(root->right)  pathSumHelper(root->right, targetSum - root->val, path);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return{};
        pathSumHelper(root, targetSum, {});
        return ans;
    }
};
