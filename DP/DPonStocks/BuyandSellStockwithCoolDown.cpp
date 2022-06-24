class Solution {
public:
    int find(vector<int> prices,int buy,int n,vector<vector<int>> &dp)
    {
        if(n>=prices.size())
            return 0;
        
        int profit;
        if(dp[n][buy]!=-1)
            return dp[n][buy];
        if(buy)
        {
            int take=-prices[n]+find(prices,0,n+1,dp);
            int nottake=find(prices,1,n+1,dp);
            profit=max(take,nottake);
        }
        else
        {
            int take=prices[n]+find(prices,1,n+2,dp);
            int nottake=0+find(prices,0,n+1,dp);
            profit=max(take,nottake);
        }
        
        return dp[n][buy]=profit;
    }
    int maxProfit(vector<int>& Arr) {
        int n=Arr.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
    
    for(int ind = n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; buy++){
            int profit;
            
            if(buy==0){// We can buy the stock
                profit = max(0+dp[ind+1][0], -Arr[ind] + dp[ind+1][1]);
            }
    
            if(buy==1){// We can sell the stock
                profit = max(0+dp[ind+1][1], Arr[ind] + dp[ind+2][0]);
            }
            
            dp[ind][buy] = profit;
        }
    }
    
    return dp[0][0];
    }
};