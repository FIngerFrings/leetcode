/* 给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。 */
//方法一：递归
//思路：根据二叉搜索树的性质，中序遍历的得到的数组是非降序的，所以可以通过记录中序遍历过程中的最大值以及前一个节点的个数，从而得到BST中的众数
//和代码随想录的思路一样
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
    vector<int> ans;
    TreeNode* pre = nullptr;
    int count = 0;
    int maxCount = 0;
    void dfs(TreeNode* root){
        if(root == nullptr) return;

        dfs(root->left);
        if(pre == nullptr){
            pre = root;
            ++count;
        }
        else if(root->val == pre->val){
            ++count;
        }
        else{
            if(count == maxCount){
                ans.push_back(pre->val);
            }
            else if(count > maxCount){
                maxCount = count;
                ans.clear();
                ans.push_back(pre->val);
            }
            pre = root;
            count = 1;
        }
        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        if(root == nullptr) return {};
        dfs(root);
        if(count == maxCount){
            ans.push_back(pre->val);
        }
        else if(count > maxCount){
            maxCount = count;
            ans.clear();
            ans.push_back(pre->val);
        }
        return ans;
    }
};

//哈希表+递归
//思路：通过递归遍历二叉树，并使用哈希表记录节点出现频率，之后对哈希表进行排序，得到众数
//没用运用二叉搜索树的性质
class Solution {
public:
    unordered_map<int, int> hash;
    
    void dfs(TreeNode* root){
        if(root == nullptr) return;

        dfs(root->left);
        ++hash[root->val];
        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        if(root == nullptr) return {};
        dfs(root);
        vector<pair<int, int>> nums(hash.begin(), hash.end());
        sort(nums.begin(), nums.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            return a.second > b.second;
        });
        vector<int> ans{nums[0].first};
        for(int i = 1; i < nums.size(); i++){
            if(nums[i].second == nums[0].second){
                ans.push_back(nums[i].first);
            }
            else break;
        }
        return ans;
    }
};

//代码随想录的递归，比我的要好些
class Solution {
public:
    vector<int> ans;
    TreeNode* pre = nullptr;
    int count = 0;
    int maxCount = 0;
    void dfs(TreeNode* root){
        if(root == nullptr) return;

        dfs(root->left);
        if(pre == nullptr){
            count = 1;
        }
        else if(root->val == pre->val){
            ++count;
        }
        else{
            count = 1;
        }
        pre = root;

        if(count == maxCount){
            ans.push_back(pre->val);
        }
        else if(count > maxCount){
            maxCount = count;
            ans.clear();
            ans.push_back(root->val);
        }
        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        if(root == nullptr) return {};
        dfs(root);
        return ans;
    }
};

//代码随想录迭代
//思路：同代码随想录递归
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if(root == nullptr) return {};
        stack<TreeNode*> stk;
        int count = 0;
        int maxCount = 0;
        TreeNode* pre = nullptr;
        stk.push(root);
        vector<int> ans;
        while(!stk.empty()){
            auto node = stk.top();
            stk.pop();
            if(node != nullptr){
                if(node->right) stk.push(node->right);

                stk.push(node);
                stk.push(nullptr);

                if(node->left)  stk.push(node->left);
            }
            else{
                node = stk.top();
                stk.pop();
                
                if(pre == nullptr){
                    count = 1;
                }
                else if(node->val == pre->val){
                    ++count;
                }
                else{
                    count = 1;
                }

                pre = node;

                if(count == maxCount){
                    ans.push_back(pre->val);
                }
                else if(count > maxCount){
                    maxCount = count;
                    ans.clear();
                    ans.push_back(pre->val);
                }
            }
        }
        return ans;
    }
};
