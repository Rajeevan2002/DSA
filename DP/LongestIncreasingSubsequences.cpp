class Solution {
public:
    int f(vector<int> nums,int idx,int prev,vector<vector<int>> &dp)
    {
        if(idx==nums.size())
            return 0;
        if(dp[idx][prev+1]!=-1)
            return dp[idx][prev+1];
        int len;
        int nottake=0+f(nums,idx+1,prev,dp);
        int take=-1;
        if(prev==-1 || nums[idx]>nums[prev])
        {
            take=1+f(nums,idx+1,idx,dp);
        }
        len=max(take,nottake);
        return dp[idx][prev+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<vector<int>> dp(nums.size()+1,vector<int> (nums.size()+1,0));
        int n=nums.size();
        for(int i=n-1;i>=0;i--)
        {
            for(int prev=i-1;prev>=-1;prev--)
            {
                int len;
                int nottake=0+dp[i+1][prev+1];
                int take=0;
                if(prev==-1 || nums[i]>nums[prev])
                {
                    take=1+dp[i+1][i+1];
                }
                len=max(take,nottake);
                dp[i][prev+1]=len;   
            }
        }
        return dp[0][0];
    }
};