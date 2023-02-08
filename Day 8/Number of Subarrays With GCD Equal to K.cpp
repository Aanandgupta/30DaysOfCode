class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        unordered_map<int,int> store;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            unordered_map<int,int> store1;
            if(nums[i]%k==0)
            {
                store[nums[i]]++;
                for(auto it:store)
                    store1[gcd(nums[i],it.first)]+=it.second;
            }
            count+=store1[k];
            swap(store,store1);
        }
        return count;
    }
};