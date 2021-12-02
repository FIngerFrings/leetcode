/* 根据一棵树的中序遍历与后序遍历构造二叉树。 */
//方法一：递归
//思路:找出中序遍历和后序遍历中的左右子树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if(n == 0)  return nullptr;
        TreeNode *root = new TreeNode(postorder[n - 1]);
        if(n == 1)  return root;

        int l = 0;
        for(l = 0; l < n; l++){
            if(inorder[l] == postorder[n - 1]){
                break;
            }
        }

        vector<int> temp1(inorder.begin(), inorder.begin() + l);
        vector<int> temp2(postorder.begin(), postorder.begin() + l);
        vector<int> temp3(inorder.begin() + l + 1, inorder.end());
        vector<int> temp4(postorder.begin() + l, postorder.end() - 1);

        root->left = buildTree(temp1, temp2);
        root->right = buildTree(temp3, temp4);
        return root;

    }
};

//方法二：递归
//思路：实际上和上面一样的，不过更好一点
//需要注意的是先得到右节点，再得到左节点
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
    int root_inx;
    unordered_map<int, int> hash;

    TreeNode *buildTreehepler(int in_left, int in_right, vector<int> &inorder, vector<int> postorder){
        if(in_left > in_right)  return nullptr;

        int root_val = postorder[root_inx];
        int in_idx = hash[root_val];

        root_inx--;
        TreeNode *root = new TreeNode(root_val);
        root->right = buildTreehepler(in_left, root_inx - 1, inorder, postorder);
        root->left = buildTreehepler(root_inx + 1, in_right, inorder, postorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        root_inx = n - 1;
        for(int i = 0; i < n; i++){
            hash[inorder[i]] = i;
        }

        return buildTreehepler(0, n - 1, inorder, postorder);
    }
};

//代码随想录递归
class Solution {
public:
    TreeNode* buildTreeHelper(vector<int> &inorder, int inorderBegin, int inorderEnd, vector<int> &postorder, int postorderBegin, int postorderEnd){
        if(inorderBegin == inorderEnd)  return nullptr;

        int rootVal = postorder[postorderEnd - 1];
        TreeNode* root = new TreeNode(rootVal);
        if(inorderBegin + 1 == inorderEnd){
            return root;
        }

        int index;
        for(index = inorderBegin; index < inorderEnd; index++){
            if(inorder[index] == rootVal)   break;
        }

        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = index;
        int rightInorderBegin = index + 1;
        int rightInorderEnd = inorderEnd;

        int leftPostorderBegin = postorderBegin;
        int leftPostorderEnd = postorderBegin + index - inorderBegin;
        int rightPostorderBegin = leftPostorderEnd;
        int rightPostorderEnd = postorderEnd - 1;

        root->left = buildTreeHelper(inorder, leftInorderBegin, leftInorderEnd, postorder, leftPostorderBegin, leftPostorderEnd);
        root->right = buildTreeHelper(inorder, rightInorderBegin, rightInorderEnd, postorder, rightPostorderBegin, rightPostorderEnd);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0)    return nullptr;
        return buildTreeHelper(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};
