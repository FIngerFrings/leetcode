/* 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。 */
//方法一：迭代（一次遍历）
//思路：略
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans = root;
        while(true){
            if(p->val < ans->val && ans->val > q->val){
                ans = ans->left;
            }
            else if(p->val > ans->val && ans->val < q->val){
                ans = ans->right;
            }
            else{
                break;
            }
        }
        return ans;
    }
};
//方法二：递归（一次遍历）
//思路：略
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans = nullptr;
        if(root->val == p->val || root->val == q->val){
            ans = root;
        }
        else if((root->val > p->val && root->val < q->val) || (root->val < p->val && root->val > q->val)){
            ans = root;
        }
        else if((root->val > p->val && root->val > q->val)){
            ans = lowestCommonAncestor(root->left, p, q);
        }
        else{
            ans = lowestCommonAncestor(root->right, p, q);
        }
        return ans;
    }
};
