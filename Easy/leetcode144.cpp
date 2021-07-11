/* 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。 */
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

    void qxbl(TreeNode* root){
        if(!root){
            return;
        }

        ans.push_back(root->val);
        qxbl(root->left);
        qxbl(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        qxbl(root);
        return ans;
    }
};

//方法二：迭代
//思路：略，和前面中序遍历的迭代思路差不多，但是我觉得不够好
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> stk;
        while(root != nullptr || !stk.empty()){
            while(root != nullptr){
                ans.push_back(root->val);
                if(root->right != nullptr){
                    stk.push(root->right);
                }
                root = root->left;
            }
            if(!stk.empty()){
                root = stk.top();
                stk.pop();
            }
        }
        return ans;
    }
};

//是我写的不好，下面是官方的迭代，思路差不多
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> stk;
        while(root != nullptr || !stk.empty()){
            while(root != nullptr){
                ans.push_back(root->val);
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            root = root->right;
        }
        return ans;
    }
};

//方法三：moris前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *pre = nullptr;
        while(root != nullptr){
            if(root->left != nullptr){
                pre = root->left;
                while(pre->right != nullptr && pre->right != root){
                    pre = pre->right;
                }

                if(pre->right == nullptr){
                    ans.push_back(root->val);
                    pre->right = root;
                    root = root->left;
                }
                else{
                    root = root->right;
                    pre->right = nullptr;           //这里估计是为了不破坏二叉树的形状，我觉得实际上并不影响结果
                }
            }
            else{
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};
