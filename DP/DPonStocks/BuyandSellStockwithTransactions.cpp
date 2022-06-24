class Solution {
public:
    int find(vector<int> prices,int idx,bool buy,vector<vector<int>> &dp,int fee)
    {
        if(idx==prices.size())
            return 0;
        int profit=INT_MIN;
        if(dp[idx][buy]!=-1)
            return dp[idx][buy];
        if(buy)
        {
            int take=-prices[idx]+find(prices,idx+1,!buy,dp,fee);
            int nottake=find(prices,idx+1,buy,dp,fee);
            profit=max(take,nottake);
        }
        else
        {
            int take=prices[idx]-fee+find(prices,idx+1,!buy,dp,fee);
            int nottake=find(prices,idx+1,buy,dp,fee);
            profit=max(take,nottake);
        }
        
        return dp[idx][buy]=profit;
    }
    int maxProfit(vector<int>& Arr,int fee) 
    {
            //Write your code here
    int n=Arr.size();
    vector<vector<int>> dp(n+1,vector<int>(2,-1));
    
    //base condition
    dp[n][0] = dp[n][1] = 0;
    
    long profit;
    
    for(int ind= n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; buy++){
            if(buy==0){// We can buy the stock
                profit = max(0+dp[ind+1][0], -Arr[ind] + dp[ind+1][1]);
            }
    
            if(buy==1){// We can sell the stock
                profit = max(0+dp[ind+1][1], Arr[ind]-fee + dp[ind+1][0]);
            }
            
            dp[ind][buy]  = profit;
        }
    }
    return dp[0][0];
    }
};