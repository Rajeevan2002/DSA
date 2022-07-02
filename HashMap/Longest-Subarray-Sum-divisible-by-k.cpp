// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    unordered_map<int,int> mp;
	    int ans=0;
	    int curr=0;
	    
	    vector<int> mod(n);
	    for(int i=0;i<n;i++)
	    {
	        curr+=arr[i];
	        mod[i]=(((curr%k)+k)%k);
	        
	        if(mod[i]==0)
	            ans=i+1;
	        else if(mp.find(mod[i])==mp.end())
	            mp[mod[i]]=i;
	        else
	            ans=max(ans,i-mp[mod[i]]);
	    }
	    
	    return ans;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends