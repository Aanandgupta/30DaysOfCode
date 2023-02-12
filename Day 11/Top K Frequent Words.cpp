class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> store;
        vector<pair<int,string>> store1;
        int count=0;
        for(string i:words)
        {
            store[i]--;
            count=max(count,store[i]);
        }
        vector<string> ans;
        for(auto it:store)
        {
            store1.push_back({it.second,it.first});
        }
        sort(store1.begin(),store1.end());
        for(int i=0;i<store1.size() and i<k;i++)
        {
            ans.push_back(store1[i].second);
        }
        return ans;
    }
};
