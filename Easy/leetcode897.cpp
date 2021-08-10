/* 给你一棵二叉搜索树，请你 按中序遍历 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。 */
//方法一：递归
//思路：略
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
    TreeNode *ans = new TreeNode();
    TreeNode *node = ans;
    void dfs(TreeNode *root){
        if(root == nullptr) return;

        dfs(root->left);
        node->right = new TreeNode(root->val);
        node = node->right;
        dfs(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        dfs(root);
        return ans->right;
    }
};

//方法二：morris遍历
//思路：略
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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *ans = new TreeNode();
        TreeNode *node = ans;
        while(root){
            TreeNode *pre = root->left;
            if(pre){
                while(pre->right != nullptr && pre->right != root){
                    pre = pre->right;
                }

                if(pre->right == nullptr){
                    pre->right = root;
                    root = root->left;
                }
                else{
                    pre->right = nullptr;
                    node->right = new TreeNode(root->val);
                    node = node->right;
                    root = root->right;
                }
            }
            else{
                node->right = new TreeNode(root->val);
                node = node->right;
                root = root->right;
            }
        }
        return ans->right;
    }
};

//方法三：迭代
//思路：略
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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *ans = new TreeNode();
        TreeNode *node = ans;
        stack<TreeNode *> q;

        while(!q.empty() || root){
            while(root){
                q.push(root);
                root = root->left;
            }

            root = q.top();
            q.pop();
            node->right = new TreeNode(root->val);
            node = node->right;
            root = root->right;
        }
        return ans->right;
    }
};
