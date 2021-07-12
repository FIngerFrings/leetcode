/*
 * 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
 * push(x) —— 将元素 x 推入栈中。
 * pop() —— 删除栈顶的元素。
 * top()  —— 获取栈顶元素。
 * getMin() —— 检索栈中的最小元素。
 */
//方法一：辅助栈
//思路：用一个辅助栈来保存每次入栈时的最小元素
class MinStack {
public:
    stack<int> x_stk;
    stack<int> min_stk;
    /** initialize your data structure here. */
    MinStack() {
        min_stk.push(INT_MAX);
    }
    
    void push(int val) {
        x_stk.push(val);
        min_stk.push(min(min_stk.top(), val));
    }
    
    void pop() {
        x_stk.pop();
        min_stk.pop();
    }
    
    int top() {
        return x_stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
