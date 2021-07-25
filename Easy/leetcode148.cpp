/*
 * 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
 * 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
 */
//方法一：数组暴力
//思路：用数组保存所有节点并排序，然后新建一条链表
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
    ListNode* sortList(ListNode* head) {
        vector<ListNode *> q;
        while(head){
            q.push_back(head);
            head = head->next;
        }

        sort(q.begin(), q.end(), [](const ListNode *a, const ListNode *b){
            return a->val < b->val;
        });
        ListNode *dummynode = new ListNode();
        ListNode *ptr = dummynode;
        for(auto node : q){
            ptr->next = new ListNode(node->val);
            ptr = ptr->next;
        }
        return dummynode->next;
    }
};

//这样来看可以直接保存链表的值而不用保存链表
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
    ListNode* sortList(ListNode* head) {
        vector<int> q;
        while(head){
            q.push_back(head->val);
            head = head->next;
        }

        sort(q.begin(), q.end());

        ListNode *dummynode = new ListNode();
        ListNode *ptr = dummynode;
        for(auto node : q){
            ptr->next = new ListNode(node);
            ptr = ptr->next;
        }
        return dummynode->next;
    }
};
