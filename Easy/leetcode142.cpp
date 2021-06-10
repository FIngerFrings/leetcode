/* 
 * 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
 * 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 7
 * 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。
 */ 
//方法一：我觉得算是暴力解法
//思路：遍历链表，将某个节点是否搜索过存放在哈希表中
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
    ListNode *detectCycle(ListNode *head) {
        map<ListNode *, int> q;
        int i = 0;
        while(head != nullptr){
            if(q.count(head)){
                return head;
            }
            else{
                q[head] = i++;
            }
            head = head->next;
        }
        
        return NULL;
    }
};
