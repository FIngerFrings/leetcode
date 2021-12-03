/* 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。 */
//方法一：中序遍历+递归+数组
//思路：有效的二叉搜索树中序遍历得到的数组应该是升序的
class Solution {
public:
    vector<int> nums;

    void dfs(TreeNode* root){
        if(root == nullptr) return;

        dfs(root->left);
        nums.push_back(root->val);
        dfs(root->right);
    }

    bool isValidBST(TreeNode* root) {
        dfs(root);
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= nums[i-1]){
                return false;
            }
        }
        return true;
    }
};

//递归，不需要数组，只需要记录前一个节点值
//初始值用LONG_MIN，因为范例中会有INT_MIN
class Solution {
public:
    long maxVal = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;

        bool left = isValidBST(root->left);
        if(maxVal < root->val)  maxVal = root->val;
        else    return false;
        bool right = isValidBST(root->right);
        return left && right;
    }
};
