//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点
//没做出来
//答案
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
//在c++中是可以给结构体添加构造函数的
//操作结点的方式一般都使用指针
class Solution {
  public:
  //head一般用来表示头指针
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* sentinel = new ListNode(0); //只有当声明的指针是个新的地址地址时才使用new，而如果像下面的prev和curr一样声明之后马上就会赋值一个已经存在了的地址时，就不用使用new
    sentinel->next = head;  //head在这里更像是指向链表第一个结点的指针，而不是头结点（我理解的头结点是一个结点，结点中的next指针指向链表第一个结点）
    //因为toDelete一开始并不指向谁，所以设置为nullptr
    ListNode *prev = sentinel, *curr = head, *toDelete = nullptr; //之前会有一种思维惯性，就是将指向结点的指针看成一个结点，但从这题来看，应该就单纯的把它看成一个指针
    while (curr != nullptr) {
      if (curr->val == val) {
        prev->next = curr->next;
        toDelete = curr;
      } else prev = curr;

      curr = curr->next;
      //因为每次toDelete都会被赋值为nullptr，所以这里需要判断一下是否为空指针，如果是空指针则也不用删除了，其实我是更偏向于让toDelete在上面一个if语句中删除的
      //这里实际上是不行的，因为如果在上面的if语句中删除了toDelete，则curr就会被删除
      if (toDelete != nullptr) {
        delete toDelete;
        toDelete = nullptr;
      }
    }

    ListNode *ret = sentinel->next;
    delete sentinel;
    return ret;
  }
};
//这题也是用到了双指针，发现不论是数组还是链表，如果要在数组或链表中查找某个对象并删除或者往后移动，则可以使用双“指针”的方法
//这里的指针打上引号是因为并不一定是传统意义上的指针，例如在对数组进行操作的时候，就可以用一个int类型的数据充当指针
//对于删除链表中的元素，如果删除的结点在链表中间则非常简单，直接将前面一个结点的next指针指向删除结点的next
//而如果是链表中的第一个指针，因为他没有前一个结点，所以可以在链表第一个结点前面添加一个哨兵结点，添加哨兵结点的目的是为了让第一个结点和后面节点的处理方式相同
//方法：迭代，但是代码不够简洁，并且没有释放内存
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
//方法：迭代，官方解法更加简洁，但是仍然没有释放内存
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
//方法：迭代，代码随想录的方法，释放了内存
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

//方法：递归
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr){
            return head;
        }
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};
