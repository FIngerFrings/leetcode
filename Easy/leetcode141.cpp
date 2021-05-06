/* 给定一个链表，判断链表中是否有环。
 * 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
 * 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
 * 如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
 * 如果链表中存在环，则返回 true 。 否则，返回 false 。
*/
//方法一：自己的方法，使用一个哈希表unordered_map标记是否有经过这个结点，如果经过，则相应的值+1，如果某给值为2，则说明之前经过以此这个结点，表明链表中存在环
//经过测试，该方法的执行时间和内存消耗较大，所以不推荐使用
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
    unordered_map<ListNode *, int> hasptr;
    bool hasCycle(ListNode *head) {
        ListNode *ptr = head;
        int pos = -1;
        while(ptr != nullptr){
            hasptr[ptr]++;
            pos++;
            if(hasptr[ptr] == 2){
                return true;
            }
            ptr = ptr->next;
        }
        pos = -1;
        return false;
    }
};
//官方给出的方法一也是使用哈希表，原理和我们相同，内存和时间也都消耗较大
//虽然代码看起来比较简洁，但是原理和我们相同
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> seen;  //不同的是官方使用的是unordered_set
        while (head != nullptr) { //而且他是直接使用头指针操作，但是我不想直接操作头指针，所以声明了另一个结点指针
            if (seen.count(head)) {
                return true;
            }
            seen.insert(head);
            head = head->next;
        }
        return false;
    }
};
