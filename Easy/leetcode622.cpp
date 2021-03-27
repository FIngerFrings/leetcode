/*
 *设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。
 *循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。
 *你的实现应该支持如下操作：
 *MyCircularQueue(k): 构造器，设置队列长度为 k 。
 *Front: 从队首获取元素。如果队列为空，返回 -1 。
 *Rear: 获取队尾元素。如果队列为空，返回 -1 。
 *enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
 *deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
 *isEmpty(): 检查循环队列是否为空。
 *isFull(): 检查循环队列是否已满。
*/
//该方法通过数组构造循环队列，中规中矩
class MyCircularQueue {
public:
    int n;
    int *buf;
    int *head;
    int *tail;
    MyCircularQueue(int k) {
        n = k;
        head = nullptr;
        tail = nullptr;
        buf = new int[k];
    }
    
    bool enQueue(int value) {
        if(isEmpty()){
            buf[0] = value;
            head = &buf[0];
            tail = &buf[0];
            return true;
        }
        else{
            if(isFull()){
                return false;
            }else{
                if(tail == &buf[n-1]){
                    tail = &buf[0];
                    *tail = value;
                    return true;
                }
                else{
                    tail++;
                    *tail = value;
                    return true;
                }
            }
        }
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }else{
            if(head == tail){
                head = nullptr;
                tail = nullptr;
                return true;
            }
            else{
                if(head == &buf[n-1]){
                    head = &buf[0];
                }else{
                    head++;
                }
                return true;
            }
        }
    }
    
    int Front() {
        return isEmpty() ? -1 : *head;
    }
    
    int Rear() {
        return isEmpty() ? -1 : *tail;
    }
    
    bool isEmpty() {
        return head == nullptr;
    }
    
    bool isFull() {
        return isEmpty() ? false : ((tail > head) ? (tail - head == n - 1) : (tail + 1 == head));
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
