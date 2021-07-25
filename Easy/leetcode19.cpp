/*
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 * 进阶：你能尝试使用一趟扫描实现吗？
 */
//方法一：暴力
//思路：略
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num = 0;
        ListNode *ptr = head;
        while(ptr){
            ++num;
            ptr = ptr->next;
        }
        int h = num;
        ptr = head;
        while(--h > n){
            ptr = ptr->next;
        }
        if(num == n){
            return head->next;
        }
        else{
            ptr->next = ptr->next->next;
        }
        return head;
    }
};

//方法二：栈
//思路：使用栈将所有节点放入，然后依次弹出栈，弹出n个节点后，栈顶节点就是要删除节点的前面一个节点
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyNode = new ListNode();
        dummyNode->next = head;
        stack<ListNode *> stk;
        ListNode *ptr = dummyNode;
        while(ptr){
            stk.push(ptr);
            ptr = ptr->next;
        }

        int i = 0;
        while(i < n){
            ++i;
            stk.pop();
        }
        ptr = stk.top();
        ptr->next = ptr->next->next;
        return dummyNode->next;
    }
};

//方法三：快慢指针
//思路：可以设定两个指针，一个指针指向哑节点，一个指针指向头节点
//快指针先移动n步，然后两个指针一起移动，当快指针到达链表尾时
//满指针到达倒数n个节点的前面那个节点
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummynode = new ListNode();
        dummynode->next = head;
        ListNode *fast = head;
        ListNode *low = dummynode;
        int i = 0;
        while(i < n){
            ++i;
            fast = fast->next;
        }

        while(fast){
            fast = fast->next;
            low = low->next;
        }

        low->next = low->next->next;
        return dummynode->next;
    }
};
