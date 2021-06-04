/* 
 * Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。
 * 请你实现 Trie 类：
 * Trie() 初始化前缀树对象。
 * void insert(String word) 向前缀树中插入字符串 word 。
 * boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
 * boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。
 */

class Trie {
public:
    vector<Trie *> children;
    bool isEnd;
    /** Initialize your data structure here. */
    Trie() {
        children.resize(26);
        isEnd = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node = this;
        for(char str : word){
            if(node->children[str - 'a'] == nullptr){
                node->children[str - 'a'] = new Trie;
            }
            node = node->children[str - 'a'];
        }
        node->isEnd = true;
    }

    Trie *searchprefix(string prefix){
        Trie *node = this;
        for(char str : prefix){
            if(node->children[str - 'a'] == nullptr){
                return nullptr;
            }
            node = node->children[str - 'a'];
        }
        return node;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node = searchprefix(word);
        return (node == nullptr) ? false : node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *node = searchprefix(prefix);
        return node != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

//上面的方法是额外定义了一个函数searchprefix，下面的方式是没有searchprefix函数的
class Trie {
public:
    vector<Trie *> children;
    bool isEnd;
    /** Initialize your data structure here. */
    Trie() {
        children.resize(26);
        isEnd = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node = this;
        for(char str : word){
            if(node->children[str - 'a'] == nullptr){
                node->children[str - 'a'] = new Trie;
            }
            node = node->children[str - 'a'];
        }
        node->isEnd = true;
    }

    // Trie *searchprefix(string prefix){
    //     Trie *node = this;
    //     for(char str : prefix){
    //         if(node->children[str - 'a'] == nullptr){
    //             return nullptr;
    //         }
    //         node = node->children[str - 'a'];
    //     }
    //     return node;
    // }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node = this;
        for(char str : word){
            if(node->children[str - 'a'] == nullptr){
                return false;
            }
            node = node->children[str - 'a'];
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *node = this;
        for(char str : prefix){
            if(node->children[str - 'a'] == nullptr){
                return false;
            }
            node = node->children[str - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
