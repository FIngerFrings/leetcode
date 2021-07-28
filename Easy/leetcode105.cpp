/* 给定一棵树的前序遍历 preorder 与中序遍历  inorder。请构造二叉树并返回其根节点。 */
//方法一：递归
//思路：实质上就是那套通过前序和中序遍历得到二叉树的思想，这里不再赘述
//这是pdf的解法，但是会超时
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty())    return nullptr;
        unordered_map<int, int> dict;
        for(int i = 0; i < inorder.size(); i++){
            dict[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, dict, 0, preorder.size() - 1, 0);
    }

    TreeNode *buildTreeHelper(vector<int>& preorder, unordered_map<int, int> dict, int s0, int e0, int s1){
        if(s0 > e0){
            return nullptr;
        }

        int mid = preorder[s1];
        int index = dict[mid];
        int leftlen = index - s0;
        TreeNode *root = new TreeNode(mid);
        root->left = buildTreeHelper(preorder, dict, s0, index - 1, s1 + 1);
        root->right =  buildTreeHelper(preorder, dict, index + 1, e0, s1 + leftlen + 1);
        return root;
    }
};

//官方的解法，哈希表不应该当作形参
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
        unordered_map<int, int> q;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i = 0; i < n; i++){
            q[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, 0, n - 1, 0, n - 1);
    }

    TreeNode *buildTreeHelper(vector<int>& preorder, int pre_left, int pre_right, int in_left, int in_right){
        if(pre_left > pre_right){
            return nullptr;
        }

        int pre_root = pre_left;
        int in_root = q[preorder[pre_root]];
        int leftlen = in_root - in_left;
        TreeNode *root = new TreeNode(preorder[pre_root]);
        root->left = buildTreeHelper(preorder, pre_left + 1, pre_left + leftlen, in_left, in_root - 1);
        root->right = buildTreeHelper(preorder, pre_left + leftlen + 1, pre_right, in_root + 1, in_right);
        return root;
    }
};
//这里将哈希表当作全局参数就不会超时了，pdf的解法
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
    unordered_map<int, int> dict;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty())    return nullptr;
        for(int i = 0; i < inorder.size(); i++){
            dict[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, 0, preorder.size() - 1, 0);
    }

    TreeNode *buildTreeHelper(vector<int>& preorder, int s0, int e0, int s1){
        if(s0 > e0){
            return nullptr;
        }

        int mid = preorder[s1];
        int index = dict[mid];
        int leftlen = index - s0;
        TreeNode *root = new TreeNode(mid);
        root->left = buildTreeHelper(preorder, s0, index - 1, s1 + 1);
        root->right =  buildTreeHelper(preorder, index + 1, e0, s1 + leftlen + 1);
        return root;
    }
};

//方法二：
