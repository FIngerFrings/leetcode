/*
 * 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
 * 假设二叉树中至少有一个节点。
 */
//方法一：层序遍历
//思路：层序遍历，获取每一层的第一个数，遍历完后得到的就是最底层最左边节点的值
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = root->val;
        while(!q.empty()){
            int n = q.size();
            ans = q.front()->val;
            while(n--){
                auto node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return ans;
    }
};

//方法二：递归
//思路：实际上就是找到深度最大且最左边的节点，通过遍历过程中传入当前节点的深度，并判断当前节点是否是叶子节点，如果是则比较深度
//找到其中深度最大的叶子节点，为了保证是最左边的，所以可以前序遍历
class Solution {
public:
    int maxHeight;
    int ans;

    void traversal(TreeNode* root, int height){
        if(root->left == nullptr && root->right == nullptr){
            if(height > maxHeight){
                maxHeight = height;
                ans = root->val;
            }
        }

        if(root->left) traversal(root->left, height + 1);
        if(root->right) traversal(root->right, height + 1);
    }

    int findBottomLeftValue(TreeNode* root) {
        maxHeight = INT_MIN;
        traversal(root, 1);
        return ans;
    }
};
