/*
 * 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
 * 假设二叉树中至少有一个节点。
 */
//方法一：广度优先搜索
//思路：使用广度优先搜索，先将右节点放入队列中，再将左结点放入，这样搜索的最后一个结点就是最底层最左边的结点
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
    int findBottomLeftValue(TreeNode* root) {
        TreeNode *node = nullptr;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                node = q.front();
                q.pop();
                if(node->right)  q.push(node->right);
                if(node->left) q.push(node->left);
            }
        }
        return node->val;
    }
};

//实际上题目要求的是最底层最左边的结点，并不是说明它就是左结点，所以这里也有可能是右节点
//因此只需要递归到最底层，同时先处理左结点即可
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
    int ans;
    int maxlen = -1;

    void findBottomHelper(TreeNode *root, int level){
        if(!root->left && !root->right){
            if(level > maxlen){
                ans = root->val;
                maxlen = level;
            }
            return;
        }

        if(root->left){
            findBottomHelper(root->left, level + 1);
        }

        if(root->right){
            findBottomHelper(root->right, level + 1);
        }
    }

    int findBottomLeftValue(TreeNode* root) {
        findBottomHelper(root, 0);
        return ans;
    }
};
