/*
 * 给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在，返回 true ；否则，返回 false 。
 * 二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。
 */
//方法一：递归
//思路：递归root，如果root的值和subroot的值相等，则检查以他们为根节点的数是否相等
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
    bool check(TreeNode *root, TreeNode *subRoot){
        if(!root && !subRoot){
            return true;
        }
        else if((root && !subRoot) || (!root && subRoot)){
            return false;
        }

        if(root->val == subRoot->val){
            return check(root->left, subRoot->left) && check(root->right, subRoot->right);
        }
        else{
            return false;
        }
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)   return false;

        if(subRoot->val == root->val && check(root, subRoot)){
            return true;
        }
        else{
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
    }
};

//代码随想录
class Solution {
public:
    bool check(TreeNode *root, TreeNode *subRoot){
        if(!root && !subRoot){
            return true;
        }
        else if((!root || !subRoot) || (root->val != subRoot->val)){
            return false;
        }
        return check(root->left, subRoot->left) && check(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)   return false;
        return check(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
