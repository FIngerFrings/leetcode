/*设计实现双端队列。
 *你的实现需要支持以下操作：
 *MyCircularDeque(k)：构造函数,双端队列的大小为k。
 *insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true。
 *insertLast()：将一个元素添加到双端队列尾部。如果操作成功返回 true。
 *deleteFront()：从双端队列头部删除一个元素。 如果操作成功返回 true。
 *deleteLast()：从双端队列尾部删除一个元素。如果操作成功返回 true。
 *getFront()：从双端队列头部获得一个元素。如果双端队列为空，返回 -1。
 *getRear()：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1。
 *isEmpty()：检查双端队列是否为空。
 *isFull()：检查双端队列是否满了。
*/
//该方法类似于622设计循环队列
class MyCircularDeque {
public:
    int n;
    int *buf;
    int *head;
    int *tail;
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        n = k;
        head = nullptr;
        tail = nullptr;
        buf = new int[k];
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isEmpty()){
            buf[0] = value;
            head = buf;
            tail = buf;
            return true;
        }
        else{
            if(isFull()){
                return false;
            }
            else{
                if(head == &buf[0]){
                    head = &buf[n-1];
                }
                else{
                    head--;
                }
                *head = value;
                return true;
            }
        }
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isEmpty()){
            buf[0] = value;
            head = buf;
            tail = buf;
            return true;
        }
        else{
            if(isFull()){
                return false;
            }
            else{
                if(tail==&buf[n-1]){
                    tail = &buf[0];
                }
                else{
                    tail++;
                }
                *tail = value;
                return true;
            }
        }
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }else{
            if(head == tail){
                head = nullptr;
                tail = nullptr;
            }else{
                if(head == &buf[n-1]){
                    head = &buf[0];
                }else{
                    head++;
                }
            }
            return true;
        }
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        else{
            if(head == tail){
                head = nullptr;
                tail = nullptr;
            }
            else{
                if(tail == buf){
                    tail = &buf[n-1];
                }
                else{
                    tail--;
                }
            }
            return true;
        }
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return isEmpty() ? -1 : *head;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return isEmpty() ? -1 : *tail;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return head == nullptr;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return isEmpty() ? false : ((tail > head) ? (tail - head == n - 1) : ((head - tail) == 1));
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
