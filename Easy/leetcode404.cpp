/* 计算给定二叉树的所有左叶子之和。 */
//方法一：递归+前序遍历
//思路：实际上就是遍历所有节点，判断每个节点是否有左子节点且左子节点是否为叶子节点
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
    void getSum(TreeNode *root, int &sum){
        if(!root->left && !root->right){
            return;
        }

        if(root->left && !root->left->left && !root->left->right){
            sum += root->left->val;
        }

        if(root->left){
            getSum(root->left, sum);
        }

        if(root->right){
            getSum(root->right, sum);
        }
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) return 0;
        int sum = 0;
        getSum(root, sum);
        return sum;
    }
};

//递归+后序遍历
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = sumOfLeftLeaves(root->left);
        int right = sumOfLeftLeaves(root->right);

        int mid = 0;
        if(root->left && !root->left->left && !root->left->right){
            mid += root->left->val;
        }

        return left + right + mid;
    }
};

//方法二：迭代
//思路：同样是遍历所有节点，然后判断自己的左子节点是否是叶子节点
//队列
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = 0;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node->left && !node->left->left && !node->left->right){
                ans += node->left->val;
            }

            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        return ans;
    }
};
//栈
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = 0;
        stack<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            auto node = q.top();
            q.pop();
            if(node->left && !node->left->left && !node->left->right){
                ans += node->left->val;
            }

            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        return ans;
    }
};
