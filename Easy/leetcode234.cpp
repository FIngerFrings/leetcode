/* 请判断一个链表是否为回文链表。 */
//方法一：使用数组
//思路：将链表中的值存放在数组中，然后判断数组是否回文
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
    bool isPalindrome(ListNode* head) {
        vector<int> q;
        while(head != nullptr){
            q.push_back(head->val);
            head = head->next;
        }

        int l = 0, r = q.size() - 1;
        while(l <= r && q[l] == q[r]){
            ++l;
            --r;
        }
        return l >= r;
    }
};
