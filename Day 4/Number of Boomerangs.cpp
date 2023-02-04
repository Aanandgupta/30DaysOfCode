class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        
        int count=0;
        for(int i=0;i<points.size();i++)
        {
            unordered_map<long long,int> store;
            for(int j=0;j<points.size();j++)
            {
                
                if(j==i)
                continue;
                long long x=points[j][1]-points[i][1];
                long long y=points[j][0]-points[i][0];
                count+=store[x*x+y*y]*2;
                store[x*x+y*y]++;
            }
            
        }
       
        return count;

    }
};
