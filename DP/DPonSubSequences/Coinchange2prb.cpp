class Solution {
public:
    int find(int i,vector<int> coins,int target,vector<vector<int>> &dp)
    {
        if(i==0)
        {
            return (target%coins[i]==0);
        }
        
        if(dp[i][target]!=-1)
            return dp[i][target];
        int nottake=find(i-1,coins,target,dp);
        int take=0;
        if(target>=coins[i])
            take=find(i,coins,target-coins[i],dp);
        
        return dp[i][target]=take+nottake;
    }
    int change(int amount, vector<int>& coins) 
    {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,0));
        for(int i=0;i<=amount;i++)
            if(i%coins[0]==0)
                dp[0][i]=1;
        
        for(int i=1;i<n;i++)
        {
            for(int cap=0;cap<=amount;cap++)
            {
                int nottake=dp[i-1][cap];
                int take=0;
                if(cap>=coins[i])
                    take=dp[i][cap-coins[i]];
                
                dp[i][cap]=take+nottake;
            }
        }
        
        return dp[n-1][amount];
    }
};