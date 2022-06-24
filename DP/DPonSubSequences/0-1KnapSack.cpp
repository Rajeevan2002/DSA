class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int function(int w,int wt[],int val[],int n,vector<vector<int>> &dp)
    {
        if(n==0)
        {
            if(wt[n]<=w)
                return val[n];
            else
                return 0;
        }
        // 
        if(dp[n][w]!=-1)
            return dp[n][w];
        int nottake=0+function(w,wt,val,n-1,dp);
        int take=INT_MIN;
        if(wt[n]<=w)
            take=val[n]+function(w-wt[n],wt,val,n-1,dp);
        
        return dp[n][w]=max(take,nottake);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       int w=W;
       vector<vector<int>> dp(n,vector<int> (w+1,-1)); 
       return function(w,wt,val,n-1,dp);
    }
};


// Tabulation
vector<vector<int>> dp(n,vector<int> (W+1,0)); 
        for(int w=wt[0];w<=W;w++)
            dp[0][w]=val[0];
            
        for(int i=1;i<n;i++)
        {
            for(int w=0;w<=W;w++)
            {
                int nottake=0+dp[i-1][w];
                int take=INT_MIN;
                if(wt[i]<=w)
                    take=val[i]+dp[i-1][w-wt[i]];
                dp[i][w]=max(nottake,take);
            }
        }
        
        return dp[n-1][W];