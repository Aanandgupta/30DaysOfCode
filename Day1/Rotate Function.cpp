class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int total=0,prev,maxi=0,add,sub;
        for(int i:nums)
            total+=i;
        for(int i=0;i<nums.size();i++)
        {
            maxi+=(i*nums[i]);
        } 
        prev=maxi;
        for(int i=1;i<nums.size();i++)
        {
            total-=nums[nums.size()-i];
            prev=prev+(total)-(nums.size()-1)*nums[nums.size()-i];
            maxi=max(maxi,prev);
            total+=nums[nums.size()-i];
        }
        return maxi;
    }
};