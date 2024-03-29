/* 
 * 设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。
 * 在链表类中实现这些功能：
 * get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
 * addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
 * addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
 * addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
 * deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
 */
//方法一：模拟
class MyLinkedList {
public:
    struct ListNode{
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *node) : val(x), next(node) {}
    };

    MyLinkedList() {
        dummyNode = new ListNode();
        lSize = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= lSize){
            return -1;
        }
        ListNode *temp = dummyNode;
        while(index--){
            temp = temp->next;
        }
        return temp->next->val;
    }
    
    void addAtHead(int val) {
        ListNode *node = new ListNode(val, dummyNode->next);
        dummyNode->next = node;
        ++lSize;
    }
    
    void addAtTail(int val) {
        ListNode *node = new ListNode(val);
        ListNode *temp = dummyNode;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = node;
        ++lSize;
    }
    
    void addAtIndex(int index, int val) {
        if(index > lSize){
            return;
        }

        ListNode *node = new ListNode(val);
        ListNode *temp = dummyNode;
        
        while(index--){
            temp = temp->next;
        }

        node->next = temp->next;
        temp->next = node;
        ++lSize;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= lSize){
            return;
        }

        ListNode *temp = dummyNode;
        while(index--){
            temp = temp->next;
        }
        ListNode *del = temp->next;
        temp->next = temp->next->next;
        delete del;
        --lSize;
    }

private:
    ListNode *dummyNode;
    int lSize;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
