class Solution {
public:
    string ans="";
    int maxi=INT_MIN;
    int extra=0;
    int value(vector<int>& aliceArrows,string s)
    {
        int val=0;
        for(int i=1;i<=11;i++)
        {
            if(s[i]=='1')
                val+=i;
        }
        return val;
    }
    void helper(int i,int numArrows, vector<int>& aliceArrows,string s)
    {
        if(i==12)
        {
            int val=value(aliceArrows,s);
            if(val>maxi)
            {
                ans=s;
                maxi=val;
                extra=numArrows;
            // cout<<ans<<" "<<val<<endl;
            }
            return;
        }
        helper(i+1,numArrows,aliceArrows,s);
        s[i]='1';
        if(numArrows>=aliceArrows[i]+1)
            helper(i+1,numArrows-(aliceArrows[i]+1),aliceArrows,s);
        
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        string s="";
        for(int i=0;i<=11;i++)
            s+="0";
        helper(1,numArrows,aliceArrows,s);
        vector<int> store;
        for(int i=0;i<12;i++)
        {
            if(ans[i]=='1')
                store.push_back(aliceArrows[i]+1);
            else
                store.push_back(0);
        }
        store[0]=extra;
        return store;
    }
};