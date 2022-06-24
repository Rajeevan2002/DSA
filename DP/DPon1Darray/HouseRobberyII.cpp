int find(vector<int> &dp,vector<int> nums,int i,int n)
    {
        if(i>=n)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        int pick=nums[i]+find(dp,nums,i+2,n);
        int notpick=find(dp,nums,i+1,n);
        
        return dp[i]=max(pick,notpick);
        
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        vector<int> dp1(nums.size(),-1);
        vector<int> dp2(nums.size(),-1);
        int f1=find(dp1,nums,0,nums.size()-1);
        int f2=find(dp2,nums,1,nums.size());
        return max(f1,f2);
    }

//Tabulation
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        int dp[n+1], dp1[n+1];
        dp[0] = 0 ; 
        dp[1] = nums[0];
        dp1[0] = 0;
        dp1[1] = 0;
        for(int i = 2 ; i <=n ; i++){
            if(i == n) 
                dp[i] = dp[i-1];
            else 
                dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
            dp1[i] = max(dp1[i-1], dp1[i-2]+nums[i-1]);
        }  
        return max(dp[n], dp1[n]);
        
    }
};