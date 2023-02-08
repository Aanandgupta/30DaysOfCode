class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> store;
        store[0]=1;
        int curSum=0,count=0,prefix=0;
        for(int i:nums)
        {
          prefix=(prefix+i%k+k)%k;
          count+=store[prefix]++;
        }
        return count;
    }
};