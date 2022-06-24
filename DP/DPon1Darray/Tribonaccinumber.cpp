class Solution {
public:
    int tri(int n,vector<int> &dp)
    {
        if(dp[n]!=-1)
            return dp[n];
        return dp[n]=tri(n-1,dp)+tri(n-2,dp)+tri(n-3,dp);
    }
    int tribonacci(int n) 
    {
        vector<int> dp(38,-1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        
        
        
        return tri(n,dp);
    }
    
};