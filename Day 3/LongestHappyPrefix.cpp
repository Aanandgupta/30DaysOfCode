class Solution {
public:
    string longestPrefix(string s) {
        vector<int> pi(s.size(),0);
        for(int i=1;i<s.size();i++)
        {
            int j=pi[i-1];
            while(j>0 and s[i]!=s[j])
                j=pi[j-1];
            if(s[i]==s[j])
                j++;
            pi[i]=j;
        }
        return s.substr(0,pi[s.size()-1]);
    }
};