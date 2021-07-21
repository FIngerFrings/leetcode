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
