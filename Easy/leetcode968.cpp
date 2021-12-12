/*
 * 给定一个二叉树，我们在树的节点上安装摄像头。
 * 节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。
 * 计算监控树的所有节点所需的最小摄像头数量。
 */
 //方法一：贪心
//思路：叶子节点的父节点一定要安装摄像头，当所有叶子节点的父节点安装完摄像头后，删掉三层，又会有新的叶子节点
//我觉得基本思路就像上面说的，但是实际上就是分状态，3个状态，0是无覆盖，1是摄像头，2是有覆盖，后序遍历，获得左右孩子的状态，根据孩子的状态返回自己的状态
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
    int ans = 0;

    int dfs(TreeNode* root){
        if(root == nullptr) return 2;

        int l = dfs(root->left);
        int r = dfs(root->right);

        if(l == 0 || r == 0){
            ++ans;
            return 1;
        }
        else if(l == 1 || r == 1){
            return 2;
        }
        
        return 0;
    }

public:
    int minCameraCover(TreeNode* root) {
        if(root == nullptr) return 0;
        if(dfs(root) == 0){
            ++ans;
        }
        return ans;
    }
};
