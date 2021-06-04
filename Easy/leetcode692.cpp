/* 给一非空的单词列表，返回前 k 个出现次数最多的单词。返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。*/
/* 看的答案，思路首先是使用unordered_map也就是哈希表保存每个字符出现的次数，从这里可以看出，保存出现的次数可以使用哈希表*/
/* 因为unorder_map不能排序，所以需要使用vector数组将它们存储起来，然后再使用sort排序，这里需要注意的一点是，vector中的数据类型是pair结合而成，同时sort排序的第三个参数也需要我们使用伪函数自己构造*/
/* 排序完后，我们再创建一个vector用来存放前K个出现次数最多的单词，其实就是将排序完的数组按顺序访问前K个即可*/
struct Cmp{ //这里伪函数的构造方法要会，伪函数通常也是使用在stl的算法中
        bool operator()(const pair<string, int>& p1, const pair<string, int>&p2){ //注意pair后面使用的是尖括号
            if(p1.second!=p2.second){
                return p1.second > p2.second;
            }
            else{
                return p1.first < p2.first;
            }
        }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wordsfreq;
        for(string& str : words){ //要知道数据结构的遍历方法
            wordsfreq[str]++; //unordered_map默认初始值为0，应该是可以直接++的
        }
        vector<pair<string, int>> sort_list(wordsfreq.begin(), wordsfreq.end());  //关于数组的初始化方式
        sort(begin(sort_list), end(sort_list), Cmp());  //排序
        vector<string> result;
        for(int i = 0; i < k; i++){
            result.push_back(sort_list[i].first);
        }
        return result;
    }
};
//下面是官方解法，实际上思路和上面是一样的，不过上面的代码比较看得懂
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> q;
        for(string word : words){
            q[word]++;
        }
        vector<string> res;
        for(auto &[key, value] : q){
            res.emplace_back(key);
        }
        sort(res.begin(), res.end(), [&](const string &a, const string &b)->bool{
            return q[a] == q[b] ? a < b : q[a] > q[b];
        });
        res.erase(res.begin()+k, res.end());
        return res;

    }
};

//方法二：优先队列
//思路：首先同样也是记录每个单词出现的频率，然后将其放入优先队列，优先级根据先频率后大小决定
//优先队列的大小就设置成k个，且优先队列设置成小顶堆，当个数超了就弹出队首元素
//最后剩下的k个元素就是前k个高频词汇
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> frequceny;
        for(auto &word : words){
            frequceny[word]++;
        }
                
        //这里确实没想到，没看错应该就是lambda表达式，但是这里将他赋值给了一个变量
        auto cmp = [](const pair<string, int> &a, const pair<string, int> &b){
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        };
        //同时初始化队列竟然还要这个变量
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> q(cmp);
        //unordered_map里面的元素竟然就是pair组成的
        for(auto &it : frequceny){
            q.push(it);
            if(q.size() > k){
                q.pop();
            }
        }
        
        vector<string> ret(k);
        for(int i = k - 1; i >= 0; i--){
            ret[i] = q.top().first;
            q.pop();
        }
        return ret;
    }
};
