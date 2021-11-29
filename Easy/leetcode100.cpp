/*
 * 给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
 * 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
 */
//方法一：递归
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        else if(!p || !q) return false;
        else if(p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

//方法二：迭代
//队列
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode *> help;
        help.push(p);
        help.push(q);
        while(!help.empty()){
            auto l = help.front();
            help.pop();
            auto r = help.front();
            help.pop();
            if(!l && !r){
                continue;
            }

            if((!l || !r) || (l->val != r->val)){
                return false;
            }

            help.push(l->left);
            help.push(r->left);
            help.push(l->right);
            help.push(r->right);
        }
        return true;
    }
};
//栈
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode *> help;
        help.push(p);
        help.push(q);
        while(!help.empty()){
            auto l = help.top();
            help.pop();
            auto r = help.top();
            help.pop();
            if(!l && !r){
                continue;
            }

            if((!l || !r) || (l->val != r->val)){
                return false;
            }

            help.push(l->left);
            help.push(r->left);
            help.push(l->right);
            help.push(r->right);
        }
        return true;
    }
};
