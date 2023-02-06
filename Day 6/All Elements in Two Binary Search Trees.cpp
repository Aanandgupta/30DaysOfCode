/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     
    void push(stack<TreeNode *> &st,TreeNode *root1)
    {
        while(root1!=NULL)
        {
            st.push(root1);
            root1=root1->left;
        }
    }

    int next(stack<TreeNode *> &st)
    {
        TreeNode * temp=st.top();
        st.pop();
        push(st,temp->right);
        return temp->val;
    }

    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode *> st1,st2;
        push(st1,root1);
        push(st2,root2);
        vector<int> ans;
        while(!st1.empty() and !st2.empty())
        {
            if(st1.top()->val<st2.top()->val)
            {
                ans.push_back(next(st1));
            }
            else
            {
                ans.push_back(next(st2));
            }
        }
        while(!st1.empty())
        {
            ans.push_back(next(st1));
        }
        while(!st2.empty())
        {
            ans.push_back(next(st2));
        }
        return ans;
    }
};