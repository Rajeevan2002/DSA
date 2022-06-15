// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void tps(int i,vector<int> adj[],vector<bool> &visited,stack<int> &s)
	{
	    visited[i]=true;
	    for(auto itr:adj[i])
	    {
	        if(!visited[itr])
	        {
	            tps(itr,adj,visited,s);
	        }
	    }
	    s.push(i);
	}
	
	void dfs(int i,vector<int> adj[],vector<bool> &visited)
	{
	    visited[i]=true;
	    for(auto itr:adj[i])
	    {
	        if(!visited[itr])
	        {
	            dfs(itr,adj,visited);
	        }
	    }
	}
    
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int> s;
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                tps(i,adj,visited,s);
            }
        }
        
        vector<int> transpose[V];
        for(int i=0;i<V;i++)
        {
            visited[i]=false;
            for(auto itr:adj[i])
            {
                transpose[itr].push_back(i);
            }
        }
        
        int count=0;
        while(!s.empty())
        {
            int i=s.top();
            s.pop();
            if(!visited[i])
            {
                dfs(i,transpose,visited);
                count+=1;
            }
        }
        return count;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends