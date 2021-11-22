//反转一个单链表
//方法一：迭代
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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while(curr != nullptr){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
//该方法使用迭代，声明了三个指针，一个指向当前指针，一个指向当前指针的前面一个指针，一个指向当前指针的下一个指针
//首先让prev指向nullptr，curr指向head，next指向head->next
//之后将curr的next改为指向prev，再将三个指针分别向下移动一次
//最后当curr为nullptr时，pre就是反转后的头指针了
//这是真反转。。。
//下面的递归是和迭代相同思路的递归
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
    ListNode *reverse(ListNode *pre, ListNode *cur){
        if(cur == nullptr)  return pre;
        ListNode *temp = cur->next;
        cur->next = pre;
        
        return reverse(cur, temp);
    }

    ListNode* reverseList(ListNode* head) {
        return reverse(nullptr, head);
    }
};
//方法二：递归
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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){           //这里的第一个条件是判断head是否为空指针，如果为空，说明链表中没有结点，直接返回head。第二个条件是判断是否到达最后一个结点
            return head;
        }
        ListNode *newhead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;               //即使不是第一个结点，结点的next也会被置为nullptr，但是上一个结点会将他置为上一个结点
        return newhead;
    }
};
//该方法使用递归，实际上就是先运行到最后一个结点，然后返回指向最后一个结点的地址，在倒数第二个结点上，将最后一个结点的next指向倒数第二个结点
//newhead实际上就是指向最后一个结点的地址，也就是反转后的头结点，它从最后一个结点一直返回到开头
//需要注意的是，因为链表最后一个结点的next是nullptr，所以在代码中需要加上head->next=nullptr，否则返回到第一个节点时，它会指向第二个结点，从而形成了环
//从上面两个方法可以看出，反转链表用的都是将结点的next指针改为指向前面一个结点，使用的方法可以是定义一个指针指向结点的前面一个结点，又或者是使用递归的方法
