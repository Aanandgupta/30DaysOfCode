class Solution {
public:
    vector<vector<int>> ans;
    void helper(int k,int n,int last,vector<int> cur)
    {
        if(k==0)
        {
            if(n==0)
                ans.push_back(cur);
            return;
        }
        if(last+1>n)
            return;
        for(int i=last+1;i<=n and i<=9;i++)
        {
            if(n-i<last and n-i!=0)
                continue;
            cur.push_back(i);
            helper(k-1,n-i,i,cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        helper(k,n,0,temp);
        return ans;
    }
};