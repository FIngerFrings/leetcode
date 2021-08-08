/* 返回与给定的前序和后序遍历匹配的任何二叉树。 */
//方法一：递归
//思路：找出左子树和右子树所在位置，使用递归处理
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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        if(n == 0)  return nullptr;
        TreeNode *root = new TreeNode(preorder[0]);
        if(n == 1)  return root;

        int i = 0;
        for(i = 0; i < n; i++){
            if(postorder[i] == preorder[1]){
                break;
            }
        }
        ++i;
        vector<int> temp1(preorder.begin() + 1, preorder.begin() + i + 1);
        vector<int> temp2(postorder.begin(), postorder.begin() + i);
        vector<int> temp3(preorder.begin() + i + 1, preorder.begin() + n);
        vector<int> temp4(postorder.begin() + i, postorder.begin() + n - 1);
        root->left = constructFromPrePost(temp1, temp2);
        root->right = constructFromPrePost(temp3, temp4);

        return root;
    }
};
