/*
 * 在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
 * 计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。
 */
//方法一：暴力
//思路：如果偷一个节点，则还要头它的四个孙子节点，如果不偷当前节点，则偷它的两个孩子
//因为有重复计算节点所以超时了
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
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return root->val;
        int val1 = root->val;
        if(root->left != nullptr) val1 += rob(root->left->left) + rob(root->left->right);
        if(root->right != nullptr) val1 += rob(root->right->left) + rob(root->right->right);
        int val2 = rob(root->left) + rob(root->right);
        return max(val1, val2);
    }
};

//记忆化地推，添加一个哈希表记录搜索过的节点
class Solution {
public:
    unordered_map<TreeNode*, int> hash;
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return root->val;
        if(hash.find(root) != hash.end()) return hash[root];
        int val1 = root->val;
        if(root->left != nullptr) val1 += rob(root->left->left) + rob(root->left->right);
        if(root->right != nullptr) val1 += rob(root->right->left) + rob(root->right->right);
        int val2 = rob(root->left) + rob(root->right);
        hash[root] = max(val1, val2);
        return max(val1, val2);
    }
};

//方法二：动态规划
//思路：用一个有2个元素的数组记录当前节点偷与不偷情况下能获得的最大利润
class Solution {
public:
    vector<int> robhelper(TreeNode* root){
        if(root == nullptr) vector<int>{0, 0};
        vector<int> leftVal = (root->left == nullptr) ? vector<int>{0, 0} : robhelper(root->left);
        vector<int> rightVal = (root->right == nullptr) ? vector<int>{0, 0} : robhelper(root->right);
        int val1 = root->val + leftVal[1] + rightVal[1];
        int val2 = max(leftVal[0], leftVal[1]) + max(rightVal[0], rightVal[1]);
        return vector<int>{val1, val2}; 
    }

    int rob(TreeNode* root) {
        vector<int> ans = robhelper(root);
        return max(ans[0], ans[1]); 
    }
};
