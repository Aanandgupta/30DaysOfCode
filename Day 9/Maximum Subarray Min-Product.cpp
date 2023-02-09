class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        vector<int> nextGreater(nums.size(),-1),
        left(nums.size(),-1);
        vector<long long> pre(nums.size(),0);
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            pre[i]=(nums[i]+pre[i-1]);
        }
        stack<int> ng,lg;
        for(int i=0;i<nums.size();i++)
        {
            while(!ng.empty() and nums[i]<nums[ng.top()])
            {
                nextGreater[ng.top()]=i;
                ng.pop();
            }
            ng.push(i);
        }
        while(!ng.empty())
            ng.pop();
      
  
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!ng.empty() and nums[i]<=nums[ng.top()])
            {
                left[ng.top()]=i;
                ng.pop();
            }
            ng.push(i);
        }
        long long ans1=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            long long add=pre[nums.size()-1];
            long long minus=0;
            if(nextGreater[i]!=-1)
            {
                add=pre[nextGreater[i]-1];
            }
            if(left[i]!=-1)
            {
                minus=pre[left[i]];
            }
            long long temp1=((add-minus)*nums[i]);
            
            if(temp1>ans1)
            ans1=temp1;
        }
        return ans1%1000000007;
    }
};
