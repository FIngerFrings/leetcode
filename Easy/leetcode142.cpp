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
//这是官方给出的哈希表解法，实际上和上面的一样
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> visited;
        while (head != nullptr) {
            if (visited.count(head)) {
                return head;
            }
            visited.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};

//方法二：双指针
//思路：使用快慢指针判断是否有环，如果有环，则将fast重置为head，然后slow和fast都一步一步跳，相遇的地方就是入环的节点
//证明见官方解答或markdown笔记
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
        if(head == nullptr || head->next == nullptr)    return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                fast = head;
                break;
            }
        }
        if(fast->next == nullptr || fast->next->next == nullptr){
            return NULL;
        }
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
        
    }
};

//官方比较间接的双指针
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
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != nullptr){
            slow = slow->next;
            if(fast->next == nullptr){
                return nullptr;
            }
            fast = fast->next->next;
            if(fast == slow){
                fast = head;
                while(fast != slow){
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};
