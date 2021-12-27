/* 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。 *
//方法一：双指针
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
        while(ptrA != ptrB){
            if(ptrA == nullptr){
                ptrA = headB;
            }
            else{
                ptrA = ptrA->next;
            }
            
            if(ptrB == nullptr){
                ptrB = headA;
            }
            else{
                ptrB = ptrB->next;
            }
        }
        if(ptrA != nullptr) return ptrA;
        return nullptr;
    }
};

//方法二：哈希表
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> hash;
        while(headA != nullptr){
            hash.insert(headA);
            headA = headA->next;
        }

        while(headB != nullptr){
            if(hash.find(headB) != hash.end()){
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};

//方法三：代码随想录
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
        int lenA = 0, lenB = 0;
        while(ptrA != nullptr){
            ++lenA;
            ptrA = ptrA->next;
        }

        while(ptrB != nullptr){
            ++lenB;
            ptrB = ptrB->next;
        }

        ptrA = headA;
        ptrB = headB;
        if(lenA < lenB){
            swap(ptrA, ptrB);
            swap(lenA, lenB);
        }

        int gap = lenA - lenB;
        while(gap-- > 0){
            ptrA = ptrA->next;
        }

        while(ptrA != nullptr){
            if(ptrA == ptrB) return ptrA;
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
        return nullptr;
    }
};
