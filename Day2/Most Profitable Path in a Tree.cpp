class Solution {
public:
    vector<int> path;
    bool dfs(vector<vector<int>> &store,int i,int bob,vector<bool> &visited)
    {
        visited[i]=true;
        path.push_back(i);
        if(i==bob)
            return true;
        for(int j:store[i])
        {
            if(!visited[j] and dfs(store,j,bob,visited))
                return true;
        }
        path.pop_back();
        return false;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        
        
        vector<vector<int>> store(amount.size());
        
        for(vector<int> i:edges)
        {
            store[i[0]].push_back(i[1]);
            store[i[1]].push_back(i[0]);
        }
        vector<bool> visited(amount.size(),false);
        dfs(store,0,bob,visited);
        // for(int i:path)
        //     cout<<i<<endl;
        reverse(path.begin(),path.end());
        int i=0;
        float ans=INT_MIN;
        queue<pair<int,float>> trav;
        trav.push({0,amount[0]});
        amount[0]=0;
        amount[bob]=0;
        i++;
         vector<bool> visited1(amount.size(),false);
        visited1[0]=true;
        unordered_map<int,int> check;
        for(int i=0;i<path.size();i++)
        {
            check[path[i]]=i;
        }
        while(!trav.empty())
        {
            int x=trav.size();
            while(x)
            {
                pair<int,float> temp=trav.front();
                trav.pop();
                int flag=1,flag2=1;
                for(int it:store[temp.first])
                {
                    
                    if(!visited1[it])
                    {
                        flag=0;
                        visited1[it]=true;
                        if(check.find(it)==check.end() or check[it]>i)
                        {
                            trav.push({it,amount[it]+temp.second});
                        }
                        else
                        {
                            if(check[it]==i)
                                trav.push({it,amount[it]/2+temp.second});
                            else
                            trav.push({it,temp.second});
                        }
                    }
                    
                }
                if(flag)
                    ans=max(ans,temp.second);
             
                x--;
            }
            i++;
            
        }
        return ans;
    }
};
