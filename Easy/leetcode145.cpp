/* 给定一个二叉树，返回它的 后序 遍历。 */
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
    vector<int> ans;

    void hxbl(TreeNode* root){
        if(root == nullptr){
            return;
        }

        hxbl(root->left);
        hxbl(root->right);
        ans.push_back(root->val);

    }

    vector<int> postorderTraversal(TreeNode* root) {
        hxbl(root);
        return ans;
    }
};

//方法二：迭代
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> stk;
        TreeNode *pre = nullptr;
        while(root != nullptr || !stk.empty()){
            while(root != nullptr){
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if(root->right == nullptr || root->right == pre){
                ans.push_back(root->val);
                pre = root;
                root = nullptr;
            }
            else{
                stk.push(root);
                root = root->right;
            }
        }
        return ans;
    }
};
