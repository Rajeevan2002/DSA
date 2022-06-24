class Solution {
public:
    int countPartitions(vector<int> nums,int target)
    {
        vector<vector<int>> dp(nums.size(),vector<int> (target+1,0));
        if(nums[0]==0)
            dp[0][0]=2;
        else 
            dp[0][0]=1;
        
        if(nums[0]!=0 && nums[0]<=target)
            dp[0][nums[0]]=1;
        
        for(int i=1;i<nums.size();i++)
        {
            for(int capacity=0;capacity<=target;capacity++)
            {
                int notake=dp[i-1][capacity];
                int take=0;
                if(capacity>=nums[i])
                    take=dp[i-1][capacity-nums[i]];
                
                dp[i][capacity]=take+notake;
            }
        }
        
        return dp[nums.size()-1][target];

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0;
        for(int i=0;i<nums.size();i++)
            total+=nums[i];
        
        int tofind=(total-target)/2;
        if(total-target<0 || (total-target)%2)
            return 0;
        
        return countPartitions(nums,tofind);
    }
};