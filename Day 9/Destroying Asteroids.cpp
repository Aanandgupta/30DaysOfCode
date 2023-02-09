class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& as) {
        sort(as.begin(),as.end());
        int maxi=*max_element(as.begin(),as.end());
        for(int i:as)
        {
            if(mass>=maxi)
            return true;
            if(mass<i)
            return false;
            mass+=i;
        }
        return true;
    }
};