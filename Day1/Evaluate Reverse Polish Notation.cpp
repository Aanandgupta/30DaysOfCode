class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int last=1;
        for(int i=2;i<tokens.size();i++)
        {
            if(tokens[i]=="+")
            {
                tokens[--last]=to_string(stoi(tokens[last])+stoi(tokens[last-1]));
                
            }
            else if (tokens[i]=="*")
                tokens[--last]=to_string(stoi(tokens[last])*stoi(tokens[last-1]));
            else if(tokens[i]=="/")
                tokens[--last]=to_string(stoi(tokens[last-1])/stoi(tokens[last]));
            else if(tokens[i]=="-")
                tokens[--last]=to_string(stoi(tokens[last-1])-stoi(tokens[last]));
            else
                tokens[++last]=tokens[i];
        }
        return stoi(tokens[0]);
    }
};