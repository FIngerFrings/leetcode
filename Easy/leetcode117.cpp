/* 
 * 给定一个二叉树
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
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return root;
    }
};

//方法二：使用next指针
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
    void handle(Node* &last, Node* &p, Node* &nextstart){
        if(last){
            last->next = p;
        }
        if(!nextstart){
            nextstart = p;
        }
        last = p;
    }

    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        Node *start = root;
        while(start){
            Node *last = nullptr;
            Node *nextstart = nullptr;
            for(Node *p = start; p != nullptr; p = p->next){
                if(p->left){
                    handle(last, p->left, nextstart);
                }

                if(p->right){
                    handle(last, p->right, nextstart);
                }
            }
            start = nextstart;
        }
        return root;
    }
};
