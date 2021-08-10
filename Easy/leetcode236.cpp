/* 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。 */
//方法一：递归
//思路：递归找出两个节点的路径，然后寻找其中的分叉点
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findpath(TreeNode *root, TreeNode *p, vector<TreeNode *> &path){
        if(root == nullptr) return false;

        if(root->val == p->val || findpath(root->left, p, path) || findpath(root->right, p, path)){
            path.push_back(root);
            return  true;
        }

        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> p_path;
        findpath(root, p, p_path);
        vector<TreeNode *> q_path;
        findpath(root, q, q_path);

        reverse(p_path.begin(), p_path.end());
        reverse(q_path.begin(), q_path.end());

        int i;
        for(i = 0; i < p_path.size() && i < q_path.size(); i++){
            if(p_path[i] != q_path[i]){
                break;
            }
        }

        return p_path[i-1];

    }
};
