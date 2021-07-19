/*
 * 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
 * 请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
 */
//方法一：普通的方法
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)   return head;
        ListNode *dummylist = new ListNode(0);
        ListNode *ptr = dummylist;
        ListNode *cur = head;
        while(cur != nullptr && cur->next != nullptr){
            ListNode *nextTemp = cur->next;
            cur->next = nextTemp->next;
            nextTemp->next = nullptr;
            ptr->next = nextTemp;
            ptr = ptr->next;
            if(cur->next){
                cur = cur->next;
            }
        }
        cur->next = dummylist->next;
        return head;
    }
};

//其实和上面的思路差不多，但是代码比较简洁
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)   return head;
        ListNode *evenhead = head->next;
        ListNode *odd = head;
        ListNode *even = evenhead;
        while(even != nullptr && even->next != nullptr){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenhead;
        return head;
    }
};
