/* 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。*/
//方法一：广度优先算法
//下面的方法是我看了答案后自己写的广度优先算法，是通过将结点和层数绑定在一起，最后根据层数分类，不过显示运行时间太长，不过整个逻辑应该是没问题，可能会有小错误
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode *, int>> q;
        vector<pair<int, int>> t;
        q.push({root, 0});
        while(!q.empty()){
            auto a = q.front();
            TreeNode *node = a.first;
            int level = a.second;
            if(node == nullptr){
                continue;
            }
            t.push_back({node->val, level});
            q.push({node->left, level+1});
            q.push({node->right, level+1});
        }
        vector<int> temp;
        vector<vector<int>> ans;
        int n = 0;
        for(auto nnode : t){
            int value = nnode.first;
            int llevel = nnode.second;
            if(llevel == n){
                temp.push_back(value);
            }
            else{
                n = llevel;
                ans.push_back(temp);
                temp.clear();
                temp.push_back(value);
            }
        }
        return ans;

    }
};
//考虑如何使用哈希表实现上面的方法
//下面就是官方给出的答案，并没有用哈希表或者level来保存层数，而是记录下每层的个数，然后使用for循环遍历每层中的结点，这时候同样也可以加结点到队列中，因为已经知道了每一层有几个结点
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int CurrentLevelSize = q.size();    //记录每层有多少结点
            ans.push_back(vector<int> ());      //这里要记得加入一个空的数组，实际上就是添加一层
            for(int i = 0; i < CurrentLevelSize; i++){
                TreeNode *node = q.front();
                q.pop();
                ans.back().push_back(node->val);    //这个是一开始没想到的，因为ans.back()返回的是一个vector<int>，因此可以使用push_back(),实际上就是把vector<int>和vector<vector<int>>结合起来了
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};
//下面的方法是错误的，我想的是能不能不用判断是否为空，直接将左右结点插入，然后通过上面的if语句，如果是空指针则直接跳到下一次循环
//但实际上这样会加入新的一层，因为最后的叶子结点也会将它的左右空结点加入到队列中，然后导致又插入了一个空数组
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int CurrentLevelSize = q.size();
            ans.push_back(vector<int> ());
            for(int i = 0; i < CurrentLevelSize; i++){
                TreeNode *node = q.front();
                q.pop();
                if(node == nullptr){
                    continue;
                }
                ans.back().push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ans;
    }
};
