class Solution {
public:

    struct node
    {
        int maxi=INT_MIN;
        long long total=0;
        string id="a";
    };
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string,node> store;
        long long maxi=INT_MIN;
        for(int i=0;i<views.size();i++)
        {
            if(store.find(creators[i])!=store.end())
            {
                store[creators[i]].total+=views[i];
                if(store[creators[i]].maxi<views[i])
                {
                    store[creators[i]].maxi=views[i];
                    store[creators[i]].id=ids[i];
                }
                else if(store[creators[i]].maxi==views[i]  )
                {
                    store[creators[i]].id=min(store[creators[i]].id,ids[i]);
                }
                maxi=max(maxi, store[creators[i]].total);
            }
            else
            {
                node t;
                t.maxi=views[i];
                t.total=views[i];
                t.id=ids[i];
                store[creators[i]]=t;
                maxi=max(maxi,t.total);
            }

        }
        vector<vector<string>> ans;
        for(auto it:store)
        {
            if(it.second.total==maxi)
            {
                ans.push_back({it.first,it.second.id});
            }
        }
        // cout<<maxi;
        return ans;
    }
};
