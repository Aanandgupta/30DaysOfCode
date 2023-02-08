class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> store(nums.size(),0);
        store[nums.size()-1]=nums[nums.size()-1];
        for(int j=nums.size()-2;j>=0;j--)
        {
            store[j]=max(store[j+1],nums[j]);
        }
        int mini=nums[0];
        for(int i=1;i<nums.size()-1;i++)
        {
            if(mini<nums[i] and nums[i]<store[i+1])
                return true;
            mini=min(mini,nums[i]);
        }
        return false;
    }
};