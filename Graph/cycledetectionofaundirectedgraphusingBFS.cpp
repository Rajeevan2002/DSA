#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool check(int i,int par,vector<int> adj[],vector<bool> &visited)
    {
        queue<pair<int,int>>q;
        visited[i]=true;
        q.push({i,par});
        while(!q.empty())
        {
            int node=q.front().first;
            int par=q.front().second;
            q.pop();
            for(auto it:adj[node])
            {
                if(!visited[it])
                {
                    visited[it]=true;
                    q.push({it,node});
                }
                else if(it!=par)
                    return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,0);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(check(i,-1,adj,visited))
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends