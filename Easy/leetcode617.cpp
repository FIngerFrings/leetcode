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

//方法二：广度优先
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
        if(!root1){
            return root2;
        }
        else if(!root2){
            return root1;
        }

        queue<TreeNode *> q;
        queue<TreeNode *> q1;
        queue<TreeNode *> q2;
        auto merged = new TreeNode(root1->val + root2->val);
        q.push(merged);
        q1.push(root1);
        q2.push(root2);
        while(!q1.empty() && !q2.empty()){
            auto node = q.front();
            auto node1 = q1.front();
            auto node2 = q2.front();
            q.pop();
            q1.pop();
            q2.pop();
            auto left1 = node1->left;
            auto left2 = node2->left;
            auto right1 = node1->right;
            auto right2 = node2->right;
            if(left1 || left2){
                if(left1 && left2){
                    node->left = new TreeNode(left1->val + left2->val);
                    q.push(node->left);
                    q1.push(left1);
                    q2.push(left2);
                }
                else if(left1 != nullptr){
                    node->left = left1;
                }
                else{
                    node->left = left2;
                }
            }
            if(right1 || right2){
                if(right1 && right2){
                    node->right = new TreeNode(right1->val + right2->val);
                    q.push(node->right);
                    q1.push(right1);
                    q2.push(right2);
                }
                else if(right1 != nullptr){
                    node->right = right1;
                }
                else{
                    node->right = right2;
                }
            }
        }
        return merged;
    }
};/**
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
        if(!root1){
            return root2;
        }
        else if(!root2){
            return root1;
        }

        queue<TreeNode *> q;
        queue<TreeNode *> q1;
        queue<TreeNode *> q2;
        auto merged = new TreeNode(root1->val + root2->val);
        q.push(merged);
        q1.push(root1);
        q2.push(root2);
        while(!q1.empty() && !q2.empty()){
            auto node = q.front();
            auto node1 = q1.front();
            auto node2 = q2.front();
            q.pop();
            q1.pop();
            q2.pop();
            auto left1 = node1->left;
            auto left2 = node2->left;
            auto right1 = node1->right;
            auto right2 = node2->right;
            if(left1 || left2){
                if(left1 && left2){
                    node->left = new TreeNode(left1->val + left2->val);
                    q.push(node->left);
                    q1.push(left1);
                    q2.push(left2);
                }
                else if(left1 != nullptr){
                    node->left = left1;
                }
                else{
                    node->left = left2;
                }
            }
            if(right1 || right2){
                if(right1 && right2){
                    node->right = new TreeNode(right1->val + right2->val);
                    q.push(node->right);
                    q1.push(right1);
                    q2.push(right2);
                }
                else if(right1 != nullptr){
                    node->right = right1;
                }
                else{
                    node->right = right2;
                }
            }
        }
        return merged;
    }
};
