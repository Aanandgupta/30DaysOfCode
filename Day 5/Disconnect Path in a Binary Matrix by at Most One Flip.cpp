class Solution {
public:
    bool dfs(int i,int j,vector<vector<int>>& grid)
    {
        if(i==grid.size()-1 and j==grid[0].size()-1)
            return true;
        if(i>=grid.size() or j>=grid[0].size() or grid[i][j]==0)
            return false;
        grid[i][j]=0;
        return dfs(i+1,j,grid) or dfs(i,j+1,grid);
        
    }
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        if(dfs(0,0,grid)==false)
            return true;
        grid[0][0]=1;
        return !dfs(0,0,grid);
    }
};