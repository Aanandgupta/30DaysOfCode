class Solution {
public:
    bool vow(char i)
    {
        string s="aeiou";
        for(char j:s)
        {
            if(j==i)
                return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> freq(words.size(),0),ans(queries.size(),0);
        
        for(int i=0;i<words.size();i++)
        {
            freq[i]=freq[max(0,i-1)];
            if( vow(words[i][0])and vow(words[i][words[i].size()-1]))
            {
                freq[i]++;
            }
        }
        for(int i=0;i<queries.size();i++)
        {
            if(queries[i][0]==0)
                ans[i]=freq[queries[i][1]];
            else
                ans[i]=freq[queries[i][1]]-freq[queries[i][0]-1];
        }
        return ans;
    }
};