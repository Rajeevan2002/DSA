// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int total=0;
	    for(int i=0;i<n;i++)
	        total+=arr[i];
	    vector<vector<bool>> dp(n,vector<bool> (total+1,0));
	    for(int i=0;i<n;i++)
	        dp[i][0]=true;
	   
	    if(arr[0]<=total)
	        dp[0][total]=true;
        
        for(int i=1;i<n;i++)
        {
            for(int capacity=1;capacity<=total;capacity++)
            {
                int nottake=dp[i-1][capacity];
                int take=0;
                if(capacity>=arr[i])
                    take=dp[i-1][capacity-arr[i]];
                    
                dp[i][capacity]= nottake || take;
            }
        }
        
        int mini=INT_MAX;
        for(int i=0;i<=total;i++)
        {
            if(dp[n-1][i]==true)
            {
                int s1=i;
                int s2=total-i;
                mini=min(mini,abs(s2-s1));
            }
        }
        
        return mini;
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
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends