class Solution {
public:
    int find(int n,vector<int> coins,int target,vector<vector<int>> &dp)
    {
        if(n==0)
        {
            if(target%coins[n]==0)
                return target/coins[n];
            return 1e9;
        }
        if(dp[n][target]!=-1)
            return dp[n][target];
        
        int nottake=0+find(n-1,coins,target,dp);
        int take=INT_MAX;
        if(target>=coins[n])
            take=1+find(n,coins,target-coins[n],dp);
        return dp[n][target]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,0));
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
                dp[0][i]=i/coins[0];
            else
                dp[0][i]=1e9;
        }
        
        for(int i=1;i<n;i++)
        {
            for(int cap=0;cap<=amount;cap++)
            {
                int nottake=0+dp[i-1][cap];
                int take=1e9;
                if(cap>=coins[i])
                    take=1+dp[i][cap-coins[i]];
                
                dp[i][cap]=min(nottake,take);
            }
        }
        int ans=dp[n-1][amount];
        if(ans>=1e9)
            return -1;
        return ans;
    }
};