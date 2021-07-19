/* 请判断一个链表是否为回文链表。 */
//方法一：使用数组
//思路：将链表中的值存放在数组中，然后判断数组是否回文
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
    bool isPalindrome(ListNode* head) {
        vector<int> q;
        while(head != nullptr){
            q.push_back(head->val);
            head = head->next;
        }

        int l = 0, r = q.size() - 1;
        while(l <= r && q[l] == q[r]){
            ++l;
            --r;
        }
        return l >= r;
    }
};

//方法二：递归
//思路：正常的判断回文串的方法是从两边往中间移动，然后判断是否相等
//但是链表不好移动，所以可以使用递归+另外一个指针的方法模拟上面的方法
//先让一个指针指向头节点，然后递归到最后一个节点，返回的过程实际上就是从尾节点回到头节点的过程
//而在这过程中让那个节点同时往后移动，就可以模拟数组判断回文串的过程了
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
    ListNode *frontptr;
public:
    bool hw(ListNode *head){
        if(head != nullptr){
            if(!hw(head->next)){
                return false;
            }

            if(frontptr->val != head->val){
                return false;
            }
            frontptr = frontptr->next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        frontptr = head;
        return hw(head);
    }
};

//方法三：快慢指针
//思路：基本思路就是找到链表的中点，然后将后半部分翻转，之后对比两个链表，之后再翻转
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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) return true;
        ListNode *first = getfirst(head);
        ListNode *second = reverselist(first->next);

        bool result = true;
        ListNode *l1 = head;
        ListNode *l2 = second;
        while(result && l2 != nullptr){
            if(l1->val != l2->val){
                result = false;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        first->next = reverselist(second);
        return result;
    }

    ListNode *getfirst(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *reverselist(ListNode *head){
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while(cur != nullptr){
            ListNode *node = cur->next;
            cur->next = pre;
            pre = cur;
            cur = node;
        }
        return pre;
    }
};
