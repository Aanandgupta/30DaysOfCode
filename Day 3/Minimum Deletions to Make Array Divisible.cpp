class Solution {
public:
    bool check(int nums, vector<int>& numsDivide) 
    {
        for(int i:numsDivide)
        {
            if(i%nums!=0)
            return false;
        }
        return true;
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int j=numsDivide[0];
        for(int i:numsDivide)
        {
            j=gcd(j,i);
        }
        sort(nums.begin(),nums.end());
        sort(numsDivide.begin(),numsDivide.end());
        // if(nums[0]>j)
        //     return -1;
        cout<<j<<" ";
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>numsDivide[0])
                return -1;
            if(j%nums[i]==0)
                return i;
            // if(nums[i]%j==0 and check(nums[i],numsDivide))
            // {
            //     return i;
            // }
        }
        return -1;
    }
};
