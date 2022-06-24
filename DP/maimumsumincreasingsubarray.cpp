// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> dp;
	    for(int i=0;i<n;i++)
	        dp.push_back(arr[i]);
	    int ans=INT_MIN;
	    for(int i=0;i<n;i++)
	    {
	        for(int prev=0;prev<i;prev++)
	        {
	            if(arr[prev]<arr[i])
	            {
	                dp[i]=max(dp[i],arr[i]+dp[prev]);
	            }
	        }
	        ans=max(ans,dp[i]);
	    }
	    return ans;
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends