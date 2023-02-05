class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int,int> freq1,freq2;
        int swap=0;
        int extra=0;
        for(int i:basket1)
            freq1[i]++;
        for(int i:basket2)
            freq1[i]--;
        for(auto it:freq1)
        {
           if(it.second%2)
            return -1;

            swap+=max(0,it.second)/2;
        }
        long long ans=0;
        for(auto it:freq1)
        {
            int take=abs(it.second)/2;
            take=min(take,swap);
            long long temp=min(it.first,freq1.begin()->first*2);
            ans+=temp*take;
            swap-=take;
            if(swap==0)
                return ans;
        }
        return ans;
    }
};