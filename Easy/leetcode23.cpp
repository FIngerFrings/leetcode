/*
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 */
//方法一：顺序合并
//思路：对于合并多个链表，首先需要知道怎么合并两个链表
//然后再依次将多个链表合并
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
    ListNode *mergeLists(ListNode *a, ListNode *b){
        if(a == nullptr || b == nullptr)    return a == nullptr ? b : a;
        ListNode *head = new ListNode();
        ListNode *tail = head;
        while(a != nullptr && b != nullptr){
            if(a->val < b->val){
                tail->next = a;
                a = a->next;
            }
            else{
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = (a == nullptr) ? b : a;
        return head->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans = nullptr;
        for(int i = 0; i < lists.size(); i++){
            ans = mergeLists(ans, lists[i]);
        }
        return ans;
    }
};
