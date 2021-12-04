/* 给定一个二叉搜索树，请将它的每个节点的值替换成树中大于或者等于该节点值的所有节点值之和。 */
//方法一：递归
class Solution {
public:
    int sum = 0;

    void dfs(TreeNode* root){
        if(root == nullptr) return;

        dfs(root->right);
        root->val += sum;
        sum = root->val;
        dfs(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
        return root;
    }
};

//方法二：迭代
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(root == nullptr) return nullptr;
        int pre = 0;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            auto node = stk.top();
            stk.pop();
            if(node != nullptr){
                if(node->left) stk.push(node->left);

                stk.push(node);
                stk.push(nullptr);

                if(node->right) stk.push(node->right);
            }
            else{
                node = stk.top();
                stk.pop();
                node->val += pre;
                pre = node->val;
            }
        }
        return root;
    }
};
