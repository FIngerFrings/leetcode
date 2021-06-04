/* 
 * 给定一个列表 accounts，每个元素 accounts[i] 是一个字符串列表，其中第一个元素 accounts[i][0] 是  名称 (name)，其余元素是 emails 表示该账户的邮箱地址。
 * 现在，我们想合并这些账户。如果两个账户都有一些共同的邮箱地址，则两个账户必定属于同一个人。请注意，即使两个账户具有相同的名称，它们也可能属于不同的人，因为人们可能具有相同的名称。一个人最初可以拥有任意数量的账户，但其所有账户都具有相同的名称。
 * 合并账户后，按以下格式返回账户：每个账户的第一个元素是名称，其余元素是按字符 ASCII 顺序排列的邮箱地址。账户本身可以以任意顺序返回。
 */
//方法一：并查集和哈希表
//思路：使用并查集分类，首先使用哈希表email2index将所有不同的邮箱进行编号，同时使用email2name保存所有邮箱对应的账户名称
//之后创建并查集，将属于同一用户的邮箱分到一个集合中，这里实际上只要遍历所有账户，然后把同一个账户中的邮箱分为1组，就可以将所有属于同一个人的邮箱分到一组
//因为假如将一个账户中的邮箱分到一组，另外一个账户如果有相同邮箱，则都会被分到同一个集合中，这是因为相同邮箱的编号是相同的
//使用并查集分完组后，就是可以使用index2email哈希表将所有根结点相同的邮箱放到一起
//之后根据index2email就可以将结果输出
class UnionFind {
public:
    vector<int> parent;

    UnionFind(int n) {
        parent.resize(n);     //数组这样的初始化方式要记住
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    //这里并没有压缩路径
    void unionSet(int index1, int index2) {
        parent[find(index2)] = find(index1);
    }

    int find(int index) {
        if (parent[index] != index) {
            parent[index] = find(parent[index]);
        }
        return parent[index];
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int> emailToIndex;
        map<string, string> emailToName;
        int emailsCount = 0;
        for (auto& account : accounts) {
            string& name = account[0];
            int size = account.size();
            for (int i = 1; i < size; i++) {
                string& email = account[i];
                if (!emailToIndex.count(email)) {
                    emailToIndex[email] = emailsCount++;
                    emailToName[email] = name;
                }
            }
        }
        UnionFind uf(emailsCount);
        for (auto& account : accounts) {
            string& firstEmail = account[1];
            int firstIndex = emailToIndex[firstEmail];
            int size = account.size();
            for (int i = 2; i < size; i++) {
                string& nextEmail = account[i];
                int nextIndex = emailToIndex[nextEmail];
                uf.unionSet(firstIndex, nextIndex);
            }
        }
        //这里首先将数组取出来，然后将新的邮箱放进去，然后再将放完后的数组放回去，也就是更新旧的邮箱
        map<int, vector<string>> indexToEmails;
        for (auto& [email, _] : emailToIndex) {
            int index = uf.find(emailToIndex[email]);
            vector<string>& account = indexToEmails[index];
            account.emplace_back(email);
            indexToEmails[index] = account;
        }
        vector<vector<string>> merged;
        for (auto& [_, emails] : indexToEmails) {
            sort(emails.begin(), emails.end());
            string& name = emailToName[emails[0]];
            vector<string> account;
            account.emplace_back(name);
            for (auto& email : emails) {
                account.emplace_back(email);
            }
            merged.emplace_back(account);
        }
        return merged;
    }
};
