/* 
 * 给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点
 * 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
 * 初始状态下，所有 next 指针都被设置为 NULL。
 */
//方法一：层序遍历
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto node = q.front();
                q.pop();
                if(n == 0){
                    node->next = nullptr;
                }
                else{
                    node->next = q.front();
                }
                if(node->left != nullptr)   q.push(node->left);
                if(node->right != nullptr)   q.push(node->right);
            }
        }
        return root;
    }
};

//方法二：使用next指针
//思路：使用next指针每次对当前节点的下一层操作
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        Node *leftmost = root;
        while(leftmost->left != nullptr){
            Node *node = leftmost;
            while(node != nullptr){
                node->left->next = node->right;
                if(node->next != nullptr){
                    node->right->next = node->next->left;
                }
                node = node->next;
            }
            leftmost = leftmost->left;
        }
        return root;
    }
};
