/*
 * 给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi] 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。
 * 所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。
 * 例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前。
 * 假定所有机票至少存在一种合理的行程。且所有的机票 必须都用一次 且 只能用一次。
 */
//方法一：回溯
//思路：其实这道题是希望你根据给定的机票，写出由这些机票所组成的行程路线
//通过unordered_map构造机票里面出发地所能到达的目的地。然后根据回溯法。。。
//不知道怎么说下去了，自己意会
class Solution {
    vector<string> ans;
    unordered_map<string, map<string, int>> targets;

    bool backtracking(int num){
        if(ans.size() == num + 1){
            return true;
        }

        for(pair<const string, int>& tmp : targets[ans.back()]){
            if(tmp.second > 0){
                tmp.second--;
                ans.push_back(tmp.first);
                if(backtracking(num))   return true;
                tmp.second++;
                ans.pop_back();
            }
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        ans.clear();
        for(const vector<string>& ticket : tickets){
            targets[ticket[0]][ticket[1]]++;
        }
        ans.push_back("JFK");
        backtracking(tickets.size());
        return ans;
    }
};
