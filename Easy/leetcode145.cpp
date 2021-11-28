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
//代码随想录遍历
//递归
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
    void Traversal(vector<int> &ans, TreeNode *root){
        if(root == nullptr) return;
        Traversal(ans, root->left);
        Traversal(ans, root->right);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        Traversal(ans, root);
        return ans;
    }
};
//迭代
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
        stack<TreeNode *> stk;
        vector<int> ans;
        if(root == nullptr) return{};
        stk.push(root);
        while(!stk.empty()){
            auto node = stk.top();
            stk.pop();
            ans.push_back(node->val);
            if(node->left) stk.push(node->left);
            if(node->right) stk.push(node->right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
//统一迭代
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
        stack<TreeNode *> stk;
        if(root == nullptr) return{};
        stk.push(root);
        vector<int> ans;
        while(!stk.empty()){
            TreeNode *node = stk.top();
            if(node != nullptr){
                stk.pop();
                stk.push(node);
                stk.push(nullptr);

                if(node->right) stk.push(node->right);
                if(node->left) stk.push(node->left);
            }
            else{
                stk.pop();
                node = stk.top();
                ans.push_back(node->val);
                stk.pop();
            }
        }
        return ans;
    }
};
