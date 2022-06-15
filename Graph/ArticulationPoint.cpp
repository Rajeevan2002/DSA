// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(vector<int> adj[],int node,int parent,vector<int> &tin,vector<int> &low,vector<bool> &visited,vector<bool> &isa,int timer)
    {
        visited[node]=true;
        tin[node]=timer;
        low[node]=timer;
        timer+=1;
        int child=0;
        for(auto itr:adj[node])
        {
            if(!visited[itr])
            {
                dfs(adj,itr,node,tin,low,visited,isa,timer);
                low[node]=min(low[itr],low[node]);
                if(low[itr]>=tin[node] && parent!=-1)
                    isa[node]=true;
                child++;
            }
            else
                low[node]=min(low[node],tin[itr]);
        }
        
        if(parent==-1 && child>1)
            isa[node]=true;
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> tin(V,-1);
        vector<int> low(V,-1);
        vector<bool> visited(V,false);
        vector<bool> isArticulation(V,false);
        
        int timer=0;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                dfs(adj,i,-1,tin,low,visited,isArticulation,timer);
            }
        }
        
        vector<int> ans;
        for(int i=0;i<isArticulation.size();i++)
            if(isArticulation[i])
                ans.push_back(i);
        if(ans.size()==0)
        {
            ans.push_back(-1);
        }
            
        return ans;
    }
};

// { Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends