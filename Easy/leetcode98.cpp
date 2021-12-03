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

//递归，不过这次不是记录上一个节点的值，而是直接记录上一个节点
//不用像上一般一样得注意INT_MIN
class Solution {
public:
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;

        bool left = isValidBST(root->left);
        if(pre == nullptr || pre->val < root->val)  pre = root;
        else    return false;
        bool right = isValidBST(root->right);
        return left && right;
    }
};

//方法二：迭代
//思路：实际上同递归，都是中序遍历，然后记录前一个节点用于对比
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        TreeNode* pre = nullptr;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* node = stk.top();
            if(node != nullptr){
                stk.pop();
                
                if(node->right)  stk.push(node->right);
                stk.push(node);
                stk.push(nullptr);
                if(node->left) stk.push(node->left);
            }
            else{
                stk.pop();
                node = stk.top();
                stk.pop();

                if(pre == nullptr || pre->val < node->val)  pre = node;
                else return false;
            }
        }
        return true;
    }
};
