int f(int ind,int target,int arr[],vector<vector<int>> &dp)
	{
	    
	    if(ind == 0){
            if(target==0 && arr[0]==0)
                return 2;
            if(target==0 || target == arr[0])
                return 1;
            return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = f(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = f(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]=(notTaken + taken);
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        return f(n-1,sum,arr,dp);
	}