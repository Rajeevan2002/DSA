// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    typedef long long ll;
    long long minCost(long long arr[], long long n) 
    {
        // Your code here
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        if(n==1)
            return 0;
        ll ans=0;
        for(ll i=0;i<n;i++)
        {
            pq.push(arr[i]);
        }
        
        while(!pq.empty())
        {
            ll curr=0;
            if(!pq.empty())
            {
                curr+=pq.top();
                pq.pop();
            }
            if(!pq.empty())
            {
                curr+=pq.top();
                pq.pop();
            }
            ans+=curr;
            if(!pq.empty())
                pq.push(curr);
        }
        
        return ans;
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends