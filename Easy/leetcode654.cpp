/*
 * 给定一个不含重复元素的整数数组 nums 。一个以此数组直接递归构建的 最大二叉树 定义如下：
 * 二叉树的根是数组 nums 中的最大元素。
 * 左子树是通过数组中 最大值左边部分 递归构造出的最大二叉树。
 * 右子树是通过数组中 最大值右边部分 递归构造出的最大二叉树。
 * 返回有给定数组 nums 构建的 最大二叉树 。
 */
//方法一：递归
//思路：每次递归返回一个节点，该节点为当前数组l到r范围内的最大值，之后缩小数组范围取寻找节点的左孩子和右孩子
class Solution {
public:
    TreeNode* dfs(vector<int> &nums, int l, int r){
        if(l == r)  return nullptr;

        int rootVal = nums[l];
        int index = l;
        for(int i = index + 1; i != r; i++){
            if(nums[i] > rootVal){
                rootVal = nums[i];
                index = i;
            }
        }

        TreeNode* root = new TreeNode(rootVal);
        if(l + 1 == r){
            return root;
        }

        root->left = dfs(nums, l, index);
        root->right = dfs(nums, index + 1, r);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0)    return nullptr;
        return dfs(nums, 0, nums.size());
    }
};
