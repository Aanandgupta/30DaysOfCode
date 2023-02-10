class Solution {
public:
    int helper(int startPos, int endPos, int k,vector<vector<int>> &dp)
    {
        if(k==0 and endPos==startPos)
            return 1;
        if(k==0)
            return 0;
        if(dp[k][startPos]!=-1) 
            return dp[k][startPos];
        long long a=helper(startPos+1,endPos,k-1,dp);
        long long b=helper(startPos-1,endPos,k-1,dp);
        return dp[k][startPos]=(a+b)%1000000007;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        startPos+=1000;
        endPos+=1000;
        vector<vector<int>> dp(1001,vector<int>(3001,-1));
        return helper(startPos,endPos,k,dp);
    }
};
