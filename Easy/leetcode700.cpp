/* 给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。 */
//方法一：递归
//思路：根据二叉搜索树的性质递归
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr) return nullptr;
        if(root->val == val)    return root;
        else if(!root->left && !root->right)    return nullptr;

        if(root->val > val){
            return searchBST(root->left, val);
        }
        else{
            return searchBST(root->right, val);
        }
    }
};

//代码随想录递归
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr || root->val == val) return root;
        if(root->val > val) return searchBST(root->left, val);
        if(root->val < val) return searchBST(root->right, val);
        return nullptr;
    }
};

//方法二：迭代
//思路：实际上和递归相同
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != nullptr){
            if(root->val == val)    return root;
            else if(root->val > val)     root = root->left;
            else root = root->right;
        }
        return nullptr;
    }
};
