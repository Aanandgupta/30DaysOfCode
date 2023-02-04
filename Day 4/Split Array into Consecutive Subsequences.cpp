class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map <int,int> cnt,last;
        for(int i:nums)
        {
            cnt[i]++;
        }
        for(int i:nums)
        {
            if(cnt[i]==0)
                continue;
            cnt[i]--;
            if(last[i-1]>0)
            {
                last[i-1]--;
                last[i]++;
            }
            else if(cnt[i+1] and cnt[i+2])
            {
                last[i+2]++;
                cnt[i+1]--;
                cnt[i+2]--;
            }
            else
                return false;
        }
        return true;
    }
};
