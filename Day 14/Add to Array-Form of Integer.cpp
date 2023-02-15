class Solution {
public:
    string helper(vector<int>& num, int k,int i,int add)
    {
        if(i==-1)
        {
            if(k+add==0)
            return "";
            string s=to_string(k+add);
            return s;

        } 
        int x=0;
        if(k!=0)
            x=k%10;
        int t=num[i]+x+add;
        return helper(num,k/10,i-1,t/10)+(to_string(t%10));

    }
    vector<int> addToArrayForm(vector<int>& num, int k) {
       string s=helper(num,k,num.size()-1,0);
       vector<int> ans;
       for(char i:s)
        ans.push_back(i-'0');
       return ans;
    }
};