/*
 *不使用任何内建的哈希表库设计一个哈希集合（HashSet）。
 *实现 MyHashSet 类：
 *void add(key) 向哈希集合中插入值 key 。
 *bool contains(key) 返回哈希集合中是否存在这个值 key 。
 *void remove(key) 将给定值 key 从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
 */

//答案，这题中是创建了一个vector容器，同时容器中每个值为一个链表，之后还要创建一个hash函数。由于我们使用整数除法作为哈希函数，为了尽可能避免冲突，应当将base 取为一个质数。
//这里的hash函数就是取余
class MyHashSet {
private:
    vector<list<int>> data; //要注意同期链表的定义方法
    static const int base = 769;
    static int hash(int key){
        return key % base;
    }
public:

    /** Initialize your data structure here. */
    MyHashSet() : data(base){ //注意这里的初始化，可以改成如下形式
        data.resize(base);
    }
    
    void add(int key) {
        int h = hash(key);
        for(auto it = data[h].begin(); it != data[h].end(); it++){  //auto在声明变量的时候可根据变量初始值的数据类型自动为该变量选择与之匹配的数据类型
            if((*it) == key){
                return;
            }
        }
        data[h].push_back(key);
    }
    
    void remove(int key) {
        int h = hash(key);
        for(auto it = data[h].begin(); it != data[h].end(); it++){
            if((*it) == key){
                data[h].erase(it);
                return;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int h = hash(key);
        for(auto it = data[h].begin(); it != data[h].end(); it++){
            if((*it) == key){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
