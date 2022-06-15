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
        vector<int> indeg(V,0);
	    for(int i=0;i<V;i++)
	    {
	        for(auto itr:adj[i])
	            indeg[itr]+=1;
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++)
	        if(indeg[i]==0)
	            q.push(i);
	            
	    int count=0;
	    while(!q.empty())
	    {
	        auto i=q.front();
	        q.pop();
	        
	        count++;
	        for(auto itr:adj[i])
	        {
	            indeg[itr]-=1;
	            if(indeg[itr]==0)
	                q.push(itr);
	        }
	    }
	    if(count==V)
	        return false;
	    return true;
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