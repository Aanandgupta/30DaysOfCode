class Solution {
public:
    
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<vector<string>> store(transactions.size());
        for(int i=0;i<transactions.size();i++)
        {
            stringstream check1(transactions[i]);
            string intermediate;
            while(getline(check1, intermediate, ','))
            {
                store[i].push_back(intermediate);
            }
        }

        vector<int> valid(transactions.size(),0);
        for(int i=0;i<transactions.size();i++)
        {
            if(stoi(store[i][2])>1000)
                valid[i]=-1;
            for(int j=i+1;j<transactions.size();j++)
            {
                if(store[i][0]==store[j][0] and 
                  abs(stoi(store[i][1])-stoi(store[j][1]))<=60
                    and
                    store[i][3]!=store[j][3])
                    {
                        valid[j]=-1;
                        valid[i]=-1;
                    }
            }
        }
        vector<string> ans;
        for(int i=0;i<transactions.size();i++)
        {
            if(valid[i]==-1)
                ans.push_back(transactions[i]);
        }

        return ans;
    }
};