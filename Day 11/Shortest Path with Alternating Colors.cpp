class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> distance(n,-1);
        vector<vector<pair<int,int>>> g(n);
        for(vector<int> i:redEdges)
        {
            g[i[0]].push_back({i[1],0});
        }
        for(vector<int> i:blueEdges)
        {
            g[i[0]].push_back({i[1],1});
        }

        queue<vector<int>> store;
        store.push({0,0,0});
        store.push({0,1,0});
        distance[0]=0;
        while(!store.empty())
        {
            vector<int> top=store.front();
            store.pop();
            for(pair<int,int> &i:g[top[0]])
            {
                if(i.second!=-1)
                {
                    if(i.second==1-top[1])
                    {
                        if(distance[i.first]==-1)
                        distance[i.first]=top[2]+1;
                        store.push({i.first,i.second,top[2]+1});
                        i.second=-1;
                    }
                }
            }
        }

        return distance;
    }
};
