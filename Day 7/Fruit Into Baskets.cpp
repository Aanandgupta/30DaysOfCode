class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int a=-1,b=-1,ans=0,prev=0,count=0,i=0;
        while(i<fruits.size())
        {
            int j=i+1;
            while(j<fruits.size() and fruits[i]==fruits[j])
            {
                j++;
            }
            if(a==-1)
            {
                a=fruits[i];
                count=j-prev;
                prev=i;
            }
            else if(b==-1)
            {
                b=fruits[i];
                count+=j-i;
                prev=i;
            }
            else if(fruits[i]==a or fruits[i]==b)
            {
                count+=j-i;
                prev=i;
            }
            else
            {
                a=fruits[i];
                b=fruits[prev];
                count=j-prev;
                prev=i;
            }
            ans=max(count,ans);
            i=j;
        }
        return ans; 
    }
};