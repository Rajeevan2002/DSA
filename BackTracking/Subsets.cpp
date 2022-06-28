class Solution {
public:
    void f(vector<int> nums,vector<vector<int>> &res,int idx,int n,vector<int> &ans)
    {
        if(idx==n)
        {
            res.push_back(ans);
            return;
        }
        ans.push_back(nums[idx]);
        f(nums,res,idx+1,n,ans);
        ans.pop_back();
        f(nums,res,idx+1,n,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> ans;
        int n=nums.size();
        f(nums,res,0,n,ans);
        return res;
        
    }
};