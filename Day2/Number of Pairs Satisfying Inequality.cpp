class Solution {
public:
    long long merge(vector<int>& nums,int diff,int l,int r)
    {
        int mid=(l+r)/2;
        int i=l,j=mid+1;
        long long count=0;
        vector<int> store;
        while(i<=mid and j<=r)
        {
            if(nums[i]<=nums[j]+diff)
                {

                count+=(r-j+1);
                i++;
                }
            else
                j++;
        }
        sort(nums.begin()+l,nums.begin()+r+1);
        return count;
    }
    long long inversion(vector<int>& nums1,int diff,int l,int r)
    {
        if(l<r)
        {
            int mid=(l+r)/2;
            long long left=inversion(nums1,diff,l,mid);
            long long right=inversion(nums1,diff,mid+1,r);
            return left+right+merge(nums1,diff,l,r);
        }
        return 0;
        
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        for(int i=0;i<nums1.size();i++)
        {
            nums1[i]-=nums2[i];
        }
        return inversion(nums1,diff,0,nums1.size()-1);
    }
};
