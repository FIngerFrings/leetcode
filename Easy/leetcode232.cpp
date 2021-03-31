/*
 *请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
 *实现 MyQueue 类：
 *void push(int x) 将元素 x 推到队列的末尾
 *int pop() 从队列的开头移除并返回元素
 *int peek() 返回队列开头的元素
 *boolean empty() 如果队列为空，返回 true ；否则，返回 false
*/
//方法一，该方法使用两个栈，原理和用两个队列实现栈（leetcode225）相似
//主要是在压入的时候要注意，将stk1作为输出的栈，而stk2作为辅助栈
//压入时，将stk1中的元素按顺序压入stk2，之后将输入的元素压入stk1中，之后再将stk2中的元素再依次压入stk1
class MyQueue {
public:
    stack<int> stk1;
    stack<int> stk2;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!stk1.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }
        stk2.push(x);
        while(!stk2.empty()){
            stk1.push(stk2.top());
            stk2.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int n = stk1.top();
        stk1.pop();
        return n;
    }
    
    /** Get the front element. */
    int peek() {
        return stk1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
