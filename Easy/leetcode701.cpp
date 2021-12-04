/*
 * 给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。
 */
//方法一：递归
//思路：递归找到合适的位置，然后逐层返回
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            TreeNode* node = new TreeNode(val);
            return node;
        }

        if(root->val > val){
            TreeNode* l = insertIntoBST(root->left, val);
            root->left = l;
        }
        else{
            TreeNode* r = insertIntoBST(root->right, val);
            root->right = r;
        }
        return root;
    }
};

//有两行代码是多余的
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            TreeNode* node = new TreeNode(val);
            return node;
        }

        if(root->val > val){
            root->left = insertIntoBST(root->left, val);
        }
        else{
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};

//迭代
//思路：记录前一次递归的节点，然后遍历二叉搜索树，当遍历到空节点时，将新节点插入到父节点下
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            TreeNode* node = new TreeNode(val);
            return node;
        }

        TreeNode* p = nullptr;
        TreeNode* cur = root;
        while(cur != nullptr){
            p = cur;
            if(cur->val > val)  cur = cur->left;
            else    cur = cur->right;
        }

        if(p->val > val){
            p->left = new TreeNode(val);
        }
        else{
            p->right = new TreeNode(val);
        }
        return root;
    }
};
