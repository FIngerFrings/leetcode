/*/
 * 给出二叉树的根节点 /root，树上每个节点都有一个不同的值。
 * 如果节点值在 to_delete 中出现，我们就把该节点从树上删去，最后得到一个森林（一些不相交的树构成的集合）。
 * 返回森林中的每棵树。你可以按任意顺序组织答案。
 */
//方法一：递归
//思路：从根节点开始递归，如果递归到的节点需要删除，则将它自身变为空指针，在这之前还需要判断左右子树是否需要删除
//根据上面的思路，可以使用递归实现从底向上递归，首先从叶子节点开始判断是否需要删除，这样返回是回到父节点，这样就可以先处理子节点再处理父节点了
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode *> forest;
        unordered_set<int> dict(to_delete.begin(), to_delete.end());
        root = helper(root, dict, forest);
        if(root){
            forest.push_back(root);
        }
        return forest;
    }

    TreeNode *helper(TreeNode *root, unordered_set<int> &dict, vector<TreeNode *> &forest){
        if(!root){
            return root;
        }

        root->left = helper(root->left, dict, forest);
        root->right = helper(root->right, dict, forest);
        if(dict.count(root->val)){
            if(root->left){
                forest.push_back(root->left);
            }

            if(root->right){
                forest.push_back(root->right);
            }

            root = nullptr;
        }
        return root;
    }

};
