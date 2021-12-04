/* 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。 */
//方法一：递归+前序遍历
//每次通过数组中点创建节点，然后通过递归获得左子树和右子树
class Solution {
public:
    TreeNode* dfs(vector<int> &nums, int l, int r){
        if(l == r)  return nullptr;

        int index = (l + r) / 2;
        TreeNode *root = new TreeNode(nums[index]);
        if(l + 1 == r)  return root;

        root->left = dfs(nums, l, index);
        root->right = dfs(nums, index + 1, r);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)    return nullptr;
        return dfs(nums, 0, nums.size());
    }
};

//方法二：迭代
//思路：同上
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)    return nullptr;
        queue<TreeNode*> qn;
        queue<int> ql;
        queue<int> qr;
        TreeNode* root = new TreeNode(0);
        qn.push(root);
        ql.push(0);
        qr.push(nums.size());
        while(!qn.empty()){
            auto node = qn.front();
            int l = ql.front();
            int r = qr.front();
            qn.pop();
            ql.pop();
            qr.pop();
            int mid = l + (r - l) / 2;
            node->val = nums[mid];

            if(l < mid){
                node->left = new TreeNode(0);
                qn.push(node->left);
                ql.push(l);
                qr.push(mid);
            }

            if(mid + 1 < r){
                node->right = new TreeNode(0);
                qn.push(node->right);
                ql.push(mid + 1);
                qr.push(r);
            }
        }
        return root;
    }
};
