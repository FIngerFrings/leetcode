/*
 * 给你二叉搜索树的根节点 root ，该树中的两个节点被错误地交换。请在不改变其结构的情况下，恢复这棵树。
 * 进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用常数空间的解决方案吗？
 */
//方法一：显式中序遍历
//思路：按照中序遍历排序，然后寻找顺序不对的节点，之后再遍历一遍数组交换节点
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
    vector<int> nums;

    void inorder(TreeNode *root){
        if(root == nullptr){
            return;
        }

        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }

    pair<int, int> swaped(TreeNode *root){
        int n = nums.size();
        int x = -1, y = -1;
        for(int i = 0; i < n - 1; i++){
            if(nums[i + 1] < nums[i]){
                y = nums[i + 1];
                if(x == -1){
                    x = nums[i];
                }
                else{
                    break;
                }
            }
        }
        return {x, y};
    }

    void recoverTreeHelper(TreeNode *root, int &count, int x, int y){
        if(root == nullptr || count == 0){
            return;
        }

        if(root->val == x || root->val == y){
            --count;
            root->val = root->val == x ? y : x;
        }

        recoverTreeHelper(root->left, count, x, y);
        recoverTreeHelper(root->right, count, x, y);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        auto temp = swaped(root);
        int count = 2;
        recoverTreeHelper(root, count, temp.first, temp.second);
    }
};

//方法二：隐式中序遍历
//思路：思路基本和上面一样，不过使用递归实现中序遍历
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
    void recoverTree(TreeNode* root) {
        stack<TreeNode *> stk;
        TreeNode *x = nullptr;
        TreeNode *y = nullptr;
        TreeNode *pre = nullptr;
        while(!stk.empty() || root != nullptr){
            while(root){
                stk.push(root);
                root = root->left;
            }

            root = stk.top();
            stk.pop();
            if(pre != nullptr && root->val < pre->val){
                y = root;
                if(x == nullptr){
                    x = pre;
                }
                else{
                    break;
                }
            }
            pre = root;
            root = root->right;
        }
        swap(x->val, y->val);
    }
};

//方法三：moris中序遍历
//思路：本质上和上面相同，不过就是使用moris实现中序遍历
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
    void recoverTree(TreeNode* root) {
        TreeNode *x = nullptr;
        TreeNode *y = nullptr;
        TreeNode *pre = nullptr;
        while(root){
            TreeNode *node = root->left;
            if(node){
                while(node->right != nullptr && node->right != root){
                    node = node->right;
                }

                if(node->right == nullptr){
                    node->right = root;
                    root = root->left;
                }
                else{
                    if(pre != nullptr && pre->val > root->val){
                        y = root;
                        if(x == nullptr){
                            x = pre;
                        }
                    }
                    node->right = nullptr;
                    pre = root;
                    root = root->right;
                }
            }
            else{
                if(pre != nullptr && pre->val > root->val){
                    y = root;
                    if(x == nullptr){
                        x = pre;
                    }
                }
                pre = root;
                root = root->right;
            }
        }
        swap(x->val, y->val);
    }
};
