/* 
 * 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum ，判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。
 */
//方法一：递归
//思路：就是很简单的递归。。。
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        if(root->left == nullptr && root->right == nullptr){
            if(targetSum - root->val == 0){
                return true;
            }
            else{
                return false;
            }
        }

        bool leftFlag = false, rightFlag = false;  
        if(root->left) leftFlag = hasPathSum(root->left, targetSum - root->val);
        if(root->right) rightFlag = hasPathSum(root->right, targetSum - root->val);
        return leftFlag || rightFlag;
    }
};
//比上面精简些
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        if(root->left == nullptr && root->right == nullptr){
            if(targetSum - root->val == 0){
                return true;
            }
            else{
                return false;
            }
        }
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

//方法二：迭代
//思路：其实和递归一样
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        queue<pair<TreeNode*, int>> q;
        q.push(pair<TreeNode*, int>(root, targetSum));
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(!node.first->left && !node.first->right && node.second - node.first->val == 0){
                return true;
            }

            if(node.first->left)  q.push(pair<TreeNode*, int>(node.first->left, node.second-node.first->val));
            if(node.first->right)  q.push(pair<TreeNode*, int>(node.first->right, node.second-node.first->val));
        }
        return false;
    }
};
