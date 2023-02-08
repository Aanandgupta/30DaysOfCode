


class Solution {
public:
    
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> store;
        priority_queue<int> maxi;
        for(int i=0;i<profits.size();i++)
        {
            store.push_back({capital[i],profits[i]});
        }
        sort(store.begin(),store.end());
        int j=0;
        while(k)
        {
            while(j<store.size() and store[j].first<=w)
            {
                maxi.push(store[j].second);
                j++;
            }
            if(maxi.empty())
                return w;
            w+=maxi.top();
            maxi.pop();
            k--;
        }
        return w;
    }
};