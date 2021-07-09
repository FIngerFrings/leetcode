/*
 * 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 */
//方法一：模拟
//思路：略
//需要注意的是链表的创建以及怎么添加新节点
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *tail = nullptr;
        ListNode *head = nullptr;
        int add = 0;
        while(l1 != nullptr || l2 != nullptr || add != 0){
            int i = (l1 == nullptr) ? 0 : l1->val;
            int j = (l2 == nullptr) ? 0 : l2->val;
            int result = i + j + add;
            int x = result % 10;
            add = result / 10;
            if(l1){
                l1 = l1->next;
            }
            if(l2){
                l2 = l2->next;
            }
            if(!head){
                head = new ListNode(x);
                tail = head;
            }
            else{
                tail->next = new ListNode(x);
                tail = tail->next;
            }
        }
        return head;
    }
};
