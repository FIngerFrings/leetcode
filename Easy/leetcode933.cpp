/*写一个 RecentCounter 类来计算特定时间范围内最近的请求。
*请你实现 RecentCounter 类：
*RecentCounter() 初始化计数器，请求数为 0 。
*int ping(int t) 在时间 t 添加一个新请求，其中 t 表示以毫秒为单位的某个时间，并返回过去 3000 毫秒内发生的所有请求数（包括新请求）。确切地说，返回在 [t-3000, t] 内发生的请求数。
*保证 每次对 ping 的调用都使用比之前更大的 t 值。
*/
//答案
//使用了队列的概念，这里就是先定义一个队列，每次运行ping的时候就将当前时间t压入队列中，之后使用while循环不断地将队列中与t相差3000多地时间弹出，之后返回队列长度即可
class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);
        while(q.front() < t - 3000) q.pop();
        return q.size();
    }
private:
    queue<int> q;
};

//总结：对于这种先进先出的题目就要想到用队列来实现
