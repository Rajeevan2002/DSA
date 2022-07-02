class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        unordered_set<int> mp(nums1.begin(),nums1.end());
        
        for(int x:nums2)
        {
            if(mp.count(x))
            {
                ans.push_back(x);
                mp.erase(x);
            }
                
        }
        
        return ans;
        
    }
};