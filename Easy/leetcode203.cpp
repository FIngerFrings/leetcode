/*
 * 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点
 */
//这题也是用到了双指针，发现不论是数组还是链表，如果要在数组或链表中查找某个对象并删除或者往后移动，则可以使用双“指针”的方法
//这里的指针打上引号是因为并不一定是传统意义上的指针，例如在对数组进行操作的时候，就可以用一个int类型的数据充当指针
//对于删除链表中的元素，如果删除的结点在链表中间则非常简单，直接将前面一个结点的next指针指向删除结点的next
//而如果是链表中的第一个指针，因为他没有前一个结点，所以可以在链表第一个结点前面添加一个哨兵结点，添加哨兵结点的目的是为了让第一个结点和后面节点的处理方式相同
//方法一：迭代，但是代码不够简洁，并且没有释放内存
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummyNode = new ListNode();
        dummyNode->next = head;
        ListNode *pre = dummyNode;
        while(head != nullptr){
            if(head->val == val){
                pre->next = head->next;
            }
            else{
                pre = head;
            }
            head = head->next;
        }
        return dummyNode->next;
    }
};
//迭代，官方解法更加简洁，但是仍然没有释放内存
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummyNode = new ListNode(0, head);
        ListNode *pre = dummyNode;
        while(pre->next != nullptr){
            if(pre->next->val == val){
                pre->next = pre->next->next;
            }
            else{
                pre = pre->next;
            }
        }
        return dummyNode->next;
    }
};
//迭代，代码随想录的方法，释放了内存
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummyNode = new ListNode(0, head);
        ListNode *pre = dummyNode;
        while(pre->next != nullptr){
            if(pre->next->val == val){
                ListNode *temp = pre->next;
                pre->next = pre->next->next;
                delete temp;
            }
            else{
                pre = pre->next;
            }
        }
        ListNode *newHead = dummyNode->next;
        delete dummyNode;
        return newHead;
    }
};

//方法二：递归
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr){
            return head;
        }
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};

class Solution {
    void dfs(ListNode* pre, ListNode* head, int val){
        if(head == nullptr) return;

        if(head->val == val){
            ListNode* toDel = head;
            pre->next = head->next;
            dfs(pre, head->next, val);
            delete toDel;
        }
        else{
            dfs(pre->next, head->next, val);
        }
    }
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyNode = new ListNode();
        dummyNode->next = head;
        ListNode* pre = dummyNode;
        dfs(pre, head, val);
        return dummyNode->next;
    }
};
