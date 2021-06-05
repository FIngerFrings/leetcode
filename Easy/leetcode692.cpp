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


//方法三：前缀树
//思路：使用前缀树代替上面的map，不过会出错，我觉得整个逻辑是没问题的，但是不知道问题在哪（最后发现问题出在没有对vector<string> ans初始化）
class Trie{
public:
    vector<Trie *> children;
    bool isEnd;
    pair<int, string> show;
    Trie():children(26){
        //children.resize(26);
        isEnd = false;
        show.first = 0;
    }

    void insert(string word){
        Trie *node = this;
        for(char str : word){
            if(node->children[str - 'a'] == nullptr){
                node->children[str - 'a'] = new Trie;
            }
            node = node->children[str - 'a'];
        }
        node->isEnd = true;
        node->show.first++;
        node->show.second = word;
    }
};
class Solution {
public:
    struct cmp{
        bool operator() (const pair<int, string> &a, const pair<int, string> &b){
            return a.first == b.first ? a.second < b.second : a.first > b.first;   
        }
    };

    priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> q;
    vector<string> topKFrequent(vector<string>& words, int k) {
        Trie *root = new Trie;
        for(string word : words){
            root->insert(word);
        }
        
        dfs(root, k);
        vector<string> ans(k);          //这里忘记加上(k)了
        for(int i = k - 1; i >= 0; i--){
            ans[i] = q.top().second;
            q.pop();
        }
        return ans;
    }

    void dfs(Trie *root, int k){
        if(root == nullptr) return;
        if(root->isEnd){
            q.push(root->show);
            if(q.size() > k){
                q.pop();
            }
        }
        for(int i = 0; i < 26; i++){
            if(root->children[i]!=nullptr){
                dfs(root->children[i], k);
            }
        }
    }
};

//别人写的前缀树方法
struct TrieNode{
    bool  isEnd;
    TrieNode* branch[26];
    //int times;
    //string s;
    pair<int,string> show ;//存储字符串和出现次数
    TrieNode():isEnd(false ){
        show.first=0;
        for(int i=0;i<26; i++){
             branch[i]=nullptr;
        }
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        root=new TrieNode();
        for(auto it:words){
            insert(it);//建立字典树
        }
        K=k;
        vector<string> res(k);
        dfs(root);
        for(int i=0; i<k; i++){//从堆中取数据
            res[i]=p.top().second;
            p.pop();
        }
        reverse(res.begin(),res.end()); //逆置
        return res;
    }
     void insert(string &word){//构建字典树
        TrieNode* node=root;

        for(auto it:word){
            if(node->branch[it-'a']==nullptr){
                node->branch[it-'a']=new TrieNode();
            }
            node=node->branch[it-'a'];
        }
        node->isEnd=true;
        node->show.first++;
        node->show.second=word;
    }

    void dfs(TrieNode* root){
        if(root==nullptr) return;
        if(root->isEnd){//建立堆
            p.push(root->show);
            if(p.size()>K){
                p.pop();
            }
        }  
        for(int i=0; i<26; i++){//深搜
            if(root->branch[i]!=nullptr){
                dfs(root->branch[i]);
            }
        } 
    }

    struct comp{
        bool operator()(pair<int,string> a, pair<int,string> b){
            if(a.first>b.first) return true;//自己写的比较函数
            if(a.first<b.first) return false;
            if(a.second>=b.second) return false;
            return true;
        }
    };
private:
    TrieNode* root;
    int K;
    priority_queue<pair<int,string>,vector<pair<int,string>>,  comp> p;
};
