class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        
        if(sum%2!=0)
            return false;
        if(nums.size()==1)
            return false;
            int total=sum/2;
            int n=nums.size();
            vector<vector<bool>> dp(n,vector<bool>(total+1,0));
            for(int i=0;i<n;i++)
                dp[i][0]=1;
            if(nums[0]<=total)
                    dp[0][nums[0]]=1;
            
            for(int i=1;i<n;i++)
            {
                for(int cap=1;cap<=total;cap++)
                {
                    bool nottake=dp[i-1][cap];
                    bool take=false;
                    if(cap>=nums[i])
                        take=dp[i-1][cap-nums[i]];
                    
                     dp[i][cap]= nottake | take;
                }
            }
            
            return dp[n-1][total];
        
        
    }
};