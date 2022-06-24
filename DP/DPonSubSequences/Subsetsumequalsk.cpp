bool f(vector<int> arr,int sum,int n,vector<vector<int>> &dp)
    {
        if(sum==0)
        {
            return true;
        }
        if(n==0)
        {
            if(arr[n]==sum)
                return true;
            return false;
        }
        if(dp[n][sum]!=-1)
            return dp[n][sum];
        bool nottake=f(arr,sum,n-1,dp);
        bool take=false;
        if(sum>=arr[n]) 
            take=f(arr,sum-arr[n],n-1,dp);
        
        return dp[n][sum]=(take || nottake);
    }
    bool isSubsetSum(vector<int>arr, int sum)
    {
        // code here 
        vector<vector<int> > dp(arr.size(),vector<int> (sum+1,-1));
        return f(arr,sum,arr.size()-1,dp);
    }
}

// Recursion

bool isSubsetSum(vector<int>arr, int sum)
    {
        // code here 
        vector<vector<bool> > dp(arr.size(),vector<bool> (sum+1,0));
	if(arr[0]<=sum)
	        dp[0][arr[0]]=1;
        for(int i=0;i<arr.size();i++)
            dp[i][0]=1;
        
        for(int i=1;i<arr.size();i++)
        {
            for(int target=1;target<=sum;target++)
            {
                int take=dp[i-1][target];
                int nottake=false;
                if(target>=arr[i])
                    nottake=dp[i-1][target-arr[i]];
                
                dp[i][target]=take | nottake;
            }
        }
            
        return dp[arr.size()-1][sum];
    }
