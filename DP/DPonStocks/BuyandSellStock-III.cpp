class Solution {
public:
    int find(vector<int> prices,int idx,int cap,bool buy,vector<vector<vector<int>>> &dp)
    {
        if(idx==prices.size())
            return 0;
        if(cap==0)
            return 0;
        if(dp[idx][buy][cap]!=-1)
            return dp[idx][buy][cap];
        int profit=INT_MIN;
        if(buy)
        {
            int take=-prices[idx]+find(prices,idx+1,cap,!buy,dp);
            int nottake=0+find(prices,idx+1,cap,buy,dp);
            profit=max(take,nottake);
        }
        else
        {
            int take=prices[idx]+find(prices,idx+1,cap-1,!buy,dp);
            int nottake=0+find(prices,idx+1,cap,buy,dp);
            profit=max(take,nottake);
        }
        
        return dp[idx][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) 
    {
        bool buyi=true;
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,
                                    vector<vector<int>> 
                                            (2,vector<int>(3,0)));
        
        for(int i=0;i<n;i++)
        {
            for(int buy=0;buy<2;buy++)
            {
                dp[i][buy][0]=0;
            }
        }
        
        
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<3;j++)
            {
                dp[n][i][j]=0;
            }
        }
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                for(int cap=1;cap<3;cap++)
                {
                    int profit;
                    if(j==1)
                    {
                        int take=-prices[i]+dp[i+1][0][cap];
                        int nottake=0+dp[i+1][1][cap];
                        profit=max(take,nottake);
                    }
                    else
                    {
                        int take=prices[i]+dp[i+1][1][cap-1];
                        int nottake=0+dp[i+1][0][cap];
                        profit=max(take,nottake);
                    }
                    dp[i][j][cap]=profit;
                }
                
            }
        }
        
        return dp[0][1][2];
    }
};