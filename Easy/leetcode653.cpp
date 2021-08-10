/* 给定一个二叉搜索树 root 和一个目标结果 k，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。 */
//方法一：中序遍历
//思路：先中序遍历得到数组，然后双指针查看
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
    vector<int> q;

    void dfs(TreeNode *root){
        if(root == nullptr) return;

        dfs(root->left);
        q.push_back(root->val);
        dfs(root->right);
    }

    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        int l = 0, r = q.size() - 1;
        while(l < r){
            if(q[l] + q[r] == k){
                return true;
            }
            else if(q[l] + q[r] < k){
                ++l;
            }
            else{
                --r;
            }
        }
        return false;
    }
};

//方法二：递归
//思路：遍历所有节点，查看当前哈希表中是否存在k-root->val，存在则返回true，否则继续遍历下去，同时将当前节点插入哈希表
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
    unordered_set<int> hash;

    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;

        if(hash.count(k - root->val)){
            return true;
        }

        hash.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};

//方法三：迭代
//思路：同上
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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> hash;
        stack<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                root = q.top();
                q.pop();
                if(hash.count(k-root->val)){
                    return true;
                }
                hash.insert(root->val);
                if(root->left)  q.push(root->left);
                if(root->right) q.push(root->right);
            }
        }
        return false;
    }
};
