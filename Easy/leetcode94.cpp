/* 给定一个二叉树的根节点 root ，返回它的 中序 遍历。 */
//方法一：递归
//思路：略
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
    vector<int> ans;

    void zxbl(TreeNode* root){
        if(root == nullptr){
            return;
        }

        zxbl(root->left);
        ans.push_back(root->val);
        zxbl(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        zxbl(root);
        return ans;
    }
};

//方法二：迭代
//思路：实际原理和递归相同
//先从根节点开始，迭代将其左节点压入栈，迭代完后将当前栈中最上面的节点弹出，并将其值放入数组中
//之后将其变成它的右节点，因为叶子节点的右节点为空，所以会跳过当前节点，并弹出当前栈顶节点
//当前栈顶节点就是第一个弹出的节点的父节点，将其加入数组中，然后变成它的右节点，又继续将右节点及其所有左节点压入栈
//循环上面的过程，最后中序遍历链表
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> stk;
        while(root != nullptr || !stk.empty()){
            while(root != nullptr){
                stk.push(root);
                root = root->left;
            }

            root = stk.top();
            stk.pop();
            ans.push_back(root->val);
            root = root->right;
        }
        return ans;
    }
};

//迭代中有个核心思想就是，遍历到当前节点时，其左子树肯定已经遍历完了，所以接下来肯定遍历其右子树，所以下一步才是将其变成他的右孩子

//方法三：moris中序遍历
//思路：详见官方解答，这里不太说得清
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *pre = nullptr;
        while(root != nullptr){
            if(root->left != nullptr){
                pre = root->left;
                while(pre->right != nullptr && pre->right != root){
                    pre = pre->right;
                }

                if(pre->right == nullptr){
                    pre->right = root;
                    root = root->left;
                }
                else{
                    ans.push_back(root->val);
                    root = root->right;
                    pre->right = nullptr;
                }
            }
            else{
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};
