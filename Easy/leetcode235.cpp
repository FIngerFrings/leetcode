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

//方法三：两次遍历
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
    vector<TreeNode *> getpath(TreeNode *root, TreeNode *q){
        vector<TreeNode *> path;
        TreeNode *node = root;
        while(true){
            path.push_back(node);
            if(node->val > q->val){
                node = node->left;
            }
            else if(node->val < q->val){
                node = node->right;
            }
            else{
                break;
            }
        }
        return path;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> q_path = getpath(root, q);
        vector<TreeNode *> p_path = getpath(root, p);
        TreeNode *ans = nullptr;
        for(int i = 0; i < q_path.size() && i < p_path.size(); i++){
            if(q_path[i] == p_path[i]){
                ans = q_path[i];
            }
            else{
                break;
            }
        }
        return ans;
    }
};
