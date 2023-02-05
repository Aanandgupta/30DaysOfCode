class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l=0,r=1e9;
        while(l<r)
        {
            int mid=(l+r)/2,count=0;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]<=mid)
                {
                    i++;
                    count++;
                }
            }
            if(count>=k)
                r=mid;
            else
                l=mid+1;
        }
        return r;
    }
};