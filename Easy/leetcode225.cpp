/*请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通队列的全部四种操作（push、top、pop 和 empty）。
*实现 MyStack 类：
*void push(int x) 将元素 x 压入栈顶。
*int pop() 移除并返回栈顶元素。
*int top() 返回栈顶元素。
*boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
*/ 
//方法一：双队列
class MyStack {
public:
    queue<int> q1;  //定义队列的方式
    queue<int> q2;
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int r = q1.front();
        q1.pop();   //队列的pop操作并不会返回弹出的元素
        return r;
    }
    
    /** Get the top element. */
    int top() {
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};
//方法一使用的是双队列，其中新入队的元素放在队列二中，之后将队列一中的元素全部按顺序压入队列二，这样新入队的元素就可以先出队了，实际上队列二才是主要的队列，队列一只是辅助队列
//使用这样的双队列就可以实现先进后出，即栈的功能
