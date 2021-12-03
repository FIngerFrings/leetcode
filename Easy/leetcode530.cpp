/* 给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。 */
//方法一：中序遍历
//思路：通过中序遍历找到最小差值
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
    int minsub = INT_MAX;
    TreeNode *pre = nullptr;
    void midordered(TreeNode *root){
        if(!root)   return;
        midordered(root->left);
        if(!pre){
            pre = root;
        }
        else{
            minsub = min(root->val - pre->val, minsub);
            pre = root;
        }
        midordered(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        midordered(root);
        return minsub;
    }
};

//方法二：递归+中序遍历
class Solution {
public:
    int ans;
    TreeNode* pre = nullptr;

    void dfs(TreeNode* root){
        if(root == nullptr) return;

        dfs(root->left);
        if(pre != nullptr){
            ans = min(ans, root->val - pre->val);
        }
        pre = root;
        dfs(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        ans = INT_MAX;
        dfs(root);
        return ans;
    }
};

//方法二：迭代+中序遍历
//思路：实际上同递归
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        TreeNode* pre = nullptr;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            auto node = stk.top();
            if(node != nullptr){
                stk.pop();
                
                if(node->right)  stk.push(node->right);
                stk.push(node);
                stk.push(nullptr);
                if(node->left)  stk.push(node->left);
            }
            else{
                stk.pop();
                node = stk.top();
                stk.pop();

                if(pre != nullptr){
                    ans = min(ans, node->val - pre->val);
                }
                pre = node;
            }
        }
        return ans;
    }
};
