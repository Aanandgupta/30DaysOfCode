class Solution {
public:
    int maximizeWin(vector<int>& p, int k) {
        int res=0,j=0;
        vector<int> dp(p.size()+1);
        for(int i=0;i<p.size();i++)
        {
            while(p[i]-p[j]>k)
                j++;
            dp[i+1]=max(dp[i],i-j+1);
            res=max(res,i-j+1+dp[j]);
        }
        return res;
    }
};