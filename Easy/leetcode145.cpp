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

//方法三：morris遍历
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
    void addPath(vector<int> &ans, TreeNode *node){
        int count = 0;
        while(node != nullptr){
            ans.push_back(node->val);
            ++count;
            node = node->right;
        }
        reverse(ans.end() - count, ans.end());
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *p1 = root;
        TreeNode *p2 = nullptr;
        while(p1 != nullptr){
            if(p1->left != nullptr){
                p2 = p1->left;
                while(p2->right != nullptr && p2->right != p1){
                    p2 = p2->right;
                }
                if(p2->right == nullptr){
                    p2->right = p1;
                    p1 = p1->left;
                }
                else{
                    p2->right = nullptr;
                    addPath(ans, p1->left);
                    p1 = p1->right;
                }
            }
            else{
                p1 = p1->right;
            }
        }
        addPath(ans, root);
        return ans;
    }
};
