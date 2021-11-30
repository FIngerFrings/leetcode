/*
 * 给定一个二叉树，找出其最小深度。
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 说明：叶子节点是指没有子节点的节点。
 */
//方法一：层序遍历
//思路：根据层序遍历的遍历顺序，当我们找到第一个叶子节点的时候就直接返回当前的层数
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

//方法二：后序遍历+递归
//思路：计算左子树和右子树的深度，取其中的最小值+1作为当前节点的最小深度
//但是需要注意的是如果根据二叉树的最大深度修改代码则会错，因为如果当前节点没有左节点或者右节点，则得到的结果为1，但实际上这并不是结果
//要左节点和右节点都为空时才能返回1
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
