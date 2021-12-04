/* 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。 */
//方法一：迭代（一次遍历）
//思路：略
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans = root;
        while(true){
            if(p->val < ans->val && ans->val > q->val){
                ans = ans->left;
            }
            else if(p->val > ans->val && ans->val < q->val){
                ans = ans->right;
            }
            else{
                break;
            }
        }
        return ans;
    }
};
//方法二：递归（一次遍历）
//思路：略
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans = nullptr;
        if(root->val == p->val || root->val == q->val){
            ans = root;
        }
        else if((root->val > p->val && root->val < q->val) || (root->val < p->val && root->val > q->val)){
            ans = root;
        }
        else if((root->val > p->val && root->val > q->val)){
            ans = lowestCommonAncestor(root->left, p, q);
        }
        else{
            ans = lowestCommonAncestor(root->right, p, q);
        }
        return ans;
    }
};

//方法三：两次遍历
class Solution {
public:
    vector<TreeNode *> getpath(TreeNode *root, TreeNode *q){
        vector<TreeNode *> path;
        TreeNode *node = root;
        while(true){
            path.push_back(node);
            if(node->val > q->val){
                node = node->left;
            }
            else if(node->val < q->val){
                node = node->right;
            }
            else{
                break;
            }
        }
        return path;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> q_path = getpath(root, q);
        vector<TreeNode *> p_path = getpath(root, p);
        TreeNode *ans = nullptr;
        for(int i = 0; i < q_path.size() && i < p_path.size(); i++){
            if(q_path[i] == p_path[i]){
                ans = q_path[i];
            }
            else{
                break;
            }
        }
        return ans;
    }
};

//代码随想录递归
//思路：同不同二叉树的最近公共祖先思路相同，从底层向上层递归，如果一个节点的左子树和右子树都有pq，则该节点是最近公共祖先
//如果一个节点就是p或者q则直接返回该节点，否则递归该节点的左右孩子
//但是没有用到二叉搜索树的性质
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q)   return root;

        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);

        if(l != nullptr && r != nullptr){
            return root;
        }
        else if(l != nullptr){
            return l;
        }
        else{
            return r;
        }
        return nullptr;
    }
};

//代码随想录根据二叉搜索树性质的递归
//根据二叉搜索树的性质，pq的最近公共祖先实际上就是遍历过程中第一个值在pq之间的节点
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        else if(root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        else{
            return root;
        }
    }
};

//迭代
//思路：其实同上面的递归
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        while(root){
            if(root->val > p->val && root->val > q->val){
                root = root->left;
            }
            else if(root->val < p->val && root->val < q->val){
                root = root->right;
            }
            else{
                break;
            }
        }    
        return root;
    }
};
