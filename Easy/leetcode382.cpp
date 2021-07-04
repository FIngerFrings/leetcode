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

//方法二：水库采样
//思路：不同于数组，在未遍历完链表前，我们无法知道链表的总长度。这里我们就可以使用水库采样：遍历一次链表，在遍历到第 m 个节点时，有 1/m 的概率选择这个节点覆盖掉之前的节点选择。
//我们提供一个简单的，对于水库算法随机性的证明。对于长度为 n 的链表的第 m 个节点，最后被采样的充要条件是它被选择，且之后的节点都没有被选择。
//这种情况发生的概率为 1/m × m/m+1 × m+1/m+2 × · · · × n−1/n = 1/n。因此每个点都有均等的概率被选择。
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
    ListNode *ptr_;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        ptr_ = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res = ptr_->val;
        ListNode *ptr = ptr_->next;
        int i = 2;
        while(ptr){
            if((rand() % i) == 0){
                res = ptr->val;
            }
            ++i;
            ptr = ptr->next;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
