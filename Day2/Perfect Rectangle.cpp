class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int tl=INT_MAX,tr=INT_MIN,bl=INT_MAX,br=INT_MIN;
        long long area=0;
        unordered_set<string> store;
        for(vector<int> i:rectangles)
        {
            tl=min(tl,i[1]);
            tr=max(tr,i[3]);
            bl=min(bl,i[0]);
            br=max(br,i[2]);
            string p1=to_string(i[0])+" "+to_string(i[1]);
            if(store.find(p1)!=store.end())
                store.erase(p1);
            else
                store.insert(p1);
            p1=to_string(i[0])+" "+to_string(i[3]);
            if(store.find(p1)!=store.end())
                store.erase(p1);
            else
                store.insert(p1);
            p1=to_string(i[2])+" "+to_string(i[3]);
            if(store.find(p1)!=store.end())
                store.erase(p1);
            else
                store.insert(p1);
            p1=to_string(i[2])+" "+to_string(i[1]);
            if(store.find(p1)!=store.end())
                store.erase(p1);
            else
                store.insert(p1);
            area+=(long long)(i[3]-i[1])*(long long)(i[2]-i[0]);
            
        }
        string a=to_string(bl)+" "+to_string(tl),
        b=to_string(bl)+" "+to_string(tr),
        c=to_string(br)+" "+to_string(tl),
        d=to_string(br)+" "+to_string(tr);
        if(store.size()!=4 or store.find(a)==store.end()
        or store.find(b) ==store.end()
        or store.find(c) ==store.end()
        or store.find(d) ==store.end() )
        return false;

        return area==(long long)(tr-tl)*(long long)(br-bl);
    }
};
