class Solution {
public:
    unordered_set <string> store;
    int helper(string s,int i)
    {
        if(i==s.size())
            return 0;
        int count=0,temp=INT_MIN;
        string s1="";
        for(int j=i;j<s.size();j++)
        {
            s1+=s[j];
            if(store.find(s1)==store.end())
            {
                store.insert(s1);
                temp=max(temp,1+helper(s,j+1));
                store.erase(s1);
            }
        }
        return temp;
    }
    int maxUniqueSplit(string s) {
        return helper(s,0);
    }
};
