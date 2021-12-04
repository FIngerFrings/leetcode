/*
 * 给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界 high。通过修剪二叉搜索树，使得所有节点的值在[low, high]中。
 * 修剪树不应该改变保留在树中的元素的相对结构（即，如果没有被移除，原有的父代子代关系都应当保留）。 可以证明，存在唯一的答案。
 * 所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。
 */
//方法一：递归
//思路：应该要知道递归的思想，别去太纠结递归怎么实现的，感觉递归就是一个玄学
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root)   return root;
        if(root->val > high){
            return trimBST(root->left, low, high);
        }

        if(root->val < low){
            return trimBST(root->right, low, high);
        }

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

//代码随想录递归
//思路：根据二叉搜索树的性质，如果当前遍历到的节点值大于high，则直接返回递归左节点
//箱单如果小于low，则返回递归右节点
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == nullptr) return nullptr;

        if(root->val > high){
            return trimBST(root->left, low, high);
        }

        if(root->val < low){
            return trimBST(root->right, low, high);
        }

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

//方法二：迭代
//思路：首先将root移动到[low, high]中间，然后剪枝左子树和右子树
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == nullptr) return nullptr;
        while(root != nullptr && (root->val > high || root->val < low)){
            if(root->val > high) root = root->left;
            else if(root->val < low) root = root->right;
        }

        TreeNode* cur = root;
        while(cur != nullptr){
            while(cur->left != nullptr && cur->left->val < low){
                cur->left = cur->left->right;
            }
            cur = cur->left;
        }

        cur = root;
        while(cur != nullptr){
            while(cur->right != nullptr && cur->right->val > high){
                cur->right = cur->right->left;
            }
            cur = cur->right;
        }

        return root;
    }
};
