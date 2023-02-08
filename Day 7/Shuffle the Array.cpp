class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i=n-1;
        for(int j=2*n-1;j>=n;j--)
        {
            nums[j]=nums[j]<<10;
            nums[j]+=nums[i--];
        }
        i=0;
        for(int j=n;j<=2*n-1;j++)
        {
            nums[i++]=nums[j]&1023;
            nums[i++]=nums[j]>>10;
        }
        return nums;
    }
};