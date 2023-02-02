class Solution {
public:
    vector<int> helper(vector<int>& nums,int i, unordered_map<int,vector<int>> &dp)
    {
        if(i==nums.size()-1)
            return {};
        if(dp.find(nums[i])!=dp.end())
            return dp[nums[i]];
        vector<int> temp,maxi;
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[j]%nums[i]==0)
            {
                temp=helper(nums,j,dp);
                if(temp.size()+1>maxi.size())
                {
                    maxi={nums[j]};
                    maxi.insert(maxi.end(),temp.begin(),temp.end());
                }
            }
        }
        return dp[nums[i]]=maxi;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,vector<int>> dp;
        // int cur=0,ans=0;
        vector<int> store,temp,maxi;
        for(int i=0;i<nums.size();i++)
        {
            temp=helper(nums,i,dp);
            if(temp.size()+1>maxi.size())
            {
                maxi={nums[i]};
                maxi.insert(maxi.end(),temp.begin(),temp.end());
            }   
        }
        return maxi;
    }
};