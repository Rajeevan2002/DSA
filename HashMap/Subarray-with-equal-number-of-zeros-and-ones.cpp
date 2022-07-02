// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    typedef long long ll;
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        ll ans=0;
        for(ll i=0;i<n;i++)
            if(arr[i]==0)
                arr[i]=-1;
        //After doing this this sum boils down to the question of identifying the number of subaarays with sum k=0
        ll curr=0;
        ll res=0;
        
        unordered_map<ll,ll> mp;
        mp[0]=1;
        for(ll i=0;i<n;i++)
        {
            curr+=arr[i];
            res+=mp[curr];
            mp[curr]++;
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
  // } Driver Code Ends