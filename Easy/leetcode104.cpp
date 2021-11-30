/*
 * 给定一个二叉树，找出其最大深度。
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 * 说明: 叶子节点是指没有子节点的节点。
 */
//方法一：递归
//思路：计算左子树和右子树上的深度，取最大值+1就是当前节点的深度
class Solution {
public:
    int getheight(TreeNode *root){
        if(root == nullptr){
            return 0;
        }
        return max(getheight(root->right), getheight(root->left)) + 1;
    }

    int maxDepth(TreeNode* root) {
        return getheight(root);
    }
};

//直接使用当前函数递归
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

//上面递归实际上是后序遍历二叉树，先遍历左子树，然后遍历右子树，最后访问当前节点

//方法二：广度优先（层序遍历）
//思路：使用层序遍历，每遍历一层就将结果+1，直到最后一层得到深度
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;
        while(!q.empty()){
            int n = q.size();
            while(n-- > 0){
                auto node = q.front();
                q.pop();
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
            ++depth;
        }
        return depth;
    }
};

//前序遍历 + 递归
//思路：实际上就是通过前序遍历遍历所有节点，让每个节点都知道自己在哪一层，然后记录最大的层数就是深度
class Solution {
public:
    int ans;
    void maxDepthHelper(TreeNode *root, int depth){
        ans = max(ans, depth);
        if(root->left == nullptr && root->right == nullptr){
            return;
        }

        if(root->left != nullptr){
            maxDepthHelper(root->left, depth + 1);
        }

        if(root->right != nullptr){
            maxDepthHelper(root->right, depth + 1);
        }

        return;
    }

    int maxDepth(TreeNode* root) {
        ans = 0;
        if(root == nullptr) return ans;
        maxDepthHelper(root, 1);
        return ans;
    }
};
