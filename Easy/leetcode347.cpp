/* 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。 */
//方法一：优先队列
//思路：首先记录每个元素出现的次数，并压入优先队列，之后弹出优先队列前k个元素即可
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] != nums[i-1]){
                q.emplace(count, nums[i-1]);
                count = 1;
            }
            else{
                ++count;
            }

            if(i == nums.size() - 1){
                q.emplace(count, nums[i]);
            }
        }
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};

//代码随想录优先队列
class Solution {
public:
    class MyComparisos{
    public:
        bool operator()(const pair<int, int> &a, const pair<int, int> &b){
            return a.second > b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for(int num : nums){
            ++hash[num];
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, MyComparisos > q;
        for(auto it = hash.begin(); it != hash.end(); it++){
            q.emplace(*it);
            if(q.size() > k)    q.pop();
        }

        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(q.top().first);
            q.pop();
        }
        return ans;
    }
};
