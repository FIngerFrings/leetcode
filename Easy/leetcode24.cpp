/*
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 */
//方法一：暴力解法
//思路：使用三个指针分别指向当前节点、前面一个节点和下一个节点，然后交换
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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)   return head;
        ListNode *pre = nullptr;
        ListNode *cur = head;
        head = head->next;
        bool flag = true;
        while(cur->next != nullptr){
            if(flag){
                ListNode *temp = cur->next;
                if(pre != nullptr){
                    pre->next = temp;
                }
                cur->next = temp->next;
                temp->next = cur;
                flag = false;
            }
            else{
                pre = cur;
                cur = cur->next;
                flag = true;
            }
        }
        return head;
    }
};
