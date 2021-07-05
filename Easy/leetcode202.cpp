/*
 * 编写一个算法来判断一个数 n 是不是快乐数。
 * 「快乐数」定义为：
 * 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
 * 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
 * 如果 可以变为  1，那么这个数就是快乐数。
 * 如果 n 是快乐数就返回 true ；不是，则返回 false 。
 */
//方法一：使用哈希表
//思路：首先需要知道的一个性质就是，对于大于3位数的n，它的下一个数必定小于等于3位数，所以不用担心一直循环下去数会很大，一直循环下去必定会掉到3位数一下
//知道有上限之后就可以知道，如果不是快乐数，则一直循环下去会是一个循环，所以我们可以使用哈希表判断是否循环
class Solution {
public:
    int getnext(int n){
        int sum = 0;
        while(n){
            int d = (n % 10);
            sum += d * d;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_map<int, int> q;
        while(n != 1 && q.count(n) == 0){
            q[n] = 1;
            n = getnext(n);
        }
        return n == 1;
    }
};

//方法二：快慢指针
//思路：既然知道是循环，那么也就是一个链表，就可以使用快慢指针
class Solution {
public:
    int getnext(int n){
        int sum = 0;
        while(n){
            int d = (n % 10);
            sum += d * d;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = getnext(n);
        while(fast != 1 && slow != fast){
            slow = getnext(slow);
            fast = getnext(getnext(fast));
        }
        return fast == 1;
    }
};
