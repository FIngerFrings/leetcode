/* 给定二叉搜索树的根结点 root，返回值位于范围 [low, high] 之间的所有结点的值的和。*/
//方法一：深度优先搜索
//以下是我自己做的方法，同样也是深度优先搜索，实际上就是计算根节点左子树上位于范围内的所有结点的值的和以及右子树上位于范围内的所有结点的值的和
//然后计算根结点，如果根结点也在范围内，则返回根节点和上面两个的和
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
    int sum = 0;

    int search(TreeNode* root, int low, int high){
        if(root == nullptr){
            return 0;
        }

        if(root->left == nullptr && root->right == nullptr){
            if(root->val >= low && root->val <= high){
                return root->val;
            }
            else{
                return 0;
            }
        }

        if(root->val >= low && root->val <= high){
            return search(root->left, low, high) + search(root->right, low, high) + root->val;
        }
        
        if(root->val < low){
            return search(root->right, low, high);
        }

        return search(root->left, low, high);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        return search(root, low, high);
    }
};

//以下是官方解法，实际上和我的一样，只不过它直接把给的函数当作递归函数
class Solution {
public:
    int rangeSumBST(TreeNode *root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }
        if (root->val > high) {
            return rangeSumBST(root->left, low, high);
        }
        if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        }
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};

//方法二，广度优先算法
//思路：采用广度优先算法，使用队列依次将结点放入，然后再判断是否在区间内，同时将左右结点放入队列中
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        queue<TreeNode *> q({root});
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node == nullptr){
                continue;
            }

            if(node->val > high){
                q.push(node->left);
            }
            else if(node->val < low){
                q.push(node->right);
            }
            else{
                sum += node->val;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return sum;
    }
};

//这道还是挺经典的使用DFS和BFS的题目，对于DFS，因为还需要回溯，所以一般使用递归，而BFS一般则使用while循环配合队列
