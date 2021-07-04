/* 
 * 给定一个单链表，随机选择链表的一个节点，并返回相应的节点值。保证每个节点被选的概率一样。
 * 进阶:
 * 如果链表十分大且长度未知，如何解决这个问题？你能否使用常数级空间复杂度实现？
 */
//方法一：我也不知道什么方法
//思路：总之就是用rand随机得到一个数，然后再去遍历链表
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
    int n = 0;
    ListNode* ptr_ = nullptr;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        ListNode* ptr = head;
        ptr_ = head;
        while(ptr){
            ++n;
            ptr = ptr->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int pos = rand() % n;
        ListNode *ptr = ptr_;
        for(int i = 0; i < pos - 1; i++){
            ptr = ptr->next;
        }
        return ptr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
