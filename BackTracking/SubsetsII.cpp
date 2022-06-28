class Solution {
public:
    void find(vector<int> &res,vector<vector<int>> &ans,int idx,vector<int> nums)
    {
        ans.push_back(res);
        for(int i=idx;i<nums.size();i++)
        {
            if(i!=idx && nums[i]==nums[i-1])
                continue;
            res.push_back(nums[i]);
            find(res,ans,i+1,nums);
            res.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> res;
        find(res,ans,0,nums);
        return ans;
        
    }
};