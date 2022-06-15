// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool check(vector<int> adj[],int i,vector<int> &vis,vector<int> &dfs)
    {
        vis[i]=1;
        dfs[i]=1;
        for(auto itr:adj[i])
        {
            if(!vis[itr])
            {
                if(check(adj,itr,vis,dfs))
                    return true;
            }
            else if(dfs[itr])
                return true;
        }
        dfs[i]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) 
    {
        // code here
        vector<int> vis(V,0);
        vector<int> dfs(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(check(adj,i,vis,dfs))
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends