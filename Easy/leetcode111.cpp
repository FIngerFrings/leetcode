/*
 * 给定一个二叉树，找出其最小深度。
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 说明：叶子节点是指没有子节点的节点。
 */
//方法一：层序遍历
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
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = 0;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            ++ans;
            while(n--){
                auto node = q.front();
                q.pop();
                if(node->left == nullptr && node->right == nullptr){
                    return ans;
                }
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return ans;
    }
};

//方法二：递归
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
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr){
            return 1;
        }

        int mind = INT_MAX;
        if(root->left){
            mind = min(minDepth(root->left), mind); 
        }

        if(root->right){
            mind = min(minDepth(root->right), mind);
        }

        return mind + 1;
    }
};
