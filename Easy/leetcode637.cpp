/* 给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。 */
//方法一：广度优先搜索
//思路：略
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            double sum = 0;
            int num = q.size();
            int n = num;
            while(num-- > 0){
                auto node = q.front();
                q.pop();
                sum += node->val;
                if(node->right) q.push(node->right);
                if(node->left)  q.push(node->left);
            }
            double av = sum / n;
            ans.push_back(av);
        }
        return ans;
    }
};

//方法二：深度优先
//思路：略
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sums;
        vector<int> counts;
        if(root == nullptr){
            return {};
        }
        dfs(root, sums, counts, 0);
        vector<double> ans;
        for(int i = 0; i < sums.size(); i++){
            ans.push_back(sums[i] / counts[i]);
        }
        return ans;
    }

    void dfs(TreeNode *root, vector<double> &sums, vector<int> &counts, int level){
        if(root == nullptr) return;
        if(level < sums.size()){
            sums[level] += root->val;
            counts[level] += 1;
        }
        else{
            sums.push_back(1.0 * root->val);
            counts.push_back(1);
        }

        dfs(root->left, sums, counts, level + 1);
        dfs(root->right, sums, counts, level + 1);
    }
};
