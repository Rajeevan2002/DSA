class Solution {
public:
    int find(vector<int> nums,int i,vector<int> &dp)
    {
        if(i==0)
            return nums[i];
        
        if(i<0)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        int pick=nums[i]+find(nums,i-2,dp);
        int notpick=find(nums,i-1,dp);
        
        return dp[i]=max(pick,notpick);
        
    }
    int rob(vector<int>& nums) {
        int n=nums.size()-1;
        vector<int> dp(1000,-1);
        return find(nums,n,dp);
    }
};


//Tabulation
class Solution {
public:
    int rob(vector<int>& nums)
    {
        vector<int> dp(nums.size(),0);
        dp[0]=nums[0];
        int neg=0;
        for(int i=1;i<nums.size();i++)
        {
            int take=nums[i];
            
            if(i-2>=0)
                take+=dp[i-2];
            
            int nottake=dp[i-1];
            dp[i]=max(take,nottake);
        }
        
        return dp[nums.size()-1];
        
    }
};