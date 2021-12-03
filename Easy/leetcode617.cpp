/*
 * 给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。
 * 你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。
 */
//方法一：递归
//思路：将两个结点相加，并递归计算结点的左右子树
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 && root2){
            root1->val += root2->val;
        }
        else if(root1 || root2){
            return root1 ? root1 : root2;
        }
        else{
            return nullptr;
        }
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

//后来自己写的递归，不太好看
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr)    return nullptr;
        else if(root1 != nullptr && root2 != nullptr){
            TreeNode* root = new TreeNode(root1->val + root2->val);
            root->left = mergeTrees(root1->left, root2->left);
            root->right = mergeTrees(root1->right, root2->right);
            return root;
        }
        else if(root1 != nullptr){
            return root1;
        }
        else{
            return root2;
        }
    }
};

//代码随想录的递归，前序遍历
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1)  return root2;
        if(!root2)  return root1;

        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

//中序遍历
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1)  return root2;
        if(!root2)  return root1;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->val += root2->val;
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

//后序遍历
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1)  return root2;
        if(!root2)  return root1;
        root1->right = mergeTrees(root1->right, root2->right);
        root1->left = mergeTrees(root1->left, root2->left);
        root1->val += root2->val;
        return root1;
    }
};

//方法二：层序遍历
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1)  return root2;
        if(!root2)  return root1;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root1);
        q2.push(root2);
        while(!q1.empty()){
            auto node1 = q1.front();
            auto node2 = q2.front();
            q1.pop();
            q2.pop();
            node1->val += node2->val;
            if(node1->left && node2->left){
                q1.push(node1->left);
                q2.push(node2->left);
            }

            if(node1->right && node2->right){
                q1.push(node1->right);
                q2.push(node2->right);
            }

            if(!node1->left && node2->left){
                node1->left = node2->left;
            }

            if(!node1->right && node2->right){
                node1->right = node2->right;
            }
        }
        return root1;
    }
};
