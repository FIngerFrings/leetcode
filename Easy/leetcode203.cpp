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
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* sentinel = new ListNode(0);
    sentinel->next = head;

    ListNode *prev = sentinel, *curr = head, *toDelete = nullptr;
    while (curr != nullptr) {
      if (curr->val == val) {
        prev->next = curr->next;
        toDelete = curr;
      } else prev = curr;

      curr = curr->next;

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
