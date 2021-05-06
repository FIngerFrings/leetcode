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

//方法二：官方解法，使用双指针，快慢指针
/* 本方法需要读者对「Floyd 判圈算法」（又称龟兔赛跑算法）有所了解。
 * 假想「乌龟」和「兔子」在链表上移动，「兔子」跑得快，「乌龟」跑得慢。
 * 当「乌龟」和「兔子」从链表上的同一个节点开始移动时，如果该链表中没有环，那么「兔子」将一直处于「乌龟」的前方；如果该链表中有环，
 * 那么「兔子」会先于「乌龟」进入环，并且一直在环内移动。等到「乌龟」进入环时，由于「兔子」的速度快，它一定会在某个时刻与乌龟相遇，即套了「乌龟」若干圈。
 * 我们可以根据上述思路来解决本题。具体地，我们定义两个指针，一快一满。慢指针每次只移动一步，而快指针每次移动两步。初始时，慢指针在位置 head，而快指针在位置 head.next。
 * 这样一来，如果在移动的过程中，快指针反过来追上慢指针，就说明该链表为环形链表。否则快指针将到达链表尾部，该链表不为环形链表。
*/
/* 细节
 * 为什么我们要规定初始时慢指针在位置 head，快指针在位置 head.next，而不是两个指针都在位置 head（即与「乌龟」和「兔子」中的叙述相同）？
 * 观察下面的代码，我们使用的是 while 循环，循环条件先于循环体。由于循环条件一定是判断快慢指针是否重合，如果我们将两个指针初始都置于 head，
 * 那么 while 循环就不会执行。因此，我们可以假想一个在 head 之前的虚拟节点，慢指针从虚拟节点移动一步到达 head，快指针从虚拟节点移动两步到达 head.next，
 * 这样我们就可以使用 while 循环了。当然，我们也可以使用 do-while 循环。此时，我们就可以把快慢指针的初始值都置为 head。
*/
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) { //这一点是没想到的，在做链表的题之前最好先判断以此头指针或者头指针的下一个指针是否为空。而且要用nullptr而不是null
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
