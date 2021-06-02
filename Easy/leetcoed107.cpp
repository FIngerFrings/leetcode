/* 给定一个二叉树，返回其节点值自底向上的层序遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）*/
//方法一：广度优先算法
//思路:实际上就是leetcoed102的结果反转就行了
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int currentLevelSize = q.size();
            ans.push_back(vector<int> ());
            for(int i = 0; i < currentLevelSize; i++){
                auto node = q.front();
                q.pop();
                ans.back().push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
