class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans=0;
        priority_queue<int> store;
        for(int i:gifts)
            store.push(i);
        while(k)
        {
            int x=store.top();
            store.pop();
            store.push(sqrt(x));
            k--;
        }
        while(!store.empty())
        {
            ans+=store.top();
            store.pop();
        }
        return ans;
    }
};