/* 
 * 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
 */
//方法一：递归
//思路：首先找到要删除的节点，之后最重要的是找到代替它的节点，如果删除的节点是一个叶子节点，则直接返回nullptr。
//如果左孩子或者右孩子有一个为空节点，则返回那个非空的孩子。如果左右孩子都有，则去右子树中寻找最小的那个节点，将其替代被删除的节点
//同时需要在右子树中删除那个节点
class Solution {
public:
    TreeNode* getMinNode(TreeNode* root){
        if(root->left == nullptr){
            return root;
        }

        return getMinNode(root->left);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;

        if(root->val == key){
            if(root->left == nullptr){
                return root->right;
            }
            else if(root->right == nullptr){
                return root->left;
            }
            else{
                TreeNode* minNode = getMinNode(root->right);
                minNode->right = deleteNode(root->right, minNode->val);
                minNode->left = root->left;
                return minNode;
            }
        }
        else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else{
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};

//其实可以直接将要删除节点的左子树放到其右子树中最小节点的左节点上
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;

        if(root->val == key){
            if(root->left == nullptr){
                return root->right;
            }
            else if(root->right == nullptr){
                return root->left;
            }
            else{
                TreeNode* minNode = root->right;
                while(minNode->left != nullptr){
                    minNode = minNode->left;
                }
                minNode->left = root->left;
                return root->right;
            }
        }
        else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else{
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};

//迭代
//思路：同上面的递归
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root){
        if(root == nullptr) return nullptr;
        if(root->right == nullptr)  return root->left;
        TreeNode* cur = root->right;
        while(cur->left != nullptr){
            cur = cur->left;
        }
        cur->left = root->left;
        return root->right;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        TreeNode* pre = nullptr;
        TreeNode* cur = root;
        while(cur != nullptr){
            if(cur->val == key) break;
            pre = cur;
            if(cur->val > key) cur = cur->left;
            else cur = cur->right;
        }

        if(pre == nullptr){
            return deleteNode(cur);
        }

        if(pre->left != nullptr && pre->left->val == key){
            pre->left = deleteNode(cur);
        }
        else if(pre->right != nullptr && pre->right->val == key){
            pre->right = deleteNode(cur);
        }
        return root;
    }
};
