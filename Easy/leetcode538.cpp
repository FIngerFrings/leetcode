/*
 * 给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。
 */
//方法一：数组+中序遍历
//首先中序遍历将所有结点存放在数组中，然后从后面遍历数组，将每个结点的值加上其后面结点的值
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
    vector<TreeNode *> q;

    void midordered(TreeNode *root){
        if(!root)   return;
        midordered(root->left);
        q.push_back(root);
        midordered(root->right);
    }

    TreeNode* convertBST(TreeNode* root) {
        midordered(root);
        for(int i = q.size() - 2; i >= 0; i--){
            q[i]->val += q[i + 1]->val;
        }
        return root;
    }
};

//方法二：反中序遍历
//思路：在中序遍历过程中就把所得到的值加上，不过得反向中序遍历
class Solution {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if(root){
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
    }
};

class Solution {
public:
    int sum = 0;

    void dfs(TreeNode* root){
        if(root == nullptr) return;

        dfs(root->right);
        root->val += sum;
        sum = root->val;
        dfs(root->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
};

//方法三：moris遍历
//思路：略
class Solution {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        TreeNode *node = root;
        while(node){
            TreeNode *pre = node->right;
            if(pre){
                while(pre->left != nullptr && pre->left != node){
                    pre = pre->left;
                }

                if(pre->left == nullptr){
                    pre->left = node;
                    node = node->right;
                }
                else{
                    pre->left = nullptr;
                    sum += node->val;
                    node->val = sum;
                    node = node->left;
                }
            }
            else{
                sum += node->val;
                node->val = sum;
                node = node->left;
            }
        }
        return root;
    }
};

//迭代
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr) return nullptr;
        int pre = 0;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            auto node = stk.top();
            stk.pop();
            if(node != nullptr){
                if(node->left) stk.push(node->left);

                stk.push(node);
                stk.push(nullptr);

                if(node->right) stk.push(node->right);
            }
            else{
                node = stk.top();
                stk.pop();
                node->val += pre;
                pre = node->val;
            }
        }
        return root;
    }
};
