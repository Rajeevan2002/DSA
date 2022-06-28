class Solution {
public:
    void find(int index,int n,set<vector<int> > &ans,vector<int> nums)
    {
        if(index==nums.size())
        {
            ans.insert(nums);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            if(i!=index && nums[i]==nums[i-1])
                continue;
            swap(nums[i],nums[index]);
            find(index+1,n,ans,nums);
            swap(nums[i],nums[index]);
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> ans;
        set<vector<int>> res;
        find(0,nums.size(),res,nums);
        vector<vector<int>> a(res.begin(),res.end());
        return a;
    }
};