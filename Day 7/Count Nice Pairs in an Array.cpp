class Solution {
public:
    int rev(int i)
    {
        string s=to_string(i);
        reverse(s.begin(),s.end());
        return stoi(s);
    }
    int countNicePairs(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            nums[i]-=rev(nums[i]);
        }
        int ans=0;
        unordered_map<int,int> store;
        for(int i:nums)
        {
            ans=(ans+store[i])%(1000000007);
            store[i]++;
        }
        return ans;
    }
};