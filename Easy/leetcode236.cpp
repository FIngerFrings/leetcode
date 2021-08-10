/* 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。 */
//方法一：递归
//思路：递归找出两个节点的路径，然后寻找其中的分叉点
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findpath(TreeNode *root, TreeNode *p, vector<TreeNode *> &path){
        if(root == nullptr) return false;

        if(root->val == p->val || findpath(root->left, p, path) || findpath(root->right, p, path)){
            path.push_back(root);
            return  true;
        }

        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> p_path;
        findpath(root, p, p_path);
        vector<TreeNode *> q_path;
        findpath(root, q, q_path);

        reverse(p_path.begin(), p_path.end());
        reverse(q_path.begin(), q_path.end());

        int i;
        for(i = 0; i < p_path.size() && i < q_path.size(); i++){
            if(p_path[i] != q_path[i]){
                break;
            }
        }

        return p_path[i-1];

    }
};


//方法二：递归
//思路：通过递归判断左子树或右子树中是否有两个节点，如果有则将ans置为root
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *ans;

    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q){
        if(root == nullptr) return false;

        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);

        if((lson && rson) || (root->val == p->val || root->val == q->val) && (lson || rson)){
            ans = root;
        }

        return lson || rson || (root->val == p->val || root->val == q->val);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};

//方法三：哈希表
//思路：记录每个节点的父节点，然后从p节点开始不断向上，记录经过的节点，然后从q节点开始不断向上，查看p节点是否经过，首先查找的那个就是答案
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, TreeNode *> hash;
    unordered_map<int, bool> vis;
    void dfs(TreeNode *root){
        if(root->left){
            hash[root->left->val] = root;
            dfs(root->left);
        }

        if(root->right){
            hash[root->right->val] = root;
            dfs(root->right);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        hash[root->val] = nullptr;
        dfs(root);
        TreeNode *ans;
        while(p){
            vis[p->val] = true;
            p = hash[p->val];
        }

        while(q){
            if(vis[q->val]){
                ans = q;
                break;
            }
            q = hash[q->val];
        }
        return ans;
    }
};
