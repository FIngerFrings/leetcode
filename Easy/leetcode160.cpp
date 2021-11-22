/*
 * 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
 */
//方法一：哈希表
//思路：略
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
        if(headA == nullptr || headB == nullptr)    return nullptr;
        unordered_set<ListNode *> hash;
        while(headA != nullptr || headB != nullptr){
            if(headA != nullptr){
                if(hash.count(headA)){
                    return headA;
                }
                else{
                    hash.insert(headA);
                    headA = headA->next;
                }
            }

            if(headB != nullptr){
                if(hash.count(headB)){
                    return headB;
                }
                else{
                    hash.insert(headB);
                    headB = headB->next;
                }
                
            }
        }
        return nullptr;
    }
};

//官方的哈希表
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
        unordered_set<ListNode *> hash;
        while(headA != nullptr){
            hash.insert(headA);
            headA = headA->next;
        }

        while(headB != nullptr){
            if(hash.count(headB)){
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};

//方法二：双指针
//思路：使用两个指针分别指向headA和headB，假设两个链表有相交点，相交点之前的链表长度分别为a和b，相交之后的长度为c
//则两个指针分别前进，当l1为空时就指向headB，l2为空时指向headA，则到相交点两个指针经过的节点数都为a+b+c
//如果没有相交节点，则两个指针会同时到达空节点
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
        ListNode *l1 = headA;
        ListNode *l2 = headB;
        while(l1 != l2){
            l1 = l1 ? l1->next : headB;
            l2 = l2 ? l2->next : headA;
        }
        return l1;
    }
};

//方法三：代码随想录
//思路：详细见代码随想录
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
        if(headA == nullptr || headB == nullptr){
            return nullptr;
        }

        ListNode *l1 = headA;
        ListNode *l2 = headB;
        int s1 = 0, s2 = 0;
        while(l1 != nullptr){
            ++s1;
            l1 = l1->next;
        }

        while(l2 != nullptr){
            ++s2;
            l2 = l2->next;
        }

        l1 = headA, l2 = headB;

        if(s2 > s1){
            swap(s1, s2);
            swap(l1, l2);
        }

        int gap = s1 - s2;
        while(gap--){
            l1 = l1->next;
        }

        while(l1 != nullptr){
            if(l1 == l2){
                return l1;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        return nullptr;
    }
};
