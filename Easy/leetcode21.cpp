/* 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。  */
//方法一：迭代
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p = nullptr;
        ListNode *head = nullptr;
        while(l1 != nullptr || l2 != nullptr){
            int x = (l1 == nullptr) ? INT_MAX : l1->val;
            int y = (l2 == nullptr) ? INT_MAX : l2->val;
            int t = min(x, y);
            if(head == nullptr){
                head = new ListNode(t);
                p = head;
            }
            else{
                p->next = new ListNode(t);
                p = p->next;
            }
            if(t == x){
                l1 = l1->next;
            }
            else{
                l2 = l2->next;
            }
        }
        return head;
    }
};

//方法二：递归
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
    ListNode *head = nullptr;
    ListNode *p = nullptr;

    void sx(ListNode* l1, ListNode* l2){
        if(l1 == nullptr && l2 == nullptr){
            return;
        }

        int x = (l1 == nullptr) ? INT_MAX : l1->val;
        int y = (l2 == nullptr) ? INT_MAX : l2->val;
        int t = min(x, y);
        if(head == nullptr){
            head = new ListNode(t);
            p = head;
        }
        else{
            p->next = new ListNode(t);
            p = p->next;
        }
        if(t == x){
            sx(l1->next, l2);
        }
        else{
            sx(l1, l2->next);
        }
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        sx(l1, l2);
        return head;
    }
};
