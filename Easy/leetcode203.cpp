//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点
//没做出来
//答案
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
