/*
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 */
//方法一：顺序合并
//思路：对于合并多个链表，首先需要知道怎么合并两个链表
//然后再依次将多个链表合并
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
    ListNode *mergeLists(ListNode *a, ListNode *b){
        if(a == nullptr || b == nullptr)    return a == nullptr ? b : a;
        ListNode *head = new ListNode();
        ListNode *tail = head;
        while(a != nullptr && b != nullptr){
            if(a->val < b->val){
                tail->next = a;
                a = a->next;
            }
            else{
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = (a == nullptr) ? b : a;
        return head->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans = nullptr;
        for(int i = 0; i < lists.size(); i++){
            ans = mergeLists(ans, lists[i]);
        }
        return ans;
    }
};

//方法二：分治合并
//思路：实际上就是分治的思想，将问题分成多个多个小问题，最后分成合并两个链表的问题
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
    ListNode *mergeLists(ListNode *a, ListNode *b){
        if(a == nullptr || b == nullptr)    return a == nullptr ? b : a;
        ListNode *head = new ListNode();
        ListNode *tail = head;
        while(a != nullptr && b != nullptr){
            if(a->val < b->val){
                tail->next = a;
                a = a->next;
            }
            else{
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = (a == nullptr) ? b : a;
        return head->next;
    }

    ListNode *merge(vector<ListNode*>& lists, int l, int r){
        if(l == r)  return lists[l];
        if(l > r)   return nullptr;
        int mid = (l + r) / 2;
        return mergeLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};

//方法三：优先队列
//思路：先将k个链表的k个头节点放进优先队列，然后取出优先队列队首的节点
//将其加入最后返回的链表中，然后将其下一个节点放进优先队列中
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
    struct Status{
        int val;
        ListNode *ptr;
        bool operator < (const Status &a) const{
            return val > a.val;
        }
    };

    priority_queue<Status> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(auto node : lists){
            if(node != nullptr){
                q.push({node->val, node});
            }
        }

        ListNode *head = new ListNode();
        ListNode *ptr = head;
        while(!q.empty()){
            auto node = q.top();
            q.pop();
            ptr->next = node.ptr;
            ptr = ptr->next;
            if(node.ptr->next != nullptr)   q.push({node.ptr->next->val, node.ptr->next});
        }
        return head->next;
    }
};
