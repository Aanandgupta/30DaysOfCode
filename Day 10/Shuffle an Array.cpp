class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& nums) {
        this->nums=nums;
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        vector<int> perm(nums);
        for(int i=0;i<nums.size();i++)
        {
            int pos=rand()%(nums.size());
            swap(perm[pos],perm[i]);
        } 
        return perm;  
    }

};
